#include "GPIO.h"

void config_BUTTON(void)
{
  GPIOC->ODR |= 0x02;
  GPIOC->DDR &= ~0x02;
  GPIOC->CR1 |= 0x02;
  GPIOC->CR2 |= 0x02;    
}

