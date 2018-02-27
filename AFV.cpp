#include "AFV.h"

bool AFV::gtLoc(int ac, int dw){
 
   bool compare = false;
   
   if((c.Xloc == ac) && (c.Yloc == dw)){compare = true;}
   return compare; 
}

bool AFV::gtOrder(char o){
     bool is = false;
     if(order == o)is = true;
     return is;
}


void AFV::setLoc(int x, int y){
   c.Xloc = x;
   c.Yloc = y;  
     
}

void AFV::setDefault(){
     
     markStat = 0; 
     order = 'x';     
}




