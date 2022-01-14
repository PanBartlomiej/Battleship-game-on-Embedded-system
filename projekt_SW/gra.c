#include "gra.h"
int liczba_pol=20; // liczba pól do trafienia 
// żeby jakoś zakończyć grę


//dodałem do strzelania że zwraca flage po strzale
int strzelaj(){
// zwraca 1 jesli trafione
//        0 jeśli nietrafione
//        2 jeśli coś poszło totalnie źle
//          (nie powinno wgle tego zwrócić)
  int x = 1;
  int y = 2;
  uint8_t info;
	uint8_t czy_trafiony;
	do {
    while(flaga==0);
    touchpad_to_LCD_XY();
    x=X;
    y=Y;
    LCD_to_index(&x,&y);
    while(flaga==1);
	}while( x>0 && x<11 && y>0 && y<11);

  do{
    wyslij_info(START);
    wyslij_info(x);
    wyslij_info(y);
    wyslij_info(STOP);
		czytaj_info(&info);
  }while(info!=JEST_DOBRZE);
		
	czytaj_info(&czy_trafiony);

	if(czy_trafiony ==TRAFIONY){
	  statki_przeciwnika[x][y]='1';
    liczba_pol--;
    return 1;
	}
	else if(czy_trafiony == NIE_TRAFIONY){
	  statki_przeciwnika[x][y] = '0';
    return 0;
	}
	return 2;
}

//funkcja obsługuję całą ture osoby strzelającej
//
void strzelanie(){
//strzela i  jak trafia to jeszcze raz
  int tempo;
  do{
    tempo=strzelaj();
    rysuj_plansze( statki_przeciwnika );
    if(liczba_pol==0){
      napis(100,100,"WYGRAŁEŚ !",10);
      break ;
    }
  }while(tempo == 1 );
  
}

//funckja obsługuję całą logikę tury czekania na strzał
// odbiera sygnał  sprawdza czy mój statek został TRAFIONY
// jeśli tak to wysyłam sygnał że zostaliśmy trafieni 
// i czekamy na kolejne strzały jeśli nie zostaliśmy trafieni
// to wysyłamy sygnał że nie trafiliśmy 
// i już nie nasłuchujemy ( wychodzimy z pętli)

int czekaj_na_strzal(){
  int ilosc_trafien = 0;
	uint8_t start, stop;
	uint8_t x_s;
	uint8_t y_s;
  int czy_trafiony ;
  do{
      do{
        czytaj_info(&start);
      }while(start!=START);

    czytaj_info(&x_s);
    czytaj_info(&y_s);	

    do{
      czytaj_info(&stop);
    }while(stop!=STOP);

    wyslij_info(JEST_DOBRZE);
    napis(100,100,"TURA PRZECIWNIKA",16);
    
    if(moje_statki[x_s][y_s] == 1){
      wyslij_info(TRAFIONY);
      czy_trafiony =TRAFIONY;
      ilosc_trafien++;
    }
    else if(moje_statki[x_s][y_s == 0]){
      wyslij_info(NIE_TRAFIONY);
      czy_trafiony =NIE_TRAFIONY;
    }
  }while(czy_trafiony == TRAFIONY);

  rysuj_plansze(statki_przeciwnika);
  return ilosc_trafien;
}