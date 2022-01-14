#include "plansza.h"
#define START 30
#define STOP 40
#define JEST_DOBRZE 50
#define NIE_JEST_DOBRZE 60
#define TRAFIONY 70
#define NIE_TRAFIONY 80
#ifndef GRA
#define GRA

extern bool tura ;
extern char moje_statki[12][12];       // '0' - pusto, '1' - statek, '?' - nie sprawdzone pole
extern char statki_przeciwnika[12][12];


int strzelaj();
void strzelanie();
int czekaj_na_strzal();

#endif
