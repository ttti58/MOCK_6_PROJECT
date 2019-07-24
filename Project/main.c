#include "GPIO.h"
#include "stm8l_define.h"
unsigned int a = 0;
unsigned int b = 0;
unsigned int a1 = 0;
unsigned int a2 = 0;
unsigned int b1 = 0;
unsigned int b2 = 0;

void main( void )
{
  config_BUTTON();
  config_CLK_HSI();
  config_CLK_LSE();
  config_LCD();
  config_UART();
  config_Int_Ex();
  config_interrupt_priority();
  asm("RIM\n"); //enable interrupt
  
  while(1);
}

#pragma vector = 11 // ngat button
__interrupt void BUTTON_interrupt(void)
{
  a++;
  //if(a>99)
    //a = 0;
  while(!(UART1->SR & 0x80));
    UART1->DR = 'b';
  EXTI->SR1 |= 0x02;
}

#pragma vector = 18 //ngat lcd
__interrupt void LCD_interrupt(void)
{
  if(a>99)
  {
    LCD_Clear();
    LCD_345_WIN();
    SBit(LCD_Control->LCD_CR3,3);
  }
  if(a<=99)
  {
  a1 = (a/10);
  a2 = (a%10);
  b1 = (b/10);
  b2 = (b%10);
  switch(a2)
  {
  case 0:
      LCD_30();
      break;
  case 1:
      LCD_31();
      break;
  case 2:
      LCD_32();
      break;
  case 3:
      LCD_33();
      break;
  case 4:
      LCD_34();
      break;
  case 5:
      LCD_35();
      break;
  case 6:
      LCD_36();
      break;
  case 7:
      LCD_37();
      break;
  case 8:
      LCD_38();
      break;
  case 9:
      LCD_39();
      break;
  }
    switch(a1)
  {
  case 0:
      LCD_20();
      break;
  case 1:
      LCD_21();
      break;
  case 2:
      LCD_22();
      break;
  case 3:
      LCD_23();
      break;
  case 4:
      LCD_24();
      break;
  case 5:
      LCD_25();
      break;
  case 6:
      LCD_26();
      break;
  case 7:
      LCD_27();
      break;
  case 8:
      LCD_28();
      break;
  case 9:
      LCD_29();
      break;
  }
      switch(b2)
  {
  case 0:
      LCD_50();
      break;
  case 1:
      LCD_51();
      break;
  case 2:
      LCD_52();
      break;
  case 3:
      LCD_53();
      break;
  case 4:
      LCD_54();
      break;
  case 5:
      LCD_55();
      break;
  case 6:
      LCD_56();
      break;
  case 7:
      LCD_57();
      break;
  case 8:
      LCD_58();
      break;
  case 9:
      LCD_59();
      break;
  }
      switch(b1)
  {
  case 0:
      LCD_60();
      break;
  case 1:
      LCD_61();
      break;
  case 2:
      LCD_62();
      break;
  case 3:
      LCD_63();
      break;
  case 4:
      LCD_64();
      break;
  case 5:
      LCD_65();
      break;
  case 6:
      LCD_66();
      break;
  case 7:
      LCD_67();
      break;
  case 8:
      LCD_68();
      break;
  case 9:
      LCD_69();
      break;
  }
  LCD_COLON();
  LCD_1A();
  LCD_4B();
  SBit(LCD_Control->LCD_CR3,3);
  }
}

/*
#pragma vector = 29 // Ngat Truyen
__interrupt void UART_Trans(void)
{
  
}
*/

#pragma vector = 30 // Ngat Nhan
__interrupt void UART_Receive(void)
{
    if((UART1->DR)=='a')
      b++;
}
