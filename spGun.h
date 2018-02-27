#include "ploter.h"
#include "color.h"
#include "AFV.h"


#ifndef SPGUN_H
#define SPGUN_H


class spGun : public AFV{
  
  
   void create();
   
public:
   
   spGun();    
   spGun(int);
   spGun(int, int, int, int);
   
   void place(int,int,int);
   void display(HDC, DWORD);
   void setAngle(int a){face = a;}
   void shotPos(int);
   int gtTurFace(){return face;}
};

#endif
