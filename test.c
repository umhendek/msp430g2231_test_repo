/*			MSP430 Test Code   
\                 		 
/	Description: 	Using this code to TEST my MSP430G2231
\			and the git version control system
/	
\	Author: Kevin Henderson
/	Email: umhendek@gmail.com
\	Date: 12-28-12
*/

/*	**** the TI way ****

#import <msp430g2231.h> // must import specific device header
pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR(void) { .. } // interrupt routine setup

 	**** end TI way **** */

//	**** the GCC way ****
#include <msp430.h> // device defined at compiletime
#include <legacymsp430.h>

// Function defs
void func(void);

int main(void) {

	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;
	
	P1SEL = 0x00; 	// ? pin setting select
	P1REN = 0x00; 	// ? pin resistor enable (PU or PD)

	P1DIR = 0x41; 	// direction selection
	P1OUT = 0x40; 	// output selection
	
	P1IE = 0x00;	// interrupt enable
	P1IES = 0x00; 	// transition slope
	//P1IFG 	// interrupt flag
  
	// enable global interrupts 
	eint();
		
	// loop forever
	for (;;) 
	{
		P1OUT ^= 0x41;
	}
	
}

// interrupt template
interrupt (PORT1_VECTOR) PORT1_ISR(void) 
{

}

// function template
void func(void) {

}

