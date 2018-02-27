#include "spgun.h"
#include "tankData.h"
#include "coord.h"

extern std::vector<tankData>data;

spGun::spGun(){}

spGun::spGun(int i){

   dataIndex = i;
   placed = false;
   create();
}

spGun::spGun(int i, int x, int y, int n){
                                    
     dataIndex = i;
     index = n;
     c.Xloc = x;
     c.Yloc = y;
     
     face = 0;   
     markStat = 0;     
     create();    
}
                
void spGun::create(){
     
     std::ifstream f1("spg.txt", std::ios::in);  
     hull = new ploter(f1);  
     f1.close(); 
    IsMobile = true;
    alive = true;
}

void spGun::display(HDC hdc,  DWORD mk){
   
  if(alive){
  	hull->setAngle(face);
  	hull->display(hdc,c.Xloc,c.Yloc,Color);  
  
  	SetTextColor(hdc,mk);
  
  	TextOut(hdc, c.Xloc +10, c.Yloc-25,data[dataIndex].gtNameC(), 
          data[dataIndex].gtNameLen());     
  }
}

void spGun::shotPos(int p){
	
	face = p;
     
}

void spGun::place(int x, int y, int f){
	
	c.Xloc = x;
	c.Yloc = y;
	
	face = f;
	
}
      
