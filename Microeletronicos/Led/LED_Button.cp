#line 1 "C:/Users/luis/Documents/Facul/Microeletronicos/LED_Button.c"
void main()
{
 TRISC.RC0 = 1;
 PORTC.RC0 = 1;

 TRISD.RD1 = 0;
 PORTD.RD1 = 0;

 while(1)
 {
 if(PORTC.RC0 == 0)
 {
 LATD.RD1 = 1;
 Delay_ms(300);
 }
 else
 {
 LATD.RD1 = 0;
 }
 }
}
