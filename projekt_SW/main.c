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
#include "gra.h"

extern bool tura ;
extern char moje_statki[12][12];
extern char statki_przciwnika[12][12];

int main()
{
  int moje_nietrafione_statki = 20;
  char str[21];

	UART_konfiguracja();
	
	// przerwanie LCD
	lcdConfiguration();
	init_ILI9325();
	touchpanelInit();
	
	LPC_GPIOINT->IO0IntEnF = 1 << 19;
	NVIC_EnableIRQ(EINT3_IRQn);
	
	caly_ekran(LCDWhite);
	kalibracja();
	
	inicjalizacja_plansz();

	uzupelnanie_moich_statow();

  caly_ekran(LCDWhite);
  rysuj_plansze(statki_przeciwnika);
  
	while(1){
		if(tura){
      napis(240,20,"Twój ruch       ",16);
		  strzelanie();
			tura = !tura;
		}
		else{
      napis(240,20,"Tura przeciwnika",16);
		  moje_nietrafione_statki -= czekaj_na_strzal();
		  tura = !tura;
      if(moje_nietrafione_statki==0){
        napis(100,100,"PRZEGRAŁEŚ",10)
        break;
      }
      else{
        sprintf(str,"zostalo mi %d statków",moje_nietrafione_statki);
        napis(270,20,str,21);
      }
		}
	}
	while(1);
}