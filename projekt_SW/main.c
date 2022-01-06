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

#include "TP_config.h"
#include "uart_conf.h"
#include "plansza.h"


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
	
rysuj_plansze();
	while(1){
		
		while(flaga == 0);
			sprintf(strx,"X_nie=%d",(int)(X));
			sprintf(stry,"Y_nie=%d",(int)(Y));
			wypisz(strx,10);
			wypisz(" ",1);
			wypisz(stry,10);
		  wypisz("  ",2);
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