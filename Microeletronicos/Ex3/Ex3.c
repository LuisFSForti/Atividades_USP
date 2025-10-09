//Lu�s Filipe Silva Forti

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
     //WordToStr sempre faz uma sa�da de 6 caracteres
     //https://download.mikroe.com/documents/compilers/mikroc/pic/help/conversions_library.htm
     unsigned char Texto[6];
     float tensao;
     int tensaoInteira;
     int tensaoDecimal;
     //Escrever a string direto no Lcd_Out n�o estava funcionando corretamente
     //Na documenta��o, eles usam as strings instanciadas previamente, ent�o assim o fiz
     //https://download.mikroe.com/documents/compilers/mikroc/pic/help/lcd_library.htm
     char labelADC[] = "ADC: ";
     char labelCurso[] = "SEL0036.........";

     //Coloca a porta A0 em modo de alta imped�ncia
     TRISA.RA0 = 1;
     //Ativa o ADC na porta AN0 e em "Idle"
     ADCON0 = 0B00000001;
     //Tens�o de refer�ncia = VDD/VSS e todas as portas s�o digitias, exceto a A0
     ADCON1 = 0B00001110;
     ADCON2 = 0B10010000;

     Lcd_Init();
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Cmd(_LCD_CURSOR_OFF);
     Lcd_Out(1, 1, labelADC);
     Lcd_Out(2, 1, labelCurso);

     while(1)
     {
             //Ativa a convers�o
             ADCON0.GO_DONE = 1;
             //Enquanto estiver convertendo
             while(ADCON0.GO_DONE == 1) ;

             //L� o resultado
             //Como ADC � composto de 10 bits, ele precisa de 2 bytes, ADRESH e ADRESL
             //Quando est� justificado � direita, precisa dar um bitshift de 8 bits no ADRESH
             //00000011 -> 00000011 00000000
             //Assim cria um n�mero de 2 bytes, com os bits de ADRESH no byte maior
             //Fazendo "ou l�gico" com o ADRESL, junta os dois bytes criados com o byte do ADRESL
             //Como o byte menor de ADRESH � 0, ent�o � o mesmo que juntar os bytes de ADRESH e ADRESL
             //Assim reconstruindo o valor de ADC
             ADC = ((ADRESH << 8) | ADRESL);

             //ADC ser� de 0 a 1023, usando VSS e VDD como refer�ncia
             //Converte a leitura para a tens�o real
             tensao = (ADC * 5.0) / 1023.0;
             //Separa a parte inteira da decimal
             tensaoInteira = tensao;
             tensaoDecimal = (tensao - tensaoInteira) * 1000;

             //Converte os decimais para string
             WordToStr(tensaoDecimal, Texto);
             //Se for menor que 100, preenche os espa�os necess�rios com 0
             //Analisa se for menor que 10 tamb�m
             if (tensaoDecimal < 100)
             {
                Texto[2] = '0';

                if (tensaoDecimal < 10)
                   Texto[3] = '0';
             }
             //Adiciona um '.' antes dos decimais
             Texto[1] = '.';
             //Como vai de 0 a 5, ent�o pode transformar a parte inteira em caractere
             Texto[0] = tensaoInteira + '0';
             //Escreve a tens�o final
             LCD_Out(1, 12, Texto);

             //Espera um pouco
             Delay_ms(20);
     }
}