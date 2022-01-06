#include "uart_conf.h"

#ifndef TP_CONFIG
#define TP_CONFIG

extern volatile bool flaga ;

extern volatile int X ;
extern volatile int Y ;

void EINT3_IRQHandler(void);
void rysuj_X(int x, int y);
void kalibracja();
void touchpad_to_LCD_XY();
#endif