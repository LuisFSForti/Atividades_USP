//Luís Filipe Silva Forti

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
     //WordToStr sempre faz uma saída de 6 caracteres
     //https://download.mikroe.com/documents/compilers/mikroc/pic/help/conversions_library.htm
     unsigned char Texto[6];
     float tensao;
     int tensaoInteira;
     int tensaoDecimal;
     //Escrever a string direto no Lcd_Out não estava funcionando corretamente
     //Na documentação, eles usam as strings instanciadas previamente, então assim o fiz
     //https://download.mikroe.com/documents/compilers/mikroc/pic/help/lcd_library.htm
     char labelADC[] = "ADC: ";
     char labelCurso[] = "SEL0036.........";

     //Coloca a porta A0 em modo de alta impedância
     TRISA.RA0 = 1;
     //Ativa o ADC na porta AN0 e em "Idle"
     ADCON0 = 0B00000001;
     //Tensão de referência = VDD/VSS e todas as portas são digitias, exceto a A0
     ADCON1 = 0B00001110;
     ADCON2 = 0B10010000;

     Lcd_Init();
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Cmd(_LCD_CURSOR_OFF);
     Lcd_Out(1, 1, labelADC);
     Lcd_Out(2, 1, labelCurso);

     while(1)
     {
             //Ativa a conversão
             ADCON0.GO_DONE = 1;
             //Enquanto estiver convertendo
             while(ADCON0.GO_DONE == 1) ;

             //Lê o resultado
             //Como ADC é composto de 10 bits, ele precisa de 2 bytes, ADRESH e ADRESL
             //Quando está justificado à direita, precisa dar um bitshift de 8 bits no ADRESH
             //00000011 -> 00000011 00000000
             //Assim cria um número de 2 bytes, com os bits de ADRESH no byte maior
             //Fazendo "ou lógico" com o ADRESL, junta os dois bytes criados com o byte do ADRESL
             //Como o byte menor de ADRESH é 0, então é o mesmo que juntar os bytes de ADRESH e ADRESL
             //Assim reconstruindo o valor de ADC
             ADC = ((ADRESH << 8) | ADRESL);

             //ADC será de 0 a 1023, usando VSS e VDD como referência
             //Converte a leitura para a tensão real
             tensao = (ADC * 5.0) / 1023.0;
             //Separa a parte inteira da decimal
             tensaoInteira = tensao;
             tensaoDecimal = (tensao - tensaoInteira) * 1000;

             //Converte os decimais para string
             WordToStr(tensaoDecimal, Texto);
             //Se for menor que 100, preenche os espaços necessários com 0
             //Analisa se for menor que 10 também
             if (tensaoDecimal < 100)
             {
                Texto[2] = '0';

                if (tensaoDecimal < 10)
                   Texto[3] = '0';
             }
             //Adiciona um '.' antes dos decimais
             Texto[1] = '.';
             //Como vai de 0 a 5, então pode transformar a parte inteira em caractere
             Texto[0] = tensaoInteira + '0';
             //Escreve a tensão final
             LCD_Out(1, 12, Texto);

             //Espera um pouco
             Delay_ms(20);
     }
}