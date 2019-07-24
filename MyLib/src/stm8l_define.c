#include "stm8l_define.h"

void config_Int_Ex(void)
{
  EXTI->CR1 |= 0x08;
  EXTI->CR1 &= ~0x04;
    // ngat khi kich canh xuong Button
}

void config_interrupt_priority(void)
{
    ITC_SPR5 |= 0x03; // set uu tien level 3 cho LCD
    ITC_SPR3 |= 0x08; // set uu tien 2 cho Button
    ITC_SPR7 |= 0x80; // set uu tien 2 cho ca Ngat Rx va Tx
    ITC_SPR8 |= 0x02;
}

void config_CLK_LSE()
{
  CLK->SWCR |= 0x02; // cho phep thay doi gia tri clk
  CLK->PCKENR2 |= 0x88; // clk cho LCD
  CLK->CRTCR |= 0x10; // :0 va chon clock LSE lam clock cho RTC
  // 32.768 kHz
  while((GetBit(CLK->ECKR,3))!=1); //0x50CF kiem tra LSE ready ?
}

void config_CLK_HSI()
{
  CLK->SWCR |= 0x02; // cho phep thay doi gia tri clock
  CLK->DIVR = 0X00; // :0
  CLK->SWR = 0X01; // set clock nguon la HSI
  SBit(CLK->PCKENR2,1); // enable CLK for Timer1
  SBit(CLK->PCKENR2,5); //enable CLK for UART1
  // 16MHz
  while((CLK->SCSR)!=0X01); //kiem tra HSI
  while(GetBit(CLK->ICKR,1)!=1); //kiem tra HSI ready?
}

void LCD_Clear()
{
  LCD_MEM->LCD_RAM6.Bit2 = 0; //1A
  LCD_MEM->LCD_RAM2.Bit6 = 0; //1B 
  LCD_MEM->LCD_RAM3.Bit5 = 0; //1C
  LCD_MEM->LCD_RAM3.Bit4 = 0; //1D
  LCD_MEM->LCD_RAM0.Bit0 = 0; //1E
  LCD_MEM->LCD_RAM6.Bit3 = 0; //1F
  LCD_MEM->LCD_RAM2.Bit7 = 0; //1G
  LCD_MEM->LCD_RAM0.Bit1 = 0; //1M
  
  LCD_MEM->LCD_RAM6.Bit0 = 0; //2A
  LCD_MEM->LCD_RAM2.Bit4 = 0; //2B
  LCD_MEM->LCD_RAM3.Bit7 = 0; //2C
  LCD_MEM->LCD_RAM2.Bit5 = 0; //2G
  LCD_MEM->LCD_RAM3.Bit6 = 0; //2D
  LCD_MEM->LCD_RAM0.Bit2 = 0; //2E
  LCD_MEM->LCD_RAM6.Bit1 = 0; //2F
  LCD_MEM->LCD_RAM0.Bit3 = 0; //2M
  
  LCD_MEM->LCD_RAM5.Bit6 = 0; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 0; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 0; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 0; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 0; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 0; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 0; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 0; //3M
  
  LCD_MEM->LCD_RAM5.Bit6 = 0; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 0; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 0; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 0; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 0; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 0; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 0; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 0; //3M
  
  LCD_MEM->LCD_RAM5.Bit4 = 0; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 0; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 0; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 0; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 0; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 0; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 0; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 0; //4M
  
  LCD_MEM->LCD_RAM5.Bit0 = 0; //6A
  LCD_MEM->LCD_RAM1.Bit4 = 0; //6B
  LCD_MEM->LCD_RAM4.Bit7 = 0; //6C
  LCD_MEM->LCD_RAM1.Bit5 = 0; //6G
  LCD_MEM->LCD_RAM4.Bit6 = 0; //6D
  LCD_MEM->LCD_RAM1.Bit2 = 0; //6E
  LCD_MEM->LCD_RAM5.Bit1 = 0; //6F
  LCD_MEM->LCD_RAM1.Bit3 = 0; //6M

  LCD_MEM->LCD_RAM5.Bit2 = 0; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 0; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 0; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 0; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 0; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 0; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 0; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 0; //5M
  
  LCD_MEM->LCD_RAM7.Bit7 = 0; // 4:
}

void LCD_1A()
{
  LCD_MEM->LCD_RAM6.Bit2 = 1; // 1A
  LCD_MEM->LCD_RAM2.Bit6 = 1; //1B 
  LCD_MEM->LCD_RAM3.Bit5 = 1; //1C
  LCD_MEM->LCD_RAM3.Bit4 = 0; //1D
  LCD_MEM->LCD_RAM0.Bit0 = 1; //1E
  LCD_MEM->LCD_RAM6.Bit3 = 1; // 1F
  LCD_MEM->LCD_RAM2.Bit7 = 1; // 1G
  LCD_MEM->LCD_RAM0.Bit1 = 1; // 1M
}

void LCD_10()
{
  LCD_MEM->LCD_RAM6.Bit2 = 1; //A
  LCD_MEM->LCD_RAM2.Bit6 = 1; //B 
  LCD_MEM->LCD_RAM3.Bit5 = 1; //C
  LCD_MEM->LCD_RAM3.Bit4 = 1; //D
  LCD_MEM->LCD_RAM0.Bit0 = 1; //E
  LCD_MEM->LCD_RAM6.Bit3 = 1; //F
  
  LCD_MEM->LCD_RAM2.Bit7 = 0; //1G
  LCD_MEM->LCD_RAM0.Bit1 = 0; //1M
}

void LCD_11()
{
  LCD_MEM->LCD_RAM2.Bit6 = 1; 
  LCD_MEM->LCD_RAM3.Bit5 = 1;
  
  LCD_MEM->LCD_RAM6.Bit2 = 0; //1A
  LCD_MEM->LCD_RAM3.Bit4 = 0; //1D
  LCD_MEM->LCD_RAM0.Bit0 = 0; //1E
  LCD_MEM->LCD_RAM6.Bit3 = 0; //1F
  LCD_MEM->LCD_RAM2.Bit7 = 0; //1G
  LCD_MEM->LCD_RAM0.Bit1 = 0; //1M
}

void LCD_12()
{
  LCD_MEM->LCD_RAM6.Bit2 = 1;
  LCD_MEM->LCD_RAM2.Bit6 = 1;
  LCD_MEM->LCD_RAM2.Bit7 = 1;
  LCD_MEM->LCD_RAM0.Bit1 = 1;
  LCD_MEM->LCD_RAM0.Bit0 = 1; //E
  LCD_MEM->LCD_RAM3.Bit4 = 1;
  
  LCD_MEM->LCD_RAM3.Bit5 = 0; //1C
  LCD_MEM->LCD_RAM6.Bit3 = 0; //1F
}

void LCD_13()
{
  LCD_MEM->LCD_RAM6.Bit2 = 1; // A
  LCD_MEM->LCD_RAM2.Bit6 = 1; //B 
  LCD_MEM->LCD_RAM2.Bit7 = 1; //G
  LCD_MEM->LCD_RAM0.Bit1 = 1; //M
  LCD_MEM->LCD_RAM3.Bit5 = 1; //C
  LCD_MEM->LCD_RAM3.Bit4 = 1; //D
  
  LCD_MEM->LCD_RAM0.Bit0 = 0; //1E
  LCD_MEM->LCD_RAM6.Bit3 = 0; //1F
}

void LCD_14()
{
  LCD_MEM->LCD_RAM6.Bit3 = 1; // F
  LCD_MEM->LCD_RAM2.Bit7 = 1; // G
  LCD_MEM->LCD_RAM0.Bit1 = 1; // M
  LCD_MEM->LCD_RAM2.Bit6 = 1; // B
  LCD_MEM->LCD_RAM3.Bit5 = 1; // C
  
  LCD_MEM->LCD_RAM6.Bit2 = 0; //1A
  LCD_MEM->LCD_RAM3.Bit4 = 0; //1D
  LCD_MEM->LCD_RAM0.Bit0 = 0; //1E
}

void LCD_15()
{
  LCD_MEM->LCD_RAM6.Bit2 = 1; // A
  LCD_MEM->LCD_RAM6.Bit3 = 1; // F
  LCD_MEM->LCD_RAM2.Bit7 = 1; // G
  LCD_MEM->LCD_RAM0.Bit1 = 1; // M
  LCD_MEM->LCD_RAM3.Bit5 = 1; // C
  LCD_MEM->LCD_RAM3.Bit4 = 1; //D
  
  LCD_MEM->LCD_RAM2.Bit6 = 0; //1B 
  LCD_MEM->LCD_RAM0.Bit0 = 0; //1E
}

void LCD_16()
{
  LCD_MEM->LCD_RAM6.Bit2 = 1; // A
  LCD_MEM->LCD_RAM6.Bit3 = 1; // F
  LCD_MEM->LCD_RAM2.Bit7 = 1; // G
  LCD_MEM->LCD_RAM0.Bit1 = 1; // M
  LCD_MEM->LCD_RAM3.Bit5 = 1; // C
  LCD_MEM->LCD_RAM3.Bit4 = 1; //D
  LCD_MEM->LCD_RAM0.Bit0 = 1; //E
  
  LCD_MEM->LCD_RAM2.Bit6 = 0; //1B
}

void LCD_17()
{
  LCD_MEM->LCD_RAM6.Bit2 = 1; // 1A
  LCD_MEM->LCD_RAM2.Bit6 = 1; //1B 
  LCD_MEM->LCD_RAM3.Bit5 = 1; //C
  
  LCD_MEM->LCD_RAM3.Bit4 = 0; //1D
  LCD_MEM->LCD_RAM0.Bit0 = 0; //1E
  LCD_MEM->LCD_RAM6.Bit3 = 0; //1F
  LCD_MEM->LCD_RAM2.Bit7 = 0; //1G
  LCD_MEM->LCD_RAM0.Bit1 = 0; //1M
}

void LCD_18()
{
  LCD_MEM->LCD_RAM6.Bit2 = 1; // 1A
  LCD_MEM->LCD_RAM2.Bit6 = 1; //1B 
  LCD_MEM->LCD_RAM3.Bit5 = 1; //1C
  LCD_MEM->LCD_RAM3.Bit4 = 1; //1D
  LCD_MEM->LCD_RAM0.Bit0 = 1; //1E
  LCD_MEM->LCD_RAM6.Bit3 = 1; // 1F
  LCD_MEM->LCD_RAM2.Bit7 = 1; // 1G
  LCD_MEM->LCD_RAM0.Bit1 = 1; // 1M
}

void LCD_19()
{
  LCD_MEM->LCD_RAM6.Bit2 = 1; // 1A
  LCD_MEM->LCD_RAM2.Bit6 = 1; //1B 
  LCD_MEM->LCD_RAM3.Bit5 = 1; //1C
  LCD_MEM->LCD_RAM3.Bit4 = 1; //1D
  LCD_MEM->LCD_RAM6.Bit3 = 1; // 1F
  LCD_MEM->LCD_RAM2.Bit7 = 1; // 1G
  LCD_MEM->LCD_RAM0.Bit1 = 1; // 1M
  
  LCD_MEM->LCD_RAM0.Bit0 = 0; //1E
}

// 2

void LCD_20()
{
  LCD_MEM->LCD_RAM6.Bit0 = 1; //2A
  LCD_MEM->LCD_RAM2.Bit4 = 1; //2B
  LCD_MEM->LCD_RAM3.Bit7 = 1; //2C
  LCD_MEM->LCD_RAM3.Bit6 = 1; //2D
  LCD_MEM->LCD_RAM0.Bit2 = 1; //2E
  LCD_MEM->LCD_RAM6.Bit1 = 1; //2F
  
  LCD_MEM->LCD_RAM2.Bit5 = 0; //2G
  LCD_MEM->LCD_RAM0.Bit3 = 0; //2M
}

void LCD_21()
{
  LCD_MEM->LCD_RAM2.Bit4 = 1; //2B
  LCD_MEM->LCD_RAM3.Bit7 = 1; //2C
  
  LCD_MEM->LCD_RAM6.Bit0 = 0; //2A
  LCD_MEM->LCD_RAM2.Bit5 = 0; //2G
  LCD_MEM->LCD_RAM3.Bit6 = 0; //2D
  LCD_MEM->LCD_RAM0.Bit2 = 0; //2E
  LCD_MEM->LCD_RAM6.Bit1 = 0; //2F
  LCD_MEM->LCD_RAM0.Bit3 = 0; //2M
}

void LCD_22()
{
  LCD_MEM->LCD_RAM6.Bit0 = 1; //2A
  LCD_MEM->LCD_RAM2.Bit4 = 1; //2B
  LCD_MEM->LCD_RAM0.Bit3 = 1; //2M
  LCD_MEM->LCD_RAM2.Bit5 = 1; //2G
  LCD_MEM->LCD_RAM3.Bit6 = 1; //2D
  LCD_MEM->LCD_RAM0.Bit2 = 1; //2E
  
  LCD_MEM->LCD_RAM3.Bit7 = 0; //2C
  LCD_MEM->LCD_RAM6.Bit1 = 0; //2F
}

void LCD_23()
{
  LCD_MEM->LCD_RAM6.Bit0 = 1; //2A
  LCD_MEM->LCD_RAM2.Bit4 = 1; //2B
  LCD_MEM->LCD_RAM0.Bit3 = 1; //2M
  LCD_MEM->LCD_RAM2.Bit5 = 1; //2G
  LCD_MEM->LCD_RAM3.Bit6 = 1; //2D
  LCD_MEM->LCD_RAM3.Bit7 = 1; //2C
  
  LCD_MEM->LCD_RAM0.Bit2 = 0; //2E
  LCD_MEM->LCD_RAM6.Bit1 = 0; //2F
}

void LCD_24()
{
  LCD_MEM->LCD_RAM6.Bit1 = 1; //2F
  LCD_MEM->LCD_RAM2.Bit4 = 1; //2B
  LCD_MEM->LCD_RAM0.Bit3 = 1; //2M
  LCD_MEM->LCD_RAM2.Bit5 = 1; //2G
  LCD_MEM->LCD_RAM3.Bit7 = 1; //2C
  
  LCD_MEM->LCD_RAM6.Bit0 = 0; //2A
  LCD_MEM->LCD_RAM3.Bit6 = 0; //2D
  LCD_MEM->LCD_RAM0.Bit2 = 0; //2E
}

void LCD_25()
{
  LCD_MEM->LCD_RAM6.Bit1 = 1; //2F
  LCD_MEM->LCD_RAM0.Bit3 = 1; //2M
  LCD_MEM->LCD_RAM2.Bit5 = 1; //2G
  LCD_MEM->LCD_RAM3.Bit7 = 1; //2C
  LCD_MEM->LCD_RAM6.Bit0 = 1; //2A
  LCD_MEM->LCD_RAM3.Bit6 = 1; //2D
  
  LCD_MEM->LCD_RAM2.Bit4 = 0; //2B
  LCD_MEM->LCD_RAM0.Bit2 = 0; //2E
}

void LCD_26()
{
  LCD_MEM->LCD_RAM6.Bit1 = 1; //2F
  LCD_MEM->LCD_RAM0.Bit3 = 1; //2M
  LCD_MEM->LCD_RAM2.Bit5 = 1; //2G
  LCD_MEM->LCD_RAM3.Bit7 = 1; //2C
  LCD_MEM->LCD_RAM6.Bit0 = 1; //2A
  LCD_MEM->LCD_RAM3.Bit6 = 1; //2D
  LCD_MEM->LCD_RAM0.Bit2 = 1; //2E
  
  LCD_MEM->LCD_RAM2.Bit4 = 0; //2B
}

void LCD_27()
{
  LCD_MEM->LCD_RAM6.Bit0 = 1; //2A
  LCD_MEM->LCD_RAM2.Bit4 = 1; //2B
  LCD_MEM->LCD_RAM3.Bit7 = 1; //2C
  
  LCD_MEM->LCD_RAM2.Bit5 = 0; //2G
  LCD_MEM->LCD_RAM3.Bit6 = 0; //2D
  LCD_MEM->LCD_RAM0.Bit2 = 0; //2E
  LCD_MEM->LCD_RAM6.Bit1 = 0; //2F
  LCD_MEM->LCD_RAM0.Bit3 = 0; //2M
}

void LCD_28()
{
  LCD_MEM->LCD_RAM6.Bit0 = 1; //2A
  LCD_MEM->LCD_RAM2.Bit4 = 1; //2B
  LCD_MEM->LCD_RAM3.Bit7 = 1; //2C
  LCD_MEM->LCD_RAM2.Bit5 = 1; //2G
  LCD_MEM->LCD_RAM3.Bit6 = 1; //2D
  LCD_MEM->LCD_RAM0.Bit2 = 1; //2E
  LCD_MEM->LCD_RAM6.Bit1 = 1; //2F
  LCD_MEM->LCD_RAM0.Bit3 = 1; //2M
}

void LCD_29()
{
  LCD_MEM->LCD_RAM6.Bit0 = 1; //2A
  LCD_MEM->LCD_RAM2.Bit4 = 1; //2B
  LCD_MEM->LCD_RAM3.Bit7 = 1; //2C
  LCD_MEM->LCD_RAM2.Bit5 = 1; //2G
  LCD_MEM->LCD_RAM3.Bit6 = 1; //2D
  LCD_MEM->LCD_RAM6.Bit1 = 1; //2F
  LCD_MEM->LCD_RAM0.Bit3 = 1; //2M
  
  LCD_MEM->LCD_RAM0.Bit2 = 0; //2E
}

void LCD_30()
{
  LCD_MEM->LCD_RAM5.Bit6 = 1; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 1; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 1; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 0; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 1; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 1; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 1; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 0; //3M
}

void LCD_31()
{
  LCD_MEM->LCD_RAM5.Bit6 = 0; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 1; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 1; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 0; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 0; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 0; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 0; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 0; //3M
}

void LCD_32()
{
  LCD_MEM->LCD_RAM5.Bit6 = 1; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 1; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 0; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 1; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 1; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 1; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 0; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 1; //3M
}

void LCD_33()
{
  LCD_MEM->LCD_RAM5.Bit6 = 1; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 1; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 1; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 1; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 1; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 0; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 0; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 1; //3M
}

void LCD_34()
{
  LCD_MEM->LCD_RAM5.Bit6 = 0; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 1; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 1; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 1; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 0; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 0; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 1; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 1; //3M
}

void LCD_35()
{
  LCD_MEM->LCD_RAM5.Bit6 = 1; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 0; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 1; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 1; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 1; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 0; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 1; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 1; //3M
}

void LCD_36()
{
  LCD_MEM->LCD_RAM5.Bit6 = 1; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 0; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 1; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 1; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 1; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 1; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 1; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 1; //3M
}

void LCD_37()
{
  LCD_MEM->LCD_RAM5.Bit6 = 1; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 1; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 1; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 0; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 0; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 0; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 0; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 0; //3M
}

void LCD_38()
{
  LCD_MEM->LCD_RAM5.Bit6 = 1; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 1; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 1; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 1; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 1; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 1; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 1; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 1; //3M
}

void LCD_39()
{
  LCD_MEM->LCD_RAM5.Bit6 = 1; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 1; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 1; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 1; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 1; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 0; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 1; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 1; //3M
}

void LCD_4B()
{
  
  LCD_MEM->LCD_RAM5.Bit4 = 1; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 1; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 1; //4C
  LCD_MEM->LCD_RAM4.Bit2 = 1; //4D
  LCD_MEM->LCD_RAM0.Bit7 = 1; //4M
  LCD_MEM->LCD_RAM7.Bit6 = 1; //4P
  LCD_MEM->LCD_RAM12.Bit4 = 1; //4J
  LCD_MEM->LCD_RAM2.Bit1 = 0; //4G
  LCD_MEM->LCD_RAM0.Bit6 = 0; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 0; //4F
}

void LCD_40()
{
  LCD_MEM->LCD_RAM5.Bit4 = 1; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 1; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 1; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 0; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 1; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 1; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 1; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 0; //4M
}

void LCD_41()
{
  LCD_MEM->LCD_RAM5.Bit4 = 0; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 1; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 1; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 0; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 0; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 0; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 0; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 0; //4M
}

void LCD_42()
{
  LCD_MEM->LCD_RAM5.Bit4 = 1; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 1; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 0; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 1; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 1; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 1; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 0; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 1; //4M
}

void LCD_43()
{
  LCD_MEM->LCD_RAM5.Bit4 = 1; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 1; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 1; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 1; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 1; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 0; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 0; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 1; //4M
}

void LCD_44()
{
  LCD_MEM->LCD_RAM5.Bit4 = 0; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 1; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 1; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 1; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 0; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 0; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 1; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 1; //4M
}

void LCD_45()
{
  LCD_MEM->LCD_RAM5.Bit4 = 1; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 0; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 1; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 1; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 1; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 0; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 1; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 1; //4M
}

void LCD_46()
{
  LCD_MEM->LCD_RAM5.Bit4 = 1; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 0; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 1; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 1; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 1; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 1; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 1; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 1; //4M
}

void LCD_47()
{
  LCD_MEM->LCD_RAM5.Bit4 = 1; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 1; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 1; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 0; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 0; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 0; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 0; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 0; //4M
}

void LCD_48()
{
  LCD_MEM->LCD_RAM5.Bit4 = 1; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 1; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 1; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 1; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 1; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 1; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 1; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 1; //4M
}

void LCD_49()
{
  LCD_MEM->LCD_RAM5.Bit4 = 1; //4A
  LCD_MEM->LCD_RAM1.Bit6 = 1; //4B
  LCD_MEM->LCD_RAM4.Bit5 = 1; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 1; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 1; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 0; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 1; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 1; //4M
}
//lcd 5
void LCD_50()
{
  LCD_MEM->LCD_RAM5.Bit2 = 1; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 1; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 1; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 0; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 1; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 1; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 1; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 0; //5M
}
void LCD_51()
{
  LCD_MEM->LCD_RAM5.Bit2 = 0; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 1; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 1; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 0; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 0; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 0; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 0; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 0; //5M
}
void LCD_52()
{
  LCD_MEM->LCD_RAM5.Bit2 = 1; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 1; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 0; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 1; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 1; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 1; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 0; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 1; //5M
}
void LCD_53()
{
  LCD_MEM->LCD_RAM5.Bit2 = 1; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 1; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 1; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 1; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 1; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 0; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 0; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 1; //5M
}
void LCD_54()
{
  LCD_MEM->LCD_RAM5.Bit2 = 0; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 1; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 1; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 1; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 0; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 0; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 0; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 1; //5M
}
void LCD_55()
{
  LCD_MEM->LCD_RAM5.Bit2 = 1; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 0; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 1; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 1; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 1; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 0; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 1; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 1; //5M
}
void LCD_56()
{
  LCD_MEM->LCD_RAM5.Bit2 = 1; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 0; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 1; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 1; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 1; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 1; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 1; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 1; //5M
}
void LCD_57()
{
  LCD_MEM->LCD_RAM5.Bit2 = 1; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 1; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 1; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 0; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 0; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 0; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 0; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 0; //5M
}
void LCD_58()
{
  LCD_MEM->LCD_RAM5.Bit2 = 1; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 1; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 1; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 1; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 1; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 1; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 1; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 1; //5M
}
void LCD_59()
{
  LCD_MEM->LCD_RAM5.Bit2 = 1; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 1; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 1; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 1; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 1; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 0; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 1; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 1; //5M
}
//lcd 6
void LCD_60()
{
  LCD_MEM->LCD_RAM5.Bit0 = 1; //6A
  LCD_MEM->LCD_RAM1.Bit4 = 1; //6B
  LCD_MEM->LCD_RAM4.Bit7 = 1; //6C
  LCD_MEM->LCD_RAM1.Bit5 = 0; //6G
  LCD_MEM->LCD_RAM4.Bit6 = 1; //6D
  LCD_MEM->LCD_RAM1.Bit2 = 1; //6E
  LCD_MEM->LCD_RAM5.Bit1 = 1; //6F
  LCD_MEM->LCD_RAM1.Bit3 = 0; //6M
}
void LCD_61()
{
  LCD_MEM->LCD_RAM5.Bit0 = 0; //6A
  LCD_MEM->LCD_RAM1.Bit4 = 1; //6B
  LCD_MEM->LCD_RAM4.Bit7 = 1; //6C
  LCD_MEM->LCD_RAM1.Bit5 = 0; //6G
  LCD_MEM->LCD_RAM4.Bit6 = 0; //6D
  LCD_MEM->LCD_RAM1.Bit2 = 0; //6E
  LCD_MEM->LCD_RAM5.Bit1 = 0; //6F
  LCD_MEM->LCD_RAM1.Bit3 = 0; //6M
}
void LCD_62()
{
  LCD_MEM->LCD_RAM5.Bit0 = 1; //6A
  LCD_MEM->LCD_RAM1.Bit4 = 1; //6B
  LCD_MEM->LCD_RAM4.Bit7 = 0; //6C
  LCD_MEM->LCD_RAM1.Bit5 = 1; //6G
  LCD_MEM->LCD_RAM4.Bit6 = 1; //6D
  LCD_MEM->LCD_RAM1.Bit2 = 1; //6E
  LCD_MEM->LCD_RAM5.Bit1 = 0; //6F
  LCD_MEM->LCD_RAM1.Bit3 = 1; //6M
}
void LCD_63()
{
  LCD_MEM->LCD_RAM5.Bit0 = 1; //6A
  LCD_MEM->LCD_RAM1.Bit4 = 1; //6B
  LCD_MEM->LCD_RAM4.Bit7 = 1; //6C
  LCD_MEM->LCD_RAM1.Bit5 = 1; //6G
  LCD_MEM->LCD_RAM4.Bit6 = 1; //6D
  LCD_MEM->LCD_RAM1.Bit2 = 0; //6E
  LCD_MEM->LCD_RAM5.Bit1 = 0; //6F
  LCD_MEM->LCD_RAM1.Bit3 = 1; //6M
}
void LCD_64()
{
  LCD_MEM->LCD_RAM5.Bit0 = 0; //6A
  LCD_MEM->LCD_RAM1.Bit4 = 1; //6B
  LCD_MEM->LCD_RAM4.Bit7 = 1; //6C
  LCD_MEM->LCD_RAM1.Bit5 = 1; //6G
  LCD_MEM->LCD_RAM4.Bit6 = 0; //6D
  LCD_MEM->LCD_RAM1.Bit2 = 0; //6E
  LCD_MEM->LCD_RAM5.Bit1 = 1; //6F
  LCD_MEM->LCD_RAM1.Bit3 = 1; //6M
}
void LCD_65()
{
  LCD_MEM->LCD_RAM5.Bit0 = 1; //6A
  LCD_MEM->LCD_RAM1.Bit4 = 0; //6B
  LCD_MEM->LCD_RAM4.Bit7 = 1; //6C
  LCD_MEM->LCD_RAM1.Bit5 = 1; //6G
  LCD_MEM->LCD_RAM4.Bit6 = 1; //6D
  LCD_MEM->LCD_RAM1.Bit2 = 0; //6E
  LCD_MEM->LCD_RAM5.Bit1 = 1; //6F
  LCD_MEM->LCD_RAM1.Bit3 = 1; //6M
}
void LCD_66()
{
  LCD_MEM->LCD_RAM5.Bit0 = 1; //6A
  LCD_MEM->LCD_RAM1.Bit4 = 0; //6B
  LCD_MEM->LCD_RAM4.Bit7 = 1; //6C
  LCD_MEM->LCD_RAM1.Bit5 = 1; //6G
  LCD_MEM->LCD_RAM4.Bit6 = 1; //6D
  LCD_MEM->LCD_RAM1.Bit2 = 1; //6E
  LCD_MEM->LCD_RAM5.Bit1 = 1; //6F
  LCD_MEM->LCD_RAM1.Bit3 = 1; //6M
}
void LCD_67()
{
  LCD_MEM->LCD_RAM5.Bit0 = 1; //6A
  LCD_MEM->LCD_RAM1.Bit4 = 1; //6B
  LCD_MEM->LCD_RAM4.Bit7 = 1; //6C
  LCD_MEM->LCD_RAM1.Bit5 = 0; //6G
  LCD_MEM->LCD_RAM4.Bit6 = 0; //6D
  LCD_MEM->LCD_RAM1.Bit2 = 0; //6E
  LCD_MEM->LCD_RAM5.Bit1 = 0; //6F
  LCD_MEM->LCD_RAM1.Bit3 = 0; //6M
}
void LCD_68()
{
  LCD_MEM->LCD_RAM5.Bit0 = 1; //6A
  LCD_MEM->LCD_RAM1.Bit4 = 1; //6B
  LCD_MEM->LCD_RAM4.Bit7 = 1; //6C
  LCD_MEM->LCD_RAM1.Bit5 = 1; //6G
  LCD_MEM->LCD_RAM4.Bit6 = 1; //6D
  LCD_MEM->LCD_RAM1.Bit2 = 1; //6E
  LCD_MEM->LCD_RAM5.Bit1 = 1; //6F
  LCD_MEM->LCD_RAM1.Bit3 = 1; //6M
}
void LCD_69()
{
  LCD_MEM->LCD_RAM5.Bit0 = 1; //6A
  LCD_MEM->LCD_RAM1.Bit4 = 1; //6B
  LCD_MEM->LCD_RAM4.Bit7 = 1; //6C
  LCD_MEM->LCD_RAM1.Bit5 = 1; //6G
  LCD_MEM->LCD_RAM4.Bit6 = 1; //6D
  LCD_MEM->LCD_RAM1.Bit2 = 0; //6E
  LCD_MEM->LCD_RAM5.Bit1 = 1; //6F
  LCD_MEM->LCD_RAM1.Bit3 = 1; //6M
}
// :
void LCD_COLON()
{
  LCD_MEM->LCD_RAM7.Bit1 = 1; // 1:
  LCD_MEM->LCD_RAM7.Bit7 = 1; // 4:
}
void LCD_345_WIN()
{
  //A
  LCD_1A();
  //W
  LCD_MEM->LCD_RAM5.Bit6 = 0; //3A
  LCD_MEM->LCD_RAM2.Bit2 = 1; //3B
  LCD_MEM->LCD_RAM4.Bit1 = 1; //3C
  LCD_MEM->LCD_RAM2.Bit3 = 0; //3G
  LCD_MEM->LCD_RAM4.Bit0 = 0; //3D
  LCD_MEM->LCD_RAM0.Bit4 = 1; //3E
  LCD_MEM->LCD_RAM5.Bit7 = 1; //3F
  LCD_MEM->LCD_RAM0.Bit5 = 0; //3M
  LCD_MEM->LCD_RAM9.Bit3 = 1; //3Q
  LCD_MEM->LCD_RAM11.Bit0 = 1; //3N
  //I
  LCD_MEM->LCD_RAM5.Bit4 = 1; //4A
  LCD_MEM->LCD_RAM2.Bit0 = 0; //4B
  LCD_MEM->LCD_RAM4.Bit3 = 0; //4C
  LCD_MEM->LCD_RAM2.Bit1 = 0; //4G
  LCD_MEM->LCD_RAM4.Bit2 = 1; //4D
  LCD_MEM->LCD_RAM0.Bit6 = 0; //4E
  LCD_MEM->LCD_RAM5.Bit5 = 0; //4F
  LCD_MEM->LCD_RAM0.Bit7 = 0; //4M
  LCD_MEM->LCD_RAM12.Bit4 = 1; //4J
  LCD_MEM->LCD_RAM7.Bit6 = 1; //4P
  //N
  LCD_MEM->LCD_RAM5.Bit2 = 0; //5A
  LCD_MEM->LCD_RAM1.Bit6 = 1; //5B
  LCD_MEM->LCD_RAM4.Bit5 = 1; //5C
  LCD_MEM->LCD_RAM1.Bit7 = 0; //5G
  LCD_MEM->LCD_RAM4.Bit4 = 0; //5D
  LCD_MEM->LCD_RAM1.Bit0 = 1; //5E
  LCD_MEM->LCD_RAM5.Bit3 = 1; //5F
  LCD_MEM->LCD_RAM1.Bit1 = 0; //5M
  LCD_MEM->LCD_RAM12.Bit3 = 1; //5H
  LCD_MEM->LCD_RAM11.Bit4 = 1; //5N
}
void config_LCD()
{
  //LCD onboard has 4 commons => duty = 1/4
  LCD_Control->LCD_CR1 = (uint8_t)0x2E;
  LCD_Control->LCD_CR2 = 0x0E;
  SBit(LCD_Control->LCD_CR3,5); // enable interrupt LCD
  // deadtime = 3 phase, no interrupt
  LCD_Control->LCD_CR3 &= 0xF6;
  LCD_Control->LCD_CR3 |= 0x03;
  LCD_Control->LCD_CR3 |= 0x30; //dead time
  LCD_Control->LCD_CR3 |= 0x40; //enable LCD
  LCD_Control->LCD_FRQ = (uint8_t)0x20;
  LCD_Control->LCD_PM0 = 0xFF;
  LCD_Control->LCD_PM1 = 0xFF;
  LCD_Control->LCD_PM2 = 0xFF;
  LCD_Control->LCD_PM3 = 0xFF;
}
void config_UART(void)
{
 //PA2 UART_TX
 //PA3 UART_RX
  UART1->BRR1 = 0x68; // bit 11:4
  UART1->BRR2 = 0x03; // bit 12:15 & 0:3
  // Baudrate ~9600
  //UART1->CR2 = 0xAC;  // Tx Enable, Rx Enable, Rx & Tx Interrupt Enable
  UART1->CR2 = 0x2C;  // Tx Enable, Rx Enable, Rx Interrupt Enable
  UART1->CR3 = 0x00;  // 1 Stop bits
}