#include "TP_config.h"


void EINT3_IRQHandler(void){

	int x_touch,y_touch;
	flaga = !flaga;
	int avgX = 0;
	int avgY = 0;
	for(int i=0; i<5; i++){  ////tu wiadomo srednia
		do{
			touchpanelGetXY(&y_touch, &x_touch);
		}while(y_touch<100 || x_touch >4000 );
		avgX += x_touch;
		avgY += y_touch;
	}
	X = avgX / 5;
	Y = avgY / 5;

	LPC_GPIOINT->IO0IntClr = 1 << 19;
	NVIC_EnableIRQ(EINT3_IRQn);
}

void rysuj_X(int x, int y){
	lcdSetCursor(x-3,y);
	lcdWriteIndex(DATA_RAM);
	for(int i=7; i<14; i++)
		lcdWriteData(LCDRed);
	
	for(int i=0; i<8; i++){
		lcdSetCursor(x,y-3+i);
		lcdWriteIndex(DATA_RAM);
		lcdWriteData(LCDRed);
	}
	
	lcdSetCursor(x,y);
	lcdWriteIndex(DATA_RAM);
	lcdWriteData(LCDBlue);
	
}

int X_1, X_2, Y_1, Y_2;

void kalibracja(){
	// 240 x 320 LCD_MAX_X LCD_MAX_Y
	int odc =40; //odciecie
	rysuj_X(odc,LCD_MAX_Y - odc);
	while(flaga == 0);
	caly_ekran(LCDWhite);	// po kliknieciu X znika
	X_1 = X;		// wartosci X i Y dla touchpada
	while(flaga == 1);
	
	rysuj_X(LCD_MAX_X - odc ,LCD_MAX_Y - odc);
	while(flaga == 0);
	caly_ekran(LCDWhite);
	X_2 = X;
	Y_1 = Y;
	while(flaga == 1);
	
	rysuj_X(LCD_MAX_X -odc ,odc);
	while(flaga == 0);
	caly_ekran(LCDWhite);
	Y_2 = Y;
	while(flaga == 1);
	
	
}

void touchpad_to_LCD_XY(){
	int odc=40;
	X =		(int) ((2*odc - LCD_MAX_X) * X / (double)(X_1 - X_2) + odc - X_1 * (2*odc - LCD_MAX_X) / (double)(X_1 - X_2));
	Y = (int)((2*odc - LCD_MAX_Y) * Y / (double)(Y_2 - Y_1) + odc - Y_2 * (2*odc - LCD_MAX_Y) / (double)(Y_2 - Y_1));
	
}
