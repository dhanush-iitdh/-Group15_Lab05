#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"

void GPIOF_Handler(void);
void GPIO_PORTF_Init(void);
// Initialize Port F for Switch and LED
void init(void)
{
   SYSCTL_RCGCGPIO_R |= 0x20;               /* Turn on the clock for Port F */
    GPIO_PORTF_LOCK_R = 0x4C4F434B;          /* Unlock Port F to make changes */
    GPIO_PORTF_CR_R |= 0x10;                 /* Allow modifications to PF4 (SW1) */
/* Configure PF1 as output (Red LED), PF4 as input (SW1) */
    GPIO_PORTF_DIR_R = 0x02;                 /* PF1 output, PF4 input */
    GPIO_PORTF_DEN_R = 0x12;                 /* Enable PF1 and PF4 */
    GPIO_PORTF_PUR_R = 0x10;                 /* Enable pull-up resistor for PF4 (SW1) */
/* Configure interrupt for PF4 (SW1) */
   GPIO_PORTF_IS_R &= ~0x10;                /* Configure for edge detection */
    GPIO_PORTF_IBE_R &= ~0x10;               /* Disable detection on both edges */
    GPIO_PORTF_IEV_R &= ~0x10;               /* Trigger on falling edge (button press) */
    GPIO_PORTF_ICR_R |= 0x10;                /* Clear any prior interrupt */
    GPIO_PORTF_IM_R |= 0x10;                 /* Enable interrupt for PF4 */

    NVIC_EN0_R |= 0x40000000;                /* Enable the Port F interrupt in the NVIC (Interrupt 30) */  
}
int main() {
    init();                                  /* Initialize GPIO for Port F */
    GPIO_PORTF_DATA_R = 0x00;                /* Ensure that the LED is off initially */
    while (1) 
    {
    /* Infinite loop: waiting for interrupts to occur */
    }
}

/* Interrupt handler for GPIO Port F */
void GPIOF_Handler(void) {
    if (GPIO_PORTF_RIS_R & 0x10) {           /* Check if the interrupt was caused by PF4 (SW1) */
        GPIO_PORTF_DATA_R ^= 0x02;           /* Toggle the state of the Red LED (PF1) */
        GPIO_PORTF_ICR_R |= 0x10;            /* Clear the interrupt flag for PF4 */
    }
}
