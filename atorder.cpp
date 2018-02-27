#include<vector>

#include "atorder.h"
#include "mvorder.h"
#include "tankdata.h"
#include "hAFV.h"


extern std::vector<tankData>data;
extern std::vector<h_AFV>AFVs;


atOrder::atOrder(int i){
	
	atLn = i;
	atDB = AFVs[atLn].gtDBI();
	cntry = data[atDB].gtCntry();
	dfLn = -1;
	hit = false;
	pen = false;
	imb = false;
			
}

bool atOrder::addTarget(int i){
		
	if(data[AFVs[i].gtDBI()].gtCntry() == data[atDB].gtCntry()){
		return false;		
	}
	
	dfLn = i;
	dfDB = AFVs[dfLn].gtDBI();
	
	return true;	
}

mvOrder::mvOrder(int l, int d, int s, bool a){
		
		lnNumber = l;
		direction = d;
		speed = s;
		align = a;
		
		DBI = AFVs[lnNumber].gtDBI();		
}

void mvOrder::resolve(){
	
	
    float rate = speed * .01;  
    float dir = direction * .0174532925;

 	int DBI = AFVs[lnNumber].gtDBI();
 	
  	if(align){AFVs[lnNumber].setAngle(direction);}
      else{AFVs[lnNumber].setNAngle(direction);} 
 	
    int MaxSpd = data[DBI].gtRdSpeed();

    float dist = rate * MaxSpd;
    coord c = AFVs[lnNumber].gtCoord(); 
    float tx = c.Xloc;
    float ty = c.Yloc;
    tx += (float)dist*(sin(dir));
    ty -= (float)dist*(cos(dir));
    int nx = tx;
    int ny = ty;
    AFVs[lnNumber].setLoc(nx, ny);    
}   
