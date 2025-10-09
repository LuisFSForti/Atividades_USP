#line 1 "C:/Users/Luis/Documents/Facul/Atividades_USP/Microeletronicos/Ex3/Ex3.c"


sbit LCD_RS at LATB4_bit;
sbit LCD_EN at LATB5_bit;
sbit LCD_D4 at LATB0_bit;
sbit LCD_D5 at LATB1_bit;
sbit LCD_D6 at LATB2_bit;
sbit LCD_D7 at LATB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;

void main()
{
 unsigned int ADC;


 unsigned char Texto[6];
 float tensao;
 int tensaoInteira;
 int tensaoDecimal;



 char labelADC[] = "ADC: ";
 char labelCurso[] = "SEL0036.........";


 TRISA.RA0 = 1;

 ADCON0 = 0B00000001;

 ADCON1 = 0B00001110;
 ADCON2 = 0B10010000;

 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1, 1, labelADC);
 Lcd_Out(2, 1, labelCurso);

 while(1)
 {

 ADCON0.GO_DONE = 1;

 while(ADCON0.GO_DONE == 1) ;









 ADC = ((ADRESH << 8) | ADRESL);



 tensao = (ADC * 5.0) / 1023.0;

 tensaoInteira = tensao;
 tensaoDecimal = (tensao - tensaoInteira) * 1000;


 WordToStr(tensaoDecimal, Texto);


 if (tensaoDecimal < 100)
 {
 Texto[2] = '0';

 if (tensaoDecimal < 10)
 Texto[3] = '0';
 }

 Texto[1] = '.';

 Texto[0] = tensaoInteira + '0';

 LCD_Out(1, 12, Texto);


 Delay_ms(20);
 }
}
