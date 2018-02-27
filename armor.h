#include <fstream>

#ifndef ARMOR_H
#define ARMOR_H

struct armor{
   int fnt;
   int fnt45;
   int sde;
   int sde45;
   int rear;
   int rear45;
   
   
   void load(std::ifstream& F){
   	
   	F >> fnt;
   	F >> fnt45;
   	F >> sde;
   	F >> sde45;
   	F >> rear;
   	F >> rear45;
   }
   
};

#endif
