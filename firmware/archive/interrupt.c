/* Connor Larmer
 * 2023-08-21
 * ATMEGA328P Baremetal test program
 * Sorry, Am I Interrupting something?
 */

#include "common.h"

/* Registers */
#define PCICR 	*((volatile unsigned char *) 0x68)
#define SREG 	*((volatile unsigned char *) 0x3f)
#define PCMSK1 	*((volatile unsigned char *) 0x6c)

/* Hey ASM! */
#define _SEI() asm volatile("sei" ::: "memory")
#define _CLI() asm volatile("cli" ::: "memory")

#define INT_C	1 	// Bit to enable PC interrupts on port C
#define PC0 	0  	// Button pin

#define IFLAG 7 	// Global Interrupt flag
#define TFLAG 6
#define HFLAG 5
#define SFLAG 4
#define VFLAG 3
#define NFLAG 2
#define ZFLAG 1
#define CFLAG 0

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
#define _IVNX(v) __vector_ ## v
#define INTVEC(v) int _IVNX(v) ()
/*********************************/


char button = 0;

// Create Interrupt for pin change on port C
INTVEC(PCINT1_VEC)
{
	volatile char old_sREG;
	old_sREG = SREG;
	_CLI();
	// PUT CODE HERE
	SREG = old_sREG;
}


int main()
{
	_CLI();
	_WREG( PCICR, 	_BIT(INT_C) );	// Enable PCINT port C
	_WREG( PCMSK1, 	_BIT(PC0) 	);	// Enable PCINT on PC0 
	_WREG( SREG, 	_BIT(IFLAG)	); 	// Enable global interrupts
	_SEI(); 						// Enable interrupts
	return 0;
}
