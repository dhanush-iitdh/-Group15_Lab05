#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"

void GPIOF_Handler(void);
void GPIO_PORTF_Init(void);
void init(void)
{
   SYSCTL_RCGCGPIO_R |= 0x20;               /* Turn on the clock for Port F */
    GPIO_PORTF_LOCK_R = 0x4C4F434B;          /* Unlock Port F to make changes */
    GPIO_PORTF_CR_R |= 0x10;                 /* Allow modifications to PF4 (SW1) */
    GPIO_PORTF_DIR_R = 0x02;                 /* PF1 output, PF4 input */
    GPIO_PORTF_DEN_R = 0x12;                 /* Enable PF1 and PF4 */
    GPIO_PORTF_PUR_R = 0x10;                 /* Enable pull-up resistor for PF4 (SW1) */



    
}


int main() {
       init();                                  /* Initialize GPIO for Port F */
       GPIO_PORTF_DATA_R = 0x00;                /* Ensure that the LED is off initially */

       while (1) {
           /* Infinite loop: waiting for interrupts to occur */
       }
   }

void GPIOF_Handler(void)                  /* Interrupt handler for GPIO Port F */
{
    GPIO_PORTF_ICR_R |= 0x10;             /* Clear interrupt flag for PF4 */
    GPIO_PORTF_DATA_R ^= 0x02;            /* Toggle the RED LED (PF1) */
}
