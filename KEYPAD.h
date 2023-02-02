/*
 * KEYPAD.h
 *
 * Created: 8/13/2022 11:18:53 AM
 *  Author: safifi
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "std_macros.h"

#define INIT_KEYPAD_PIN 	                   \
							DDRD = 0b11110000; \
							PORTD = 0b1111;
#define K0 READBIT(PIND,0)
#define K1 READBIT(PIND,1)
#define K2 READBIT(PIND,2)
#define K3 READBIT(PIND,3)
#define K4(x) if(x == 1) SETBIT(PORTD,4); else CLRBIT(PORTD,4);
#define K5(x) if(x == 1) SETBIT(PORTD,5); else CLRBIT(PORTD,5);
#define K6(x) if(x == 1) SETBIT(PORTD,6); else CLRBIT(PORTD,6);
#define K7(x) if(x == 1) SETBIT(PORTD,7); else CLRBIT(PORTD,7);

void KEYPAD_init(void);
uint8_t KEYPAD_read(void);



#endif /* KEYPAD_H_ */