#include <iostream>
#include "gunStat.h"

#ifndef GUN_H
#define GUN_H

class gun{
       
   std::string name;
   std::string country;
   
   gunStat * stats;   
   void create();
   char cntry;
   
   int gtRange(int);
   
   static const int ranges = 13;
   
public:
       
   gun(std::string&);
   gun(std::ifstream&);
   gun(const gun&);
   gun(std::string, std::ifstream&);
  ~gun(); 
   void input(int, int, int, int);
   
   std::string gtName();
   
   void gtCntry(char c){cntry = c;}
   char Cntry(){return cntry;}
   
   void load(std::ifstream&); 
   void save(std::ofstream&);
   
   int gtHitRoll(int);
   int gtPenitrate(int);
   

};

#endif

