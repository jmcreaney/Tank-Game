#include "game.h"

#include "hAFV.h"

#ifndef ORDERS_H
#define ORDERS_H

struct shOrder{

   h_AFV * pAttacker;
   h_AFV * pDefender; 
   
   shOrder();
   shOrder(h_AFV*);
   shOrder(const shOrder&);
   ~shOrder();
       
};

struct mvOrder{
   h_AFV * pMover;   
   
   int azmuth;
   int speed;
   bool align;   
   
   mvOrder();
   mvOrder(h_AFV*, int, int, bool);
   mvOrder(const mvOrder&);
   ~mvOrder();
   void resolve();
};

#endif
