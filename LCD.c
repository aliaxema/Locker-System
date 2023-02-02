/*
 * LCD_Q1.c
 *
 * Created: 17-Aug-22 2:57:13 PM
 *  Author: lenovo
 */ 
#include "LCD.h"
/*****************************************************************************
* Function Name: LCD_init
* Purpose      : Init lcd in 4 bit mode, clear lcd and turn off cursor
* Parameters   : void
* Return value : void
*****************************************************************************/

void LCD_init(void)
{
	LCD_init_Pins;
	/*we are going to make the usual configuration of the lcd for the 4-bit mode of operation by 
	using the data sheet we have and configure the pins by using the write command and data so
	1. we will add 0x03 3 times and have a delay of 4 ms 
	2. enable 4-bit mode by sending 0x02 command,
	4. Send command (0x28) 
	5. Send command (0x08) 
	6. Send command (0x01) to clear LCD 
	7. Send command (0x06) to make cursor increment to right 
	8. Send command (0x0C) to turn on the display
	9. Wait 20 millisecond.
	*//*
	for(int i =0;i<3;i++)
	{
		
}*/
	LCD_write_command(0x03);
	_delay_ms(4);
	LCD_write_command(0x03);
	_delay_ms(4);
	LCD_write_command(0x03);
	_delay_ms(4);
	LCD_write_command(0x02);
	LCD_write_command(0x28);//enable write on both lines
	LCD_write_command(0x08);//turn on cursor
	LCD_write_command(0x01); //to clear LCD 
	LCD_write_command(0x06);//to make cursor increment to right 
	LCD_write_command(0x0C);// to turn on the display
	_delay_ms(20);
	
}

/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : write command to LCD
* Parameters   : data: one of LCD commands
* Return value : void
*****************************************************************************/

void LCD_write_command(uint8_t data)
{
	RS(0);
	D7(READBIT(data,7)); // Data bit7  = D7
	D6(READBIT(data,6)); // Data bit6  = D6
	D5(READBIT(data,5)); // Data bit5  = D5
	D4(READBIT(data,4)); // Data bit4  = D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);

	D7(READBIT(data,3)); // Data bit3  = D7
	D6(READBIT(data,2)); // Data bit2  = D6
	D5(READBIT(data,1)); // Data bit1  = D5
	D4(READBIT(data,0)); // Data bit0  = D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}
/*****************************************************************************
* Function Name: LCD_write_char
* Purpose      : write data to LCD
* Parameters   : data: one of LCD commands
* Return value : void
*****************************************************************************/
void LCD_write_char(uint8_t data)
{
	RS(1);
	D7(READBIT(data,7)); // Data bit7  = D7
	D6(READBIT(data,6)); // Data bit6  = D6
	D5(READBIT(data,5)); // Data bit5  = D5
	D4(READBIT(data,4)); // Data bit4  = D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);

	D7(READBIT(data,3)); // Data bit3  = D7
	D6(READBIT(data,2)); // Data bit2  = D6
	D5(READBIT(data,1)); // Data bit1  = D5
	D4(READBIT(data,0)); // Data bit0  = D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}
/*****************************************************************************
* Function Name: LCD_write_string
* Purpose      : write a lone of srting on LCD
* Parameters   : *data: one of LCD commands
* Return value : void
*****************************************************************************/
void LCD_write_string(uint8_t *data)
{
	int8_t i =0;
	while(data[i]!='\0')
	{
		LCD_write_char(data[i]);
		i++;
	}
	
}
void LCD_write_num(uint16_t data)
{
	int8_t i=0;
	uint8_t arr[10];
	if(data==0)
	{
		LCD_write_char('0');
	}
	for(i=0;data!=0;i++)
	{
		arr[i]= data % 10 + 48;
		data/=10;
	}
	i--; //used for starting of the first number to print
	while(i>=0) //it is not !=0 because of the first number could be in 0 so it won't enter the loop!
	{
		LCD_write_char(arr[i]);
		i--;
	}
	
	
}