#include "PIN_LPC17xx.h"                // Keil::Device:PIN
#include "Open1768_LCD.h"
#include "LCD_ILI9325.h"
#include "asciiLib.h"
#include "TP_Open1768.h"
#include "LPC17xx.h"                    // Device header
#include "GPDMA_LPC17xx.h"              // Keil::Device:GPDMA
#include <stdlib.h>
#ifndef UART_CONFIG
#define UART_CONFIG

void wypisz(char* tab, int size);
void litera(int x0, int y0, char a);
void napis(int x0, int y0, char* text, int size);
void UART_konfiguracja();
void caly_ekran(int kolor);
void wyslij_info(const uint8_t info);
void czekaj_na_potwierdzenie();
void czytaj_info(uint8_t *info);

#endif

/* 
  gracz 1 - wysyła X i Y 
  gracz 2 - nasłuchuje - otrzymuje
            sprawdza, czy trafiony
            wysyła odpowiedz
            nie trafiony - zmiana flagi tury na 1
            trafiony - bez zmian flagi
  gracz 1 - nasłuchuje odpowiedzi
            nie trafiony - zmiana flagi tury na 0
            trafiony -  bez zmian flagi


*/