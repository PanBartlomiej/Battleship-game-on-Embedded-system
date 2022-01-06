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
#ifndef PLANSZA
#define PLANSZA

char moje_statki[12][12];       // '0' - pusto, '1' - statek, '?' - nie sprawdzone pole
char statki_przciwnika[12][12];

void inicjalizacja_plansz();
void rysuj_linie(const int x1, const int y1, const int x2, const int y2, uint16_t col);
void rysuj_kwadrat(int kolor,int x,int y );
void rysuj_plansze();

void LCD_to_index(int *x, int *y)
int wybor_statku();
void rysuj_rodzaje_statkow()
void uzupelnanie_moich_statow();

#endif