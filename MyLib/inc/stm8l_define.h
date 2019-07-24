#include <stdint.h>

#define TBit(VALUE,place) ((VALUE) ^= (1<<place))
#define SBit(VALUE, place)      ((VALUE) |= ((1<<place)))
#define CBit(VALUE, place)      ((VALUE) &=~((1<<place)))
#define GetBit(VALUE, place)  (((VALUE)>>place)&(0x01))

typedef struct BITFIELD_Struct{
  uint8_t Bit0 :1;
  uint8_t Bit1 :1;
  uint8_t Bit2 :1;
  uint8_t Bit3 :1;
  uint8_t Bit4 :1;
  uint8_t Bit5 :1;
  uint8_t Bit6 :1;
  uint8_t Bit7 :1;
}BITFILED;

// interrupt button
typedef struct{
  uint8_t CR1;
  uint8_t CR2;
  uint8_t CR3;
  uint8_t SR1;
  uint8_t SR2;
  uint8_t CONF;
}EXTI_Type;

#define ITC_SPR3 (*(uint8_t *)0x7F72)
#define ITC_SPR5 (*(uint8_t *)0x7F74)
#define ITC_SPR7 (*(uint8_t *)0x7F76)
#define ITC_SPR8 (*(uint8_t *)0x7F77)

#define EXTI ((EXTI_Type *) 0x50A0)
 void config_Int_Ex(void);
 void config_interrupt_priority(void);
 
 //config CLK
 typedef struct CLK_Struct{
  uint8_t DIVR;
  uint8_t CRTCR;
  uint8_t ICKR;
  uint8_t PCKENR1;
  uint8_t PCKENR2;
  uint8_t CCOR;
  uint8_t ECKR;
  uint8_t SCSR;
  uint8_t SWR;
  uint8_t SWCR;
  uint8_t CSSR;
  uint8_t CBEEPR;
  uint8_t HSICALR;
  uint8_t HSITRIMR;
  uint8_t HSIUNLCKR;
  uint8_t REGCSR;      
}CLK_Type; 
#define CLK   ((CLK_Type *) 0x50C0)
void config_CLK_LSE();
void config_CLK_HSI();

 
 // config LCD
 typedef struct LCD_CON_Struct{
  uint8_t LCD_CR1;
  uint8_t LCD_CR2;
  uint8_t LCD_CR3;
  uint8_t LCD_FRQ;
  uint8_t LCD_PM0;
  uint8_t LCD_PM1;
  uint8_t LCD_PM2;
  uint8_t LCD_PM3;  
}LCD_Control_Type;

#define LCD_Control ((LCD_Control_Type *) 0x5400)

typedef struct LCD_MEM_Struct{
  BITFILED LCD_RAM0;
  BITFILED LCD_RAM1;
  BITFILED LCD_RAM2;
  BITFILED LCD_RAM3;
  BITFILED LCD_RAM4;
  BITFILED LCD_RAM5;
  BITFILED LCD_RAM6;
  BITFILED LCD_RAM7;
  BITFILED LCD_RAM8;
  BITFILED LCD_RAM9;
  BITFILED LCD_RAM10;
  BITFILED LCD_RAM11;
  BITFILED LCD_RAM12;
  BITFILED LCD_RAM13; 
} LCD_MEM_Type;

#define LCD_MEM ((LCD_MEM_Type *) 0x540C)

void config_LCD();

void LCD_Clear();
//lcd 1
void LCD_1A();
void LCD_10();
void LCD_11();
void LCD_12();
void LCD_13();
void LCD_14();
void LCD_15();
void LCD_16();
void LCD_17();
void LCD_18();
void LCD_19();
//lcd 2
void LCD_20();
void LCD_21();
void LCD_22();
void LCD_23();
void LCD_24();
void LCD_25();
void LCD_26();
void LCD_27();
void LCD_28();
void LCD_29();
//lcd 3
void LCD_30();
void LCD_31();
void LCD_32();
void LCD_33();
void LCD_34();
void LCD_35();
void LCD_36();
void LCD_37();
void LCD_38();
void LCD_39();
//lcd 4
void LCD_4B();
void LCD_40();
void LCD_41();
void LCD_42();
void LCD_43();
void LCD_44();
void LCD_45();
void LCD_46();
void LCD_47();
void LCD_48();
void LCD_49();
//lcd 5
void LCD_50();
void LCD_51();
void LCD_52();
void LCD_53();
void LCD_54();
void LCD_55();
void LCD_56();
void LCD_57();
void LCD_58();
void LCD_59();
//lcd 6
void LCD_60();
void LCD_61();
void LCD_62();
void LCD_63();
void LCD_64();
void LCD_65();
void LCD_66();
void LCD_67();
void LCD_68();
void LCD_69();

void LCD_COLON();
//lcd WIN
void LCD_345_WIN();
//define UART
typedef struct{
  uint8_t SR;
  uint8_t DR;
  uint8_t BRR1;
  uint8_t BRR2;
  uint8_t CR1;
  uint8_t  CR2;
  uint8_t CR3;
  uint8_t CR4;
  uint8_t CR5;
  uint8_t GTR;
  uint8_t PSCR;
}UART_Type;
#define UART1 ((UART_Type *) 0x5230)

void config_UART(void);
