#include "uart_conf.h"
volatile bool flaga =0 ;

volatile int X =0;
volatile int Y =0;

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

void wyslij_info(const uint8_t info)
{
	while (!(LPC_UART0->LSR & (1 << 5)))
		;
	LPC_UART0->THR = info;
}

void czekaj_na_potwierdzenie()
{
	while (LPC_UART0->RBR != CONFIG_READY)
		;
}

void czytaj_info(uint8_t *info)
{
	do
	{
		*info = LPC_UART0->RBR;
	} while (*info == 0);
}