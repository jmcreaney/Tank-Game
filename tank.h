#include "ploter.h"
#include "color.h"
#include "AFV.h"

#ifndef TANK_H
#define TANK_H

class tank : public AFV{

   ploter * turret;    
   int turFace;
   
   void create();
      
public:
       
   tank();
   tank(int);
   tank(int, int, int, int);
   
   void place(int,int,int);
   void display(HDC, DWORD);
   void setAngle(int);
   void shotPos(int);
   int gtTurFace(){return turFace;}
            
};

#endif
