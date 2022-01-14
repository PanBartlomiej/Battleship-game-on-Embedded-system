// Plik odpowiedzialny za rysowanie planszy i statków
// Ustawianie 
#include "PIN_LPC17xx.h"                // Keil::Device:PIN
#include "Open1768_LCD.h"
#include "LCD_ILI9325.h"
#include "asciiLib.h"
#include "TP_Open1768.h"
#include "LPC17xx.h"                    // Device header
#include "GPDMA_LPC17xx.h"              // Keil::Device:GPDMA
#include <stdlib.h>
#include "TP_config.h"
#define KTO_PIERWSZY 55
#ifndef PLANSZA
#define PLANSZA

void inicjalizacja_plansz();
void rysuj_linie(const int x1, const int y1, const int x2, const int y2, uint16_t col);
void rysuj_kwadrat(int kolor,int x,int y, int szer);
void rysuj_plansze();
void rysuj_plansze(char tab_statki[12][12]);
void LCD_to_index(int *x, int *y);
int wybor_statku();
void rysuj_rodzaje_statkow();
void uzupelnanie_moich_statow();

#endif