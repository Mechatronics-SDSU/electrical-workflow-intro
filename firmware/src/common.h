/* Connor Larmer
 * 2023-08-21
 * Wheel? Re-inventing? What are you talking about??
 */

/* SREG flags */
#define IFLAG 7 	// Global Interrupt flag
#define TFLAG 6
#define HFLAG 5
#define SFLAG 4
#define VFLAG 3
#define NFLAG 2
#define ZFLAG 1
#define CFLAG 0
/* Other implementation macros (for pins) */
#define PCIE1 	1	// Enable PCINT on PORTC
#define PC0 	0 	// PCO mask
#define PC1 	1 	// PC1 mask
#define PD6 	6 	// PC6 mask
/* USART macros */
// #define BAUD_9600 	51
// #define BAUD_4800 	103
#define BAUD_115200 8
#define TXEN0 	3
#define RXEN0 	4
#define UDRE0 	5
#define RXC0 	7
/* GPIO registers */
#define PORTD 	*((volatile unsigned char *) 0x2B)
#define DDRD	*((volatile unsigned char *) 0x2A)
#define PIND	*((volatile unsigned char *) 0x29)
#define PORTC 	*((volatile unsigned char *) 0x28)
#define DDRC	*((volatile unsigned char *) 0x27)
#define PINC	*((volatile unsigned char *) 0x26)
#define PORTB 	*((volatile unsigned char *) 0x25)
#define DDRB	*((volatile unsigned char *) 0x24)
#define PINB	*((volatile unsigned char *) 0x23)
/* Timer registers */
#define TCCR1A  *((volatile unsigned char *) 0x80)
#define TCCR1B  *((volatile unsigned char *) 0x81)
#define TIMSK1  *((volatile unsigned char *) 0x6F)
#define OCR1AL  *((volatile unsigned char *) 0x88)
#define TCNT0	*((volatile unsigned char *) 0x46)
#define TCCR0B	*((volatile unsigned char *) 0x45)
#define TCCR0A	*((volatile unsigned char *) 0x44)
#define TIFR0	*((volatile unsigned char *) 0x35)
#define OCR0A 	*((volatile unsigned char *) 0x47)
/* Interrupt Registers */
#define PCICR 	*((volatile unsigned char *) 0x68)
#define SREG 	*((volatile unsigned char *) 0x3f)
#define PCMSK1 	*((volatile unsigned char *) 0x6c)
/* USART Registers */
#define UDR0 	*((volatile unsigned char *) 0xc6)
#define UCSR0A 	*((volatile unsigned char *) 0xc0)
#define UCSR0B 	*((volatile unsigned char *) 0xc1)
#define UCSR0C 	*((volatile unsigned char *) 0xc2)
#define UBRR0L 	*((volatile unsigned char *) 0xc4)
#define UBRR0H 	*((volatile unsigned char *) 0xc5)
/* ~ High level Convenience ~ */
#define CPU_FREQ 8000000
#define _BIT(b) (unsigned long)(1 << b) 	// Get a bitmask
#define _NOP() asm volatile("nop\n\t") 		// NOP out of this one
#define _WREG(port, bit) ((port) |= (bit)) 	// Write register bit
#define _CREG(port, bit) ((port) &= ~(bit))	// clear register bit
#define _SEI() asm volatile("sei" ::: "memory")
#define _CLI() asm volatile("cli" ::: "memory")
#define _RETI() asm volatile("reti" ::: "memory")
/*********************************/
/* INTERRUPT VECTOR ADDRESSES */
#define INT0_VEC			1
#define INT1_VEC			2
#define PCINT0_VEC			3
#define PCINT1_VEC			4
#define PCINT2_VEC			5
#define WDT_VEC				6
#define TIMER2COMPA_VEC		7
#define TIMER2COMPB_VEC		8
#define TIMER2OVF_VEC		9
#define TIMER1CAPT_VEC		10
#define TIMER1COMPA_VEC		11
#define TIMER1COMPB_VEC		12
#define TIMER1OVF_VEC		13
#define TIMER0COMPA_VEC		14
#define TIMER0COMPB_VEC		15
#define TIMER0OVF_VEC		16
#define SPISTC_VEC			17
#define USARTRXC_VEC		18
#define USARTUDRE_VEC		19
#define USARTTXC_VEC		20
#define ADCC_VEC			21
#define EEREADY_VEC			22
#define ANALOGCOMP_VEC		23
#define TWI_VEC				24
#define SPMREADY_VEC		25
/* ~Compiler Bullshi- Magic~ */
#define _IVNX(v)  __vector_ ## v
#define INTVEC(v) __attribute__((interrupt)) void _IVNX(v) ()


// You were promised puppies.
/*
                 "woof"
                  /
       ___^^:~, 
    ~~(_____)
       \\  \\
*/
