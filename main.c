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
    }
}
