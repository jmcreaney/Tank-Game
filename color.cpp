#include "color.h"

color::color(){
  colorCode = 0;
}

color::color(DWORD code){
  colorCode = code;
}

color::color(int r, int g, int b){
  colorCode = RGB(r, g, b);
}

void color::set(int r, int g, int b){
 colorCode = RGB(r, g, b);
}

void color::set(DWORD code){
 colorCode = code;
}

void color::doBg(HDC hdc){
  SetBkColor(hdc,colorCode);
}

void color::doColor(HDC hdc){ 
  SetTextColor(hdc,colorCode);
}
