#if defined(__PCM__)
#include <16F877A.H>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use DELAY(CLOCK=16000000)
#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7)
 #define use_portd_lcd TRUE
#include <lcd.c>
#byte T2CON=0x12
#byte CCP2CON=0x1D
#byte CCPR2L=0x1B
#bit TRISC=0x87.1
unsigned int a;

void main()
{
lcd_init();
delay_ms(1000);
lcd_putc('\f');
lcd_gotoxy(4,1);
lcd_putc("WELCOME");
delay_ms(1000);
TRISC=0;       //portc pin 1 is output

T2CON=0x04;     //timer2 is enable
CCP2CON=0x0c;   //pwm mode





While(1)
{
 if(input(pin_b0)==1)
  {
   CCPR2L=0xff;    //full duty cycle
   delay_ms(50);
   lcd_putc('\f');
   lcd_gotoxy(1,1);
   lcd_putc("log=");
   lcd_gotoxy(5,1);
   lcd_putc("11.2588° N");
    lcd_gotoxy(1,2);
   lcd_putc("lat=");
   lcd_gotoxy(5,2);
   lcd_putc("75.7804° E");
   delay_ms(250);
   lcd_putc('\f');
   lcd_gotoxy(1,1);
   lcd_putc("Full_Speed=60km/h");
   delay_ms(100);
  }
else if(input(pin_b1)==1)
{
CCPR2L=0xaf;    //voltage reduced we can set any register between 0x00 to 0xff
delay_ms(50);
   lcd_putc('\f');
   lcd_gotoxy(1,1);
   lcd_putc("log=");
   lcd_gotoxy(5,1);
   lcd_putc("8.5241°N");
    lcd_gotoxy(1,2);
   lcd_putc("lat=");
   lcd_gotoxy(5,2);
   lcd_putc("76.9366° E");
   delay_ms(250);
   lcd_putc('\f');
   lcd_gotoxy(1,1);
   lcd_putc("SCHOOL_ZONE");
   delay_ms(50);
   lcd_gotoxy(1,2);
   lcd_putc("Speed=40km/h");
   delay_ms(50);
}
else if(input(pin_b2)==1)
{
CCPR2L=0x0f;
delay_ms(50);
lcd_putc('\f');
   lcd_gotoxy(1,1);
   lcd_putc("log=");
   lcd_gotoxy(5,1);
   lcd_putc("11.2588° N");
    lcd_gotoxy(1,2);
   lcd_putc("lat=");
   lcd_gotoxy(5,2);
   lcd_putc("75.7804° E");
   delay_ms(150);
   lcd_putc('\f');
   lcd_gotoxy(1,1);
   lcd_putc("SPEED_BREAKER");
   delay_ms(50);
   lcd_gotoxy(1,2);
   lcd_putc("Speed=20km/h");
   delay_ms(50);
}
else
{
CCPR2L=0x00;
delay_ms(50);
lcd_putc('\f');
}
}
}
