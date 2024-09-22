#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"

void GPIOF_Handler(void);
void GPIO_PORTF_Init(void);

int main(void)
{
    GPIO_PORTF_Init();  /* Initialize GPIO Port F */
    
    while(1)
    {

    }ij
}


void GPIOF_Handler(void)
{
    GPIO_PORTF_ICR_R |= 0x10;             /* Clear interrupt flag for PF4 */
    GPIO_PORTF_DATA_R ^= 0x02;            /* Toggle the RED LED (PF1) */
}
