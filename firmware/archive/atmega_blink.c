/* Connor Larmer
 * 2023-08-19
 * ATMEGA328P Baremetal blink program
 * Its a high-level language, baby!
 */
 
#define PORTC 	*((volatile unsigned char *) 0x28)
#define DDRC	*((volatile unsigned char *) 0x27)

#define _NOP() asm volatile ("nop")

#define PC1 0b00000010;

int main()
{
	// Set PC1 as OUTPUT
	DDRC |= PC1;

	// Hang out in a loop
	while(1)
	{

		for(long i = 0; i < (200000); i ++)
			PORTC |= PC1; // Flip PC1 register to HIGH


		for(long i = 0; i < (200000); i ++)
			PORTC &= ~PC1; // Flip PC1 regsiter to LOW

	}
}
