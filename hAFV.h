#include "AFV.h"
#include "tank.h"
#include "spGun.h"

#ifndef HAFV_H
#define HAFV_H

class h_AFV{

   AFV * pAFV;   
   int * cnt;
   
   friend class AFV;

   int tnkData;
   
   
public:  
         
   h_AFV();
   h_AFV(int);
   h_AFV(int, int, int, int);   
   h_AFV(const h_AFV& afv) : cnt(afv.cnt), pAFV(afv.pAFV){++*cnt;}
   h_AFV& operator = (const h_AFV&);
  ~h_AFV(); 
  
  void create(int, int, int, int);
  
  void display(HDC hdc, DWORD c){pAFV->display(hdc, c);}
  void shotPos(int n){pAFV->shotPos(n);} 
  
  void setAngle(int a){pAFV->setAngle(a);} 
  void setNAngle(int a){pAFV->setNAngle(a);}   
  void setColor(DWORD c){pAFV->setColor(c);}
  void setColor(int r,int g,int b){pAFV->setColor(r,b,b);}
  void setStat(int s){pAFV->setStat(s);}
  void setOrder(char o){pAFV->setOrder(o);}
  void setLoc(int x, int y){pAFV->setLoc(x, y);}
  void setDefault(){pAFV->setDefault();}  
  void place(int x, int y, int f){pAFV->place(x,y,f);}
  void place(){pAFV->place();}
  void kill(){pAFV->kill();}
  int gtMarked(){return pAFV->gtStat();}
  int gtFace(){return pAFV->gtFace();}
  int gtTurFace(){return pAFV->gtTurFace();}
  int gtLoc(int x, int y){pAFV->gtLoc(x, y);}
  int gtDBI(){return pAFV->gtDBI();}
  int gtFacing(){return pAFV->gtFace();}
  int gtIndex(){return pAFV->gtIndex();} 
   
  
  bool isAlive(){return pAFV->isAlive();}
  coord gtCoord(){return pAFV->gtCoord();}
  bool isPlaced(){return pAFV->isPlaced();}
  bool isMobile(){return pAFV->isMobile();}
      
};

#endif
