/*			MSP430 Test Code   
\                 		 
/	Description: 	Using this code to TEST my MSP430G2231
\			and the git version control system
/	
\	Author: Kevin Henderson
/	Email: umhendek@gmail.com
\	Date: 12-28-12
*/

//	**** the TI way ****
// #import <msp430g2231.h> // must import specific device header
//
// pragma vector=PORT1_VECTOR
// __interrupt void PORT1_ISR(void) { .. } // interrupt routine setup
// 	**** end TI ****

//	**** the GCC way ... ****
#include <msp430.h>
#include <legacymsp430.h>

#define maxLEDFreq 2500 

// Function defs
void func(void);

int main(void) {
	volatile long int i;
	unsigned int max = maxLEDFreq;
	_Bool flag = 0;
	double voltage;

	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;
  
  	//BCSCTL1 = CALBC1_1MHZ;		// Set range
	//DCOCTL = CALDCO_1MHZ;		// SMCLK = DCO = 1MHz 
	
	P1SEL = 0x00; // ? pin setting select
	P1REN = 0x00; // ? pin resistor enable (PU or PD)

	P1DIR = 0x41;
	P1OUT = 0x40;
	
	P1IE = 0x00;	// interrupt enable
	P1IES = 0x00; 	// transition slope
	//P1IFG 	// interrupt flag
  
	/* enable global interrupts * 
	gie();
	WRITE_SR(GIE);
	BIS_SR(GIE); */
	eint();
		
	//	~Timer A~
	//TACCR1 	// Capture/compare register
	//TACCR0 	// Capture/compare register 
	//TAR 		// Timer_A register 
	//TACCTL1 	// Capture/compare control 
	//TACCTL0 	// Capture/compare control 
	//TACTL 	// Timer_A control 
	//TAIV 		// Timer_A interrupt vector 
	
	//	~ADC~
	
	ADC10CTL0 = ADC10SHT_3 + ADC10ON; 		// sample and hold time  max
	ADC10CTL1 = ADC10DIV0 + ADC10DIV1 + ADC10DIV2 + //
		INCH0 + INCH1+ INCH2+ INCH3; 		//
	ADC10AE0 |= 0x08; // ? analog enable bit 
	
	// loop forever
	for (;;) 
	{
		P1OUT ^= 0x41;
		
		voltage= ADC10MEM; // reads value

		//wait
		for (i = 0; i < max; i++); 
		{
		    
		}
	    
		if (max == maxLEDFreq)
			flag =0;
		else if (max == 0)
			flag =1;
	  	
		if (flag==1)
			max = max+5;
		else
			max = max -5;
	}
	
	// never gets here
	
}

interrupt (PORT1_VECTOR) PORT1_ISR(void) 
{

}

void func(void) {

}




