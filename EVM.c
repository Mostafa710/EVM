#define F_CPU 8000000UL
#include <util/delay.h>
#include "BUTTON.h"
#include "LCD.h"

unsigned char counter1,counter2,counter3,counter4;

int main(void)
{
	BUTTON_init('D',0);
	BUTTON_init('D',1);
	BUTTON_init('D',2);
	BUTTON_init('D',3);
	BUTTON_init('D',4);
	LCD_init();
	LCD_send_string("A=0");
	LCD_move_cursor(1,13);
	LCD_send_string("B=0");
	LCD_move_cursor(2,1);
	LCD_send_string("C=0");
	LCD_move_cursor(2,13);
	LCD_send_string("D=0");
    while(1)
    {
		if(BUTTON_read('D',0)==1)
		{
			counter1++;
			if(counter1<10)
			{
				LCD_move_cursor(1,3);
				LCD_send_char(counter1+48);
			}
			else
			{
				LCD_move_cursor(1,3);
				LCD_send_char((counter1/10)+48);
				LCD_send_char((counter1%10)+48);
			}
			_delay_ms(250);
		}
		else if(BUTTON_read('D',1)==1)
		{
			counter2++;
			if(counter2<10)
			{
				LCD_move_cursor(1,15);
				LCD_send_char(counter2+48);
			}
			else
			{
				LCD_move_cursor(1,15);
				LCD_send_char((counter2/10)+48);
				LCD_send_char((counter2%10)+48);
			}
			_delay_ms(250);
		}
		else if(BUTTON_read('D',2)==1)
		{
			counter3++;
			if(counter3<10)
			{
				LCD_move_cursor(2,3);
				LCD_send_char(counter3+48);
			}
			else
			{
				LCD_move_cursor(2,3);
				LCD_send_char((counter3/10)+48);
				LCD_send_char((counter3%10)+48);
			}
			_delay_ms(250);
		}
		else if(BUTTON_read('D',3)==1)
		{
			counter4++;
			if(counter4<10)
			{
				LCD_move_cursor(2,15);
				LCD_send_char(counter4+48);
			}
			else
			{
				LCD_move_cursor(2,15);
				LCD_send_char((counter4/10)+48);
				LCD_send_char((counter4%10)+48);
			}
			_delay_ms(250);
		}
		else if(BUTTON_read('D',4)==1)
		{
			counter1=counter2=counter3=counter4=0;
			LCD_clear_screen();
			LCD_send_string("A=0");
			LCD_move_cursor(1,13);
			LCD_send_string("B=0");
			LCD_move_cursor(2,1);
			LCD_send_string("C=0");
			LCD_move_cursor(2,13);
			LCD_send_string("D=0");
			_delay_ms(250);
		}
    }
}