#include "game.h"

extern std::vector<tankData>data;

void load(){
    
  
   std::ifstream f("gameData.pkg", std::ios::in | std::ios::binary);
   if(f.is_open()){
   
   	while(f){
       tankData td(f);
       data.push_back(td);
   	}  
   f.close(); 
   }
   
   
}

void save(){
     
}
