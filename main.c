/*
 * Locker_system1.c
 *
 * Created: 31-Aug-22 10:55:51 PM
 * Author : lenovo
 */ 

#include "LCD.h"
#include "EEPROM.h"
#include "KEYPAD.h"

uint8_t get_key();
void write_value_on_LCD(void);
void change_password(void);
void func(void);
void reset_pass();

uint8_t num[4] = {'0','0','0','0'};
uint8_t x1=48 ,x2=48,x3=48,x4=48;
int main(void)
{
	SETBIT(DDRB,0); //output of the led on portb
	LCD_init();
	KEYPAD_init();
    write_value_on_LCD();
	check_on_value();
    while (1) 
    {
		func();
		uint8_t v = get_key();
		if( v!=0 && v!='*'&& v != 'c')
		{
			
			write_value_on_LCD();
			check_on_value();
			
		}
    }
}
uint8_t get_key()
{
	uint8_t key;
	key = KEYPAD_read();
	while(key==0)
	{
		key=KEYPAD_read();
	}
	//LCD_write_char(key);
	while(KEYPAD_read()==key);
	return key;
}
void write_value_on_LCD(void)
{	 uint8_t i =0;
	while (i<4){
		uint8_t value = get_key() ;
		if(value != 0)
		{
			SETBIT(PORTB,0);
			LCD_write_char('*');
			
			_delay_ms(30);
			CLRBIT(PORTB,0);
			num[i]=value;
			i++; 
		}
	}
	
	i=0;
	
	
}
 void check_on_value(void)
 {
	 uint8_t val = get_key();
	 if(val == 'c')
	 {
		 
		 if (num[0] ==x1 && num[1] ==x2 && num[2]==x3 && num[3] == x4 )
		 {
			 LCD_write_command(0x01);
			 LCD_write_string("locker opened");
		/*	 if (get_key()=='0')
			 {
				 reset_pass();
			 }
			*/
			 if (get_key()=='*')
			 {
				 LCD_write_command(0x01);
			 }
			 
		 }
		 
		 else
		 {
			 LCD_write_command(0x01);
			 LCD_write_string("try again");
			 SETBIT(PORTB,0);
			 _delay_ms(100);
			 CLRBIT(PORTB,0);
			 LCD_write_command(0x01);
			 write_value_on_LCD();
			 check_on_value();
			 uint8_t v=get_key();
			 if (v=='*')
			 {
				 LCD_write_command(0x01);
			 }
		 }
		 
	 }
 }
 void change_password(void)
 {
	 uint8_t i =0;
	 //uint8_t value = KEYPAD_read();
	 uint8_t num1[4]={0,0,0,0};
	 LCD_write_command(0x01);
	 SETBIT(PORTB,0);
	 _delay_ms(100);
	 CLRBIT(PORTB,0);
	 while (i<4){
		 uint8_t value = KEYPAD_read() ;
		 
		 if(value!=0)
		 {
			 LCD_write_char(value);
			 SETBIT(PORTB,0);
			 _delay_ms(30);
			 CLRBIT(PORTB,0);
			 num1[i]=value;
			 i++;
			 
		 }
		 
	 }
	 x1=(num1[0]),x2=(num1[1]),x3=(num1[2]),x4=(num1[3]);
	 EEPROM_write(0,x1),EEPROM_write(1,x2),EEPROM_write(2,x3),EEPROM_write(3,x4);
	 //LCD_write_char(x1),LCD_write_char(x2),LCD_write_char(x3),LCD_write_char(x4);
	 
	 i=0;
 }
 void func(void)
 {
	 uint8_t v = KEYPAD_read();
	 
	 if (v == '\\')
	 {
		 change_password();
		 if (get_key()=='\\')
		 {
			 LCD_write_command(0x01);
			 LCD_write_string("Success");
			 _delay_ms(10);
			 LCD_write_command(0x01);
		 }
		 //  check_on_value();
	 }
 }
void reset_pass()
{
	
	uint8_t i=0,flag = 0 ;
	uint8_t arr1[11] = {0,0,0,0,0,0,0,0,0,0},arr2[11];
	
		LCD_write_command(0x01);
		LCD_write_command(0x0c);
		uint8_t key = get_key();
		while(i<10){
			if (key!=0)
			{
				arr2[i]=key;
			}
			i++;
		}
		for(uint8_t j = 0;j<10;j++)
		{
			if (arr1[j]==arr2[j])
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			x1=48,x2=48,x3=48,x4=48;
			LCD_write_command(0x01);
			LCD_write_string("Password reset");
		}
		
	
}