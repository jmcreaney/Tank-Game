#include "AFV.h"
#include "tank.h"
#include "tankData.h"

extern std::vector<tankData>data;

tank::tank(){}

tank::tank(int i){

  	dataIndex = i;
  	placed = false;
  	face = 0;        
    turFace = 0;
  	create();
}

tank::tank(int i, int x, int y, int n){
               
     dataIndex = i;
     index = n;
     c.Xloc = x;
     c.Yloc = y;
     
     face = 0;        
     turFace = 0;
     markStat = 0;  
     create();                  

}


void tank::create(){
    
   std::ifstream f1("tnk.txt", std::ios::in);
   hull = new ploter(f1);    
   f1.close();  
   std::ifstream f2("tur.txt", std::ios::in);
   turret = new ploter(f2);
   f2.close(); 
   
   IsMobile = true;
   alive = true;
}

void tank::display(HDC hdc, DWORD mk){

   
   if(alive){
   	hull->setAngle(face);
   	turret->setAngle(turFace);
   	hull->display(hdc, c.Xloc, c.Yloc, Color);
   	turret->display(hdc, c.Xloc, c.Yloc, Color);
   
   	SetTextColor(hdc,mk);
   
    
  	TextOut(hdc,c.Xloc + 10, c.Yloc - 25, data[dataIndex].gtNameC(), 
           data[dataIndex].gtNameLen());
   }
}

void tank::setAngle(int a){
   face = a;
   turFace = a;    
}

void tank::shotPos(int p){
	
	turFace = p;
     
} 

void tank::place(int x, int y, int f){
	
	c.Xloc = x;
	c.Yloc = y;
	
	face = f;
	turFace = f;
	
}


