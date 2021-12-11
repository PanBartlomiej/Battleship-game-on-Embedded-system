

char moje_statki[12][12];       // '0' - pusto, '1' - statek
char statki_przciwnika[10][10];

for(int i=0 ;i<12; i++)
  for(int j=0; j<12; j++)
    moje_statki[i][j]='0';

// (20,20), (220,220) przekatne  200 x 200 - całość; 20 x 20 - jedna pozycja  

void touch_to_index(int *x, int *y){
  // X, Y -> x_id, y_id
  // sprawdzenie czy jest poza planszą
  *x = (*x-20)/20 + 1;
  *y = (*y-20)/20 + 1;
}

void touch_to_LCD(int *x, int *y){
  // z kalibracji
}

void rysuj_statek(int X_LCD, int Y_LCD){
  // rysowanie 
}
void rysuj_rodzaje_statkow()
{
  x1= 240 // każdy;
}
int wybor_statku(){
  // pobiera warość kliknięcia
  // zamienia ją na pozycje jednego ze statków do wyboru
  // pozycje znajduą się w funckji rysuj statki
  // zwraca numer statku
}
void uzupelnanie_moich_statow(){
  // x_id, y_id - odnosi sie do indeksów tabeli moje_statki
  // x_id góra dół ( a,b,c,d...)
  // y_id lewo prawo ( 0,1,2,3,4...)

    
  rysuj_rodzaje_statkow();
  int postawione_statki[4] = {4,3,2,1}; // wszystkie statki postawione - {0,0,0,0}

  // while wstawić do main, a funkcja uzupelnanie_moich_statow(int X, int Y)
  // zawartość whila dać do tej funkcji  uzupelnanie_moich_statow(int X, int Y)
  while(postawione_statki[0]==0 && postawione_statki[1]==0 && postawione_statki[2] ==0 && postawione_statki[3] == 0){
    // wybór rodzaju statku
    // wybór miejsca
    int stawiany_statek = 0;  // wyświetlimy poniżej do wyboru
    // 1 - 4m_pion
    // 2 - 4m_poziom
    // 3 - 3m_pion
    // 4 - 3m_poziom
    // 5 - 2m_pion
    // 6 - 2m_poziom
    // 7 - 1m
 
    stawiany_statek = wybor_statku(); // zwraca warość wybranego statku
    // wybór_miejsca // X, Y -> X_LCD, Y_LCD -> x_id, y_id
    
    while(flaga == 0);
      // przypisanie nowych X i Y (w przerwaniu) 
	  while(flaga == 1);

    // int x_LCD = X, y_LCD = Y; // do rysuj_statek
    // int x_id = X, y_id = Y; // do zapisywania w tablicy

    // touch_to_index(&x_id,&y_id);
    //touch_to_LCD(&x_LCD,&y_LCD);
    bool dobre_miejce = 1;
    switch(stawiany_statek){
      case 1:{

          if(x>7 || postawione_statki[3] == 0){
            wypisz("nie możesz tu statku dać ")
            dobre_miejsce = 0;  
          }
          else{
            for(int i= x_id-1; i<=x_id+4;i++){
              for(int j= y_id-1; j<=y_id+1;j++){
                if(moje_statki[i][j] == '1'){
                  dobre_miejsce = 0;
                  break;
                }
              }
            }
            if(dobre_miejsce = 1){
              moje_statki[x_id][y_id]  ='1';  rysuj_statek(x_LCD,y_LCD);
              moje_statki[x_id+1][y_id]='1';  rysuj_statek(x_LCD+1,y_LCD);
              moje_statki[x_id+2][y_id]='1';  rysuj_statek(x_LCD+2,y_LCD);
              moje_statki[x_id+3][y_id]='1';  rysuj_statek(x_LCD+3,y_LCD);
              postawione_statki[3]--;
              // rysuj_statek(x,y)
            }
          }
        break;
      }
      case 2:{
          if(y>7 || postawione_statki[3] == 0){
            wypisz("nie możesz tu statku dać ")
            dobre_miejsce = 0;  
          }
          else{
            for(int i= x_id-1; i<=x_id+1;i++){
              for(int j= y_id-1; j<=y_id+4;j++){
                if(moje_statki[i][j] == '1'){
                  dobre_miejsce = 0;
                  break;
                }
              }
            }
            if(dobre_miejsce = 1){
              moje_statki[x_id][y_id]  ='1';  rysuj_statek(x_LCD,y_LCD);
              moje_statki[x_id][y_id+1]='1';  rysuj_statek(x_LCD,y_LCD+1);
              moje_statki[x_id][y_id+2]='1';  rysuj_statek(x_LCD,y_LCD+2);
              moje_statki[x_id][y_id+3]='1';  rysuj_statek(x_LCD,y_LCD+3);
              postawione_statki[3]--;
            }
          }
        break;
      }
      case 3:{
          if(x>8 || postawione_statki[2] == 0){
            wypisz("nie możesz tu statku dać ")
            dobre_miejsce = 0;  
          }
          else{
            for(int i= x_id-1; i<=x_id+3;i++){
              for(int j= y_id-1; j<=y_id+1;j++){
                if(moje_statki[i][j] == '1'){
                  dobre_miejsce = 0;
                  break;
                }
              }
            }
            if(dobre_miejsce = 1){
              moje_statki[x_id][y_id]  ='1';  rysuj_statek(x_LCD,y_LCD);
              moje_statki[x_id+1][y_id]='1';  rysuj_statek(x_LCD+1,y_LCD);
              moje_statki[x_id+2][y_id]='1';  rysuj_statek(x_LCD+2,y_LCD);
              postawione_statki[2]--;
            }
          }
        break;
      }
          case 4:{
          if(y>8 || postawione_statki[2] == 0){
            wypisz("nie możesz tu statku dać ")
            dobre_miejsce = 0;  
          }
          else{
            for(int i= x_id-1; i<=x_id+1;i++){
              for(int j= y_id-1; j<=y_id+3;j++){
                if(moje_statki[i][j] == '1'){
                  dobre_miejsce = 0;
                  break;
                }
              }
            }
            if(dobre_miejsce = 1){
              moje_statki[x_id][y_id]  ='1';  rysuj_statek(x_LCD,y_LCD);
              moje_statki[x_id][y_id+1]='1';  rysuj_statek(x_LCD,y_LCD+1);
              moje_statki[x_id][y_id+2]='1';  rysuj_statek(x_LCD,y_LCD+2);
              postawione_statki[2]--;
            }
          }
        break;
      }
    }
      case 5:{
          if(x>9 || postawione_statki[1] == 0){
            wypisz("nie możesz tu statku dać ")
            dobre_miejsce = 0;  
          }
          else{
            for(int i= x_id-1; i<=x_id+2;i++){
              for(int j= y_id-1; j<=y_id+1;j++){
                if(moje_statki[i][j] == '1'){
                  dobre_miejsce = 0;
                  break;
                }
              }
            }
            if(dobre_miejsce = 1){
              moje_statki[x_id][y_id]  ='1';  rysuj_statek(x_LCD,y_LCD);
              moje_statki[x_id+1][y_id]='1';  rysuj_statek(x_LCD+1,y_LCD);

              postawione_statki[1]--;
            }
          }
        break;
      }
    case 6:{
      if(y>9 || postawione_statki[1] == 0){
        wypisz("nie możesz tu statku dać ")
        dobre_miejsce = 0;  
      }
      else{
        for(int i= x_id-1; i<=x_id+1;i++){
          for(int j= y_id-1; j<=y_id+2;j++){
            if(moje_statki[i][j] == '1'){
              dobre_miejsce = 0;
                break;
            }
          }

        }
        if(dobre_miejsce = 1){
          moje_statki[x_id][y_id]  ='1';  rysuj_statek(x_LCD,y_LCD);
          moje_statki[x_id][y_id+1]='1';  rysuj_statek(x_LCD,y_LCD+1);
          postawione_statki[1]--;
        }
      }
      break;
    }  
      case 7:{
          if(x>10 || postawione_statki[0] == 0){
            wypisz("nie możesz tu statku dać ")
            dobre_miejsce = 0;  
          }
          else{
            for(int i= x_id-1; i<=x_id+1;i++)
              for(int j= y_id-1; j<=y_id+1;j++)
                if(moje_statki[i][j] == '1'){
                  dobre_miejsce = 0;
                  break;
                }
            if(dobre_miejsce = 1){
              moje_statki[x_id][y_id]  ='1';  rysuj_statek(x_LCD,y_LCD);
              postawione_statki[0]--;
            }
          }
        break;
      }
      rysuj_plansze();

  }
}

for(int i=1 ;i<12; i++)
  for(int j=1; j<12; j++)
    if(moje_statki[i][j]=='1')
      rysuj_kwadrat(kolor,10*2*i,10*2*j)



void rysuj_kwadrat(int kolor,int x,int y ){
	
	lcdSetCursor(x,y);
	lcdWriteIndex(DATA_RAM);
lcdSetCursor(x,y);		for(int j=0 ; j< 10; j++)		lcdWriteData(kolor);
lcdSetCursor(x,y+9);	for(int j=0 ; j< 10; j++)		lcdWriteData(kolor);				
	
	for(int i=1; i<9; i++){	
		lcdSetCursor(x+i,y);lcdWriteData(kolor);
		lcdSetCursor(x+i,y+9);lcdWriteData(kolor);
			}
}
