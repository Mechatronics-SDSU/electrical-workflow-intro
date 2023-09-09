#define LED_PIN 1                                    // PB1
#define BUTTON_PIN 2                                 // PD2
#define topVal 255 
#define rangeOduty 5 

volatile uint8_t lumen = 0;                           //global for duty cycle adj
volatile uint8_t pressCount = 0;                      //global for truth of state 
char pressed[]= ("Pressed b*tch \n");                 //it'n that fun

void usartSet();                                      //prototypes
void gpioSet();
void timer1Set();
void boostDown(char* input);
void fadeLed(uint8_t targetValue);
void uart_transmit (char data); 
void report();                                         //end prototypes

void setup()                                           //initializing launch
{
  
usartSet();      
gpioSet();                  
timer1Set();

}


void loop()                                             //do the stuff
{
  
  if (UCSR0A & (1<<RXC0))                               //if ready to read
  { 
    
    char inChar = UDR0;                                 //read character

    boostDown(&inChar);                                 //lower to upper if needed

    if (inChar >= 'A' && inChar <= 'F')                 //if valid option
    {
                                                        //if character is alphabet
      uint8_t delta =  (inChar - 'A');                  //where u r - where u been
      uint8_t sectional=topVal / rangeOduty;            //a 5th of 255
      uint8_t destLumen = delta*sectional;              //n sectionals

      fadeLed(destLumen);                               //send it to fade
    } 
    
    else if (inChar == '?')                             //select report case
    {
     report();            
    }
    
    else if (inChar == '\n'){}                      
    
    else{
    Serial.println("Not a valid option");               //I got lazy here not
                                                        //at this spec pnt tho
    }                                                
  }
}


void uart_transmit (char data) 
{
  while (!( UCSR0A & (1<<UDRE0)));                      //w8 while not empty b4 read;                               
  UDR0 = data;                                          //write the data in register
}


void usartSet()
{
  UBRR0H = 0;
  UBRR0L = 8;  
  
  UCSR0B = (1<<RXEN0) | 
           (1<<TXEN0);                                  //enable reciever transm
           
  UCSR0C = (1<<UCSZ01) |
           (1<<UCSZ00);                                 //for 8-bit char size
}


void gpioSet()
{
  DDRB |= (1 << LED_PIN);                               //PB1 D9 LED Pin
  DDRD &= ~(1 << BUTTON_PIN);                           //PD2 D2 Push button read
  PORTD |= (1 << BUTTON_PIN);                           //pull-up config
}


void timer1Set()
{                            
  TCCR1A |= (1 << COM1A1);                              //Com settings
  TCCR1A &= ~(1 << COM1A0);                             //non-inverting

  TCCR1A &= ~(1 << WGM10);                              //Fast PWM
  TCCR1A |= (1 << WGM11);           
  TCCR1B |= (1 << WGM13) |
            (1 << WGM12);
           
  TCCR1B |= (1<<CS10);                                  //no p.s. lolz

  PCICR  |= (1 << PCIE2);                               //enable interrupt
  PCMSK2 |= (1 << PCINT18);                             //Msk for PD2
 
  ICR1 = topVal;                                        //cuz I know Joe loves
  OCR1A = 0;                                            //duty cycle action
}


void boostDown(char* input)
{     
  if (*input >= 'a' && *input <= 'z')                   //if lower case, 
                                                        //then to upper
      { 
        *input -= (1<<5);                               //difference of 32
      }                                                 //ref to char addy
}


void fadeLed(uint8_t targetValue) 
{
  while (OCR1A != targetValue)                          //while not satisfied
  {
    if (OCR1A < targetValue)                            //if not enough
    {
      OCR1A++;                                          //drink more seed
    } 
    else 
    {
      OCR1A--;                                          //ralph some seed
    }

    delay(10);                                          //drink seed responsibly
  }
  
  lumen = OCR1A;                                        //Global store seed level
}                                                       //1st rule don't talk about
                                                        //seed club


void report()                                           //I'll just apologize now for this function
{                                                       //and would appreciate light judgment zzz
      char report [] = ("The brightness is "); 
      char precentile = (2*(lumen/(topVal/5)))+ '0';    //0-100% in 20 int
      if(precentile == ':')                             //ps i'm illiterate
      precentile = '1';
      char precSym = '%';
      int i = 0;

         while(report[i] != '\0')                       //tx till null
        {
           uart_transmit ( report[i]); 
           i++;
        }
        
      if (!(pressCount & 1))                             //if not even press is odd
      {
        uart_transmit ( precentile);
        if (precentile == '1')                          //idea is 1 is only 100 on char rep
          {
          uart_transmit ( '0');                         //cheap af
          }
        if (precentile > '0')                           
          {
          uart_transmit ( '0');                         //always 0 present
          }
      }   
        else
      uart_transmit ( '0');                             //def just 0... cuz zzz
      uart_transmit ( precSym);                         //cheap but my attn espenzive
      uart_transmit ( '\n');
  
}


ISR(PCINT2_vect) 
{
  int i = 0;
     
     cli();                                             //disable global interrupts
     delay(5000);                                       //w8 a dickens
  if (!(PIND & (1 << BUTTON_PIN)))                      //if butt pressed = 0
  {  
    if (pressCount & 1)                                 //if pressed odd
    {
      while(OCR1A != lumen)                             //Restore the brightness
      {
      OCR1A++;
      delay(500);                                       //do this at a controlled rate
      }
    } 
    
    else                                                //if pressed even.. good like
    {  
      while(OCR1A != 0)
      {
      OCR1A--;                                          //Turn off the LED, close door
      delay(500);
      }
    }
    
   while(pressed[i]!= '\0')                             //again why uart proto here vs funct?
   {                                                    //cause lazy idk mb mb
    uart_transmit (pressed[i]);
    i++; 
   }
     pressCount++;                                      //Increment the press count
     delay(5000);                                       //drink seed responsibly
  }
  delay(5000);                                          //be sure
  sei();                                                //enable global interrupts
}
