#include <stdint.h>
typedef struct GPIO_Type{
  uint8_t ODR;
  uint8_t IDR;
  uint8_t DDR;
  uint8_t CR1;
  uint8_t CR2;  
}GPIO_Type;

#define GPIOC ((GPIO_Type *) 0x500A)
#define GPIOE ((GPIO_Type *) 0x5014)

void config_BUTTON(void);
