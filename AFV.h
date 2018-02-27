#include<windows.h>

#include "coord.h"
#include "color.h"
#include "ploter.h"

#ifndef AFV_H
#define AFV_H

class AFV{
 
protected:
           
  coord c;
  color Color;
  
  int face;
  int dataIndex;
  int index;
  int markStat;
  
  ploter * hull;
  
  char order;
  
  bool alive;
  bool isMoving;
  bool IsMobile;
  bool placed;
  
  void create();
  
public:

  virtual void shotPos(int) = 0;  
  virtual int gtTurFace() = 0;
  virtual void display(HDC, DWORD) = 0;
  virtual void place(int,int,int) = 0;
  virtual void setAngle(int) = 0;     

  
  void setNAngle(int a){face = a;}
  void setColor(DWORD c){Color.set(c);}
  void setColor(int r,int g,int b){Color.set(r,b,b);}
  void setStat(int s){markStat = s;}
  void setOrder(char o){order = o;}
  void setLoc(int, int); 
  void setDefault();   
  void place(){placed = true;}
  void imobilize(){IsMobile = false;}
  void kill(){alive = false;}
    
  int gtStat(){return markStat;}
  int gtFace(){return face;}
  int gtDBI(){return dataIndex;}
  int gtIndex(){return index;}

  bool gtLoc(int, int); 
  bool isAlive(){return alive;} 
  bool gtOrder(char o);
  bool isPlaced(){return placed;}
  bool isMobile(){return IsMobile;}
 
  char gtOrder(){return order;}
  
  coord gtCoord(){return c;}
  
  
  //void AtkPos(int);


  //void setLoc(coord&);
  //coord gtLoc();
              
};

#endif
