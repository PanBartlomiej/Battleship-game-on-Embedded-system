#include "PIN_LPC17xx.h"                // Keil::Device:PIN
#include "GPIO_LPC17xx.h"               // Keil::Device:GPIO
#include "RTE_Device.h"                 // Keil::Device:Startup
#include "RTE_Components.h"             // Component selection
#include "LPC17xx.h"                    // Device header
#include "GPDMA_LPC17xx.h"              // Keil::Device:GPDMA
#include "Board_LED.h"                  // ::Board Support:LED
#include "Open1768_LCD.h"
#include "LCD_ILI9325.h"
#include "asciiLib.h"
#include "TP_Open1768.h"
#include <stdlib.h>

void caly_ekran(int kolor){
	//int kolor=LCDBlueSea;
	lcdSetCursor(0,0);
	lcdWriteIndex(DATA_RAM);
	for(int i=0; i<320; i++){
		for(int j=0; j<240; j++)
			{//kolor+=1;
			lcdWriteData(kolor);}
	}
}

void litera(int x0, int y0, char a){
	//ASCII_8X16_MS_Gothic 0
	unsigned char pBuffer[16];
	GetASCIICode(0,pBuffer,a);
	
	//lcdSetCursor(10,10);
	
	for(int i=0; i<16; i++){
		lcdSetCursor(x0,y0+i);
		lcdWriteIndex(DATA_RAM);
		for(int j=8; j>=0; j--){
			if(pBuffer[i] & (1 << j))
				lcdWriteData(LCDRed);
			else
				lcdWriteData(LCDWhite);
			//if(pBuffer[i] & 1)
				
		}
	}
}
void napis(int x0, int y0, char* text, int size){
	for(int i=0; i<size; i++){
		litera(x0+(i*8),y0,text[i]);
	}
}

volatile bool flaga = 0;

int X = 0;
int Y = 0;

void EINT3_IRQHandler(void){

	flaga = !flaga;
	int avgX = 0;
	int avgY = 0;
	for(int i=0; i<10; i++){  ////tu wiadomo srednia
		touchpanelGetXY(&X, &Y);
		avgX += X;
		avgY += Y;
	}
	X = avgX / 10;
	Y = avgY / 10;

	LPC_GPIOINT->IO0IntClr = 1 << 19;
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
/*
double k_X;
double k_Y;

void kalibracja(){
	// 240 x 320 LCD_MAX_X LCD_MAX_Y
	
	rysuj_X(10,LCD_MAX_Y - 10);
	while(flaga == 0);
	caly_ekran(LCDWhite);	// po kliknieciu X znika
	int X_10_10 = X;			// wartosci X i Y dla touchpada
	int Y_10_10 = Y;
	while(flaga == 1);
	
	rysuj_X(LCD_MAX_X - 10 ,LCD_MAX_Y - 10);
	while(flaga == 0);
	caly_ekran(LCDWhite);
	int X_230_10 = X;
	int Y_230_10 = Y;
	while(flaga == 1);
	
	rysuj_X(LCD_MAX_X -10 ,10);
	while(flaga == 0);
	caly_ekran(LCDWhite);
	int X_10_310 = X;
	int Y_10_310 = Y;
	while(flaga == 1);
	
	//int Y_tp = Y_10_310 - Y_10_10;
	//int Y_LCD = 300;
	//k = (double)Y_LCD/(double)Y_tp;
	
	k_X = 230.0 / Y_230_10;
	k_Y = 310.0 / X_10_310;
	
}
*/

int X_1, X_2, Y_1, Y_2;

void kalibracja(){
	// 240 x 320 LCD_MAX_X LCD_MAX_Y
	
	rysuj_X(10,LCD_MAX_Y - 10);
	while(flaga == 0);
	caly_ekran(LCDWhite);	// po kliknieciu X znika
	X_1 = Y;		// wartosci X i Y dla touchpada
	while(flaga == 1);
	
	rysuj_X(LCD_MAX_X - 10 ,LCD_MAX_Y - 10);
	while(flaga == 0);
	caly_ekran(LCDWhite);
	X_2 = Y;
	Y_1 = X;
	while(flaga == 1);
	
	rysuj_X(LCD_MAX_X -10 ,10);
	while(flaga == 0);
	caly_ekran(LCDWhite);
	Y_2 = X;
	while(flaga == 1);
	
	
}

void touchpad_to_LCD_XY(){
	X = (20 - LCD_MAX_X) * X / (X_1 - X_2) + 10 - X_1 * (20 - LCD_MAX_X) / (X_1 - X_2);
	Y = (20 - LCD_MAX_Y) * Y / (Y_1 - Y_2) + 10 - Y_1 * (20 - LCD_MAX_Y) / (Y_1 - Y_2);
	
}


void UART_konfiguracja(){
	// UART
	PIN_Configure(0,2,1,0,0);
  PIN_Configure(0,3,1,0,0);

  LPC_UART0->LCR = (1<<7) | (3);
  LPC_UART0->DLL = 13;
  LPC_UART0->DLM = 0;
  LPC_UART0->FDR = 1 | (15<<4);
  LPC_UART0->LCR = 3;
}

void wypisz(char* tab, int size){
	for(unsigned int i=0; i<size; i++){
        while (!(LPC_UART0->LSR & (1 << 5)))
            ;
        LPC_UART0->THR = tab[i];
	}
}

int main()
{

	UART_konfiguracja();
	
	// przerwanie LCD
	lcdConfiguration();
	init_ILI9325();
	touchpanelInit();
	
	LPC_GPIOINT->IO0IntEnF = 1 << 19;
	NVIC_EnableIRQ(EINT3_IRQn);
	
	
	caly_ekran(LCDWhite);
	kalibracja();
	
	char strx[6];
	char stry[6];
	
	
	while(1){
		
		while(flaga == 0);
			touchpad_to_LCD_XY();
			napis(X,Y,"a",1);
			sprintf(strx,"X=%d",(int)(X));
			sprintf(stry,"Y=%d",(int)(Y));
			wypisz(strx,6);
			wypisz(" ",1);
			wypisz(stry,6);
		  wypisz(" ",1);
		while(flaga == 1);
		caly_ekran(LCDWhite);

	}
		
}