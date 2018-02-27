#include "coord.h"

coord::coord(){
   Xloc = 0;
   Yloc = 0;

}

coord::coord(int x, int y){
   Xloc = x;
   Yloc = y;
}

coord& coord::operator = (const coord &c){
	Xloc = c.Xloc;
	Yloc = c.Yloc;
	return *this;
} 

bool coord::operator == (coord &c){
   bool eq = false;
   if((Xloc == c.Xloc) && (Yloc == c.Yloc)){eq = true;}
   return eq;    
     
}   

           
   
