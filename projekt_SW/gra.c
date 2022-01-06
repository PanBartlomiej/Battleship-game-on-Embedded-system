
void strzelaj(){
int x;
int y;
uint8_t info;
while(flaga==0);
  touchpad_to_LCD_XY();
  LCD_to_index(&x,&y);
while(flaga==1);

  do{
    wyslij_info(START);
    wyslij_info(x);
    wyslij_info(y);
    wyslij_info(STOP);
    czytaj_info(&info);
  }while(info!=JEST_DOBRZE)

}

void czekaj_na_strzal(){

uint8_t info;
czytaj_info(&info);
if(info==START){//jest dobrze;

  czytaj_info(&info);
  czytaj_info(&info);

  czytaj_info(&info);
  if(info==STOP){
    wyslij_info(JEST_DOBRZE);
  }
}
else{
  wyslij_info(NIE_JEST_DOBRZE);
}
}