/* Connor Larmer
 * 2023-08-21
 * ATMEGA328P Baremetal test program
 * Ooh yea
 */

#include "common.h"

#define PC1 1


int main()
{
	_WREG(DDRC,_BIT(PC1));
	while(1)
	{
	_WREG(PORTC,_BIT(PC1));
	ms_delay(1000);
	_CREG(PORTC,_BIT(PC1));
	ms_delay(1000);
	}
}
