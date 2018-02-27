#include "orders.h"



mvOrder::mvOrder(h_AFV * pAFV, int d, int s, bool a){
 
   pMover = new h_AFV(*pAFV);

   azmuth = d;
   speed = s;
   align = a;
}      

mvOrder::mvOrder(const mvOrder& o){  
  
  //if(pMover){pMover = NULL;}
  pMover = new h_AFV(*o.pMover);                 
  azmuth = o.azmuth;
  speed = o.speed;
  align = o.align;                          
}  

mvOrder::~mvOrder(){
   if(pMover){delete pMover;}                               
}   

void mvOrder::resolve(){
	/*
    int rate = speed * .01;

    int dir = pMover->gtFace() * .0174532925;   
    int DBI = pMover->gtDBI();
    int MaxSpd = data[DBI].gtRdSpeed();
    int spd = rate * MaxSpd;
    int dist = spd;
    coord c = pMover->gtCoord(); 
    float tx = c.Xloc;
    float ty = c.Yloc;
    tx += (float)dist*(sin(dir));
    ty -= (float)dist*(cos(dir));
    int nx = tx;
    int ny = ty;
    pMover->setLoc(nx, ny);
    if(align){pMover->setAngle(dir);}
      else{pMover->setNAngle(dir);}    
	  */
}          
                 

shOrder::shOrder(){
   //pAttacker = new h_AFV();
   //pDefender = new h_AFV();
                   
}

shOrder::shOrder(h_AFV * p){
   //pAttacker = p;
   //pDefender = new h_AFV();
}

shOrder::shOrder(const shOrder& o) {
    //if(pAttacker){pAttacker = new h_AFV(*o.pAttacker);}
   // if(pDefender){pDefender = new h_AFV(*o.pDefender);}
                  
}       

shOrder::~shOrder(){
  //if(pAttacker){delete pAttacker;}
  //if(pDefender){delete pDefender;}     
}                    
                                                       
 
