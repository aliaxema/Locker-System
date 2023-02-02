/*
 * EEPROM.h
 *
 * Created: 18-Aug-22 11:35:22 PM
 *  Author: lenovo
 */ 

#include "std_macros.h"
#ifndef EEPROM_H_
#define EEPROM_H_
uint8_t EEPROM_read(uint16_t addr);

void EEPROM_write(uint16_t addr,uint8_t data);




#endif /* EEPROM_H_ */