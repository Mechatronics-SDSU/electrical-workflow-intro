/* Connor Larmer
 * 2023-08-30
 * Electrical Intro Code!
 *
 * Check common.h for macro definitions,
 * interrupt madness, and puppies.
 * 
 * Notes about hw n stuff:
 * 		- timer0 is used to generate PWM
 *		- timer1 is used to poll/debounce button
 *		  and smooth the LED's brightness changes
 * 		- The mcu's usart module is used to communicate
 * 		  to a PC via a usb-to-ttl serial converter
 *		- The internal 8MHz osc. is used because I don't
 *		  have a better one.
 */

#include "common.h"

volatile unsigned char LED_ON = 0;				// LED Toggle State
volatile unsigned char PREV_LED_ON = 0;			// Previous LED Toggle State
volatile unsigned char MODE = 0; 				// Brightness Mode
volatile unsigned char PREV_MODE = 0;			// Previous Brightness Mode
volatile unsigned char DC_SETPOINT = 0; 		// Duty Cycle Setpoint
volatile unsigned char DC_CURRENT = 0; 			// Current Duty Cycle Value
volatile unsigned char DC_PREV_SP = 0; 			// Previous Duty Cycle Setpoint

unsigned char BRIGHT[6] = { 255, 204, 153, 102, 51, 0};
char* PERC[6] = { "0%", "20%", "40%", "60%", "80%", "100%"};

/* In order to debounce the button input,
   an interrupt is triggered every FCPU/256
   cycles. This interrupt polls the button state,
   and then accumulates it in the _btn_acc byte.
   8 consecutive samples of 0 (button pressed)
   will trigger LED_ON to be flipped. Not a
   pretty solution, but it effectively debounces
   the button. */
volatile unsigned short _btn_acc = 0xFFFF;
INTVEC(TIMER1COMPA_VEC)
{
	volatile char oSREG;
	oSREG = SREG;

	// Linear transition from DC_CURRENT to DC_SETPOINT
	if((DC_SETPOINT - DC_CURRENT) < 0)		DC_CURRENT -= 1;
	else if((DC_SETPOINT - DC_CURRENT) > 0)	DC_CURRENT += 1;

	_btn_acc = (_btn_acc << 1) | (PINC & _BIT(PC0) );
	if(_btn_acc == 0) 	// Button press triggered
	{
		PREV_LED_ON = LED_ON;
		_btn_acc = 0xFFFF;
		if(LED_ON)
			LED_ON = 0;
		else
			LED_ON = 1;
	}
	SREG = oSREG;	
}

void timer1_init()
{
	TCCR1A	= 0x00;
	TCCR1B	= 0b00001101;
	TIMSK1	= 0b00000010;
	OCR1AL	= 64;
}

void uart_init()
{
	// 9600 Baud 
	UBRR0H = BAUD_115200>>8;
	UBRR0L = BAUD_115200;
	// 8N1 Frame rate
	UCSR0C = 0x06;
	// Enable Trans/Recv
	UCSR0B = _BIT(RXEN0) | _BIT(TXEN0);	
	UCSR0A = _BIT(1);
}

char usart_recv_noblock()
{
	if( (UCSR0A & _BIT(RXC0)) == 0 )
		return '\0';
	return UDR0;
}

void pwm_init()
{
	OCR0A = DC_CURRENT;
	/* These values were determined from sect. 14
	of the atmega328 datasheet. Basically, timer0
	is configured to be a non-inverting fast PWM
	source with a variable duty cycle. The clock
	prescaler is not in use. (Using timer0 would
	normally conflict with Arduino's own millis
	function, but notice how we're not in Arduino
	land anymore?)*/
	TCCR0A = 0b11000011;
	TCCR0B = 0b00000001;
}

void usart_send_str(char* str)
{
	volatile int i = 0;
	while(str[i] != '\0')
	{
		while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = str[i++];
	}
}

int main()
{
	_WREG(DDRD,_BIT(PD6)); 		// Set led to output
	_CREG(DDRC,_BIT(PC0));		// Set btn to input
	_WREG(PORTC,_BIT(PC0)); 	// Enable btn pullup

	timer1_init();
	uart_init();
	pwm_init();
	_SEI();	

	volatile char ibyte = '\0';

	while(1)
	{
		// Recv and process incoming byte
		ibyte = usart_recv_noblock();

		if(ibyte == '?')
		{
			usart_send_str("Current Brightness: ");
			usart_send_str(PERC[MODE]);
			usart_send_str("\r\n");
		}

		if(ibyte > 64 && ibyte < 71)
		{
			PREV_MODE = MODE;
			MODE = ibyte-65;
			DC_PREV_SP = DC_SETPOINT;
			DC_SETPOINT = BRIGHT[MODE];
		}

		// Notify console if button changed
		if( PREV_LED_ON != LED_ON )
		{
			if(LED_ON)	usart_send_str("LED Enabled.\r\n");
			else		usart_send_str("LED Disabled.\r\n");
			PREV_LED_ON = LED_ON;
		}
		
		// Notify console if brightness changed
		if(DC_SETPOINT != DC_PREV_SP)
		{
			usart_send_str("New Brightness: ");
			usart_send_str(PERC[MODE]);
			usart_send_str("\r\n");
		}

		// Update LED
		if(LED_ON)	OCR0A = DC_CURRENT;
		else		OCR0A = 255;

		DC_PREV_SP = DC_SETPOINT;
	}
	return 0;
}
