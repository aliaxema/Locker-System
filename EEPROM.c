/*
 * EEPROM.c
 *
 * Created: 18-Aug-22 11:36:01 PM
 *  Author: lenovo
 */ 
#include "EEPROM.h"

uint8_t EEPROM_read(uint16_t addr)
{
	 while(READBIT(EECR,EEWE) == 1){}
	 EEAR = addr;
	 SETBIT(EECR,EERE);
	 return EEDR;
}

void EEPROM_write(uint16_t addr,uint8_t data)
{
	while(READBIT(EECR,EEWE) == 1){}
		EEAR = addr;
		EEDR = data;
		SETBIT(EECR,EEMWE);
		SETBIT(EECR,EEWE);
		
}