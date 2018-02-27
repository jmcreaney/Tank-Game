#include<windows.h>

#ifndef COLOR_H
#define COLOR_H

class color{
  DWORD colorCode;
  
public:
  color();
  color(int, int, int);
  color(DWORD);
  DWORD getCode(){return colorCode;}
  void set(int, int, int); //changes the color
  void set(DWORD); //changes with a DWORD
  void doBg(HDC); //Displays the color as a blackground color
  void doColor(HDC); //Deisplays the color as a forground color
};

#endif
