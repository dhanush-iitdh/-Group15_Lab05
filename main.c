#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
void GPIOF_Handler(void);
void GPIO_PORTF_Init(void);
void init(void)
{
   SYSCTL_RCGCGPIO_R |= 0x020;
              GPIO_PORTF_LOCK_R= 0x4C4F4348;
              GPIO_PORTF_CR_R |= 0x10;
              GPIO_PORTF_DIR_R = 0x02;
              GPIO_PORTF_DEN_R = 0x12;
              GPIO_PORTF_PUR_R = 0x10;



    
}


int main()
{
    SYSCTL_RCGCGPIO_R |= 0x020;
              GPIO_PORTF_LOCK_R= 0x4C4F4348;
              GPIO_PORTF_CR_R |= 0x10;
              GPIO_PORTF_DIR_R = 0x02;
              GPIO_PORTF_DEN_R = 0x12;
              GPIO_PORTF_PUR_R = 0x10;
    GPIO_PORTF_Init();  /* Initialize GPIO Port F */
    
    while(1)
    {

    }
}


void GPIOF_Handler(void)
{
    GPIO_PORTF_ICR_R |= 0x10;             /* Clear interrupt flag for PF4 */
    GPIO_PORTF_DATA_R ^= 0x02;            /* Toggle the RED LED (PF1) */
}
