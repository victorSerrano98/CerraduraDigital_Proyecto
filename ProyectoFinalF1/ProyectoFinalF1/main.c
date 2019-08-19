/*
 * PracticaFinalProyecto.c
 *
 * Created: 19/8/2019 14:16:24
 * Author : VICTOR SERRANO
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>
#include <util/delay.h>
#include "lcd.c"
#include "mat_kbrd.c"

bool comparaStr (char entrada[],char modelo[])
{
	int ind = 0;

	while (entrada[ind]!='\0' && modelo[ind]!='\0' && entrada[ind] == modelo[ind]) ind++;

	if (entrada[ind]!='\0' || modelo[ind]!='\0')
	return false;

	return true;
}
int main(void)
{
    /* Replace with your application code */
	char key;
	int i;
	lcd_init(LCD_DISP_ON);
	kbrd_init();
	lcd_home();
	lcd_clrscr();
	lcd_puts("INGRESE CLAVE: ");
	_delay_ms(50);
	char clave[4]= "123";
	char cont[4]="0000";
	int x=0;
    while (1) 
    {
		key = kbrd_read();
		if (key != 0)
		{
			lcd_gotoxy(i, 1);
			lcd_putc(key);
			cont[i]=  key;
			
			i++;
			if (i==3)
			{
				if (cont[0] == '1' && cont[1] == '2' && cont[2] == '3')
				{
					lcd_clrscr();
					lcd_puts("CORRECTO");
					_delay_ms(100);
				} 
				else
				{
					lcd_clrscr();
					lcd_puts("INCORRECTO");
					_delay_ms(100);
				}
				
				lcd_clrscr();
				lcd_puts("INGRESE CLAVE: ");
				_delay_ms(50);
				i=0;
				x=0;
					
				
			} 
			
			
			
		}
    }
}



