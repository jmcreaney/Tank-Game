#include "game.h"
#include "hAFV.h"
#include "coord.h"

extern control * manage;
extern std::vector<h_AFV>AFVs;
extern std::vector<tankData>data;

extern std::vector<mvOrder>moveOrders;
extern std::vector<atOrder>attackOrders;
extern std::vector<atOrder>OverwatchOrders;

int roll(int n){
    
    srand (time(NULL));
    
    int total = 0;
    for(int lp = 0; lp != n; lp++){
       total = total + (rand()%6)+1;
    }

    return total;
   
}

void quit(){  
  delete manage;
  //delete AI;
}


void makeTank(int n){
	
	h_AFV myAFV(n);
	AFVs.push_back(myAFV);
}

bool placeTank(std::vector<h_AFV>::iterator i, int x, int y){
	
	if(x < 10){ return false;}
	if(x > 1180){return false;}
	if(y < 10){return false;}
	if(y > 880){return false;}
	
	
	if(manage->gtWhoCurent() == 1){
		if(x < 900){return false;}
		i->place(x,y,0);
		i->setAngle(270);
	}
			
	if(manage->gtWhoCurent() == 2){
		if(x > 90){return false;}
		i->place(x,y,0);
		i->setAngle(90);
	}			
				
	return true;
}

int isTank(int x, int y){
	
	int count;
	
	for(int l2 = (y-10); l2 != (y+10); l2++){
		for(int l1 = (x-10); l1 != (x+10); l1++){
			count = 0;
			for(std::vector<h_AFV>::iterator itr = AFVs.begin()
				;itr != AFVs.end(); itr++){					
					if(itr->gtLoc(l1,l2)){return count;}			
					count++;
				}			
		}	
	}
	return -1;
}

void resetOrders(){
	
	for(std::vector<h_AFV>::iterator itr = AFVs.begin();
	itr != AFVs.end(); itr++){
		itr->setStat(0);
	}
}


void resolveFire(HWND hwnd){
	
	
	for(int ff = 0; ff != 12; ff++){
		for(std::vector<atOrder>::iterator itr = attackOrders.begin();
			itr != attackOrders.end(); itr++){
			
				x(hwnd, ff, itr);	
		}
	}
	
	// pull any destroyed tanks out of the overwatch orders.
	for(std::vector<atOrder>::iterator itr = attackOrders.begin();
		itr != attackOrders.end(); itr++){
			
		if(itr->pen){
			for(std::vector<atOrder>::iterator itro = OverwatchOrders.begin();
				itro != OverwatchOrders.end(); itr++){	
					
				if(itr->dfLn == itro->atLn){						
					OverwatchOrders.erase(itro);						
				}	
			}
		}				
	}			
}


void resolveOFire(HWND hwnd){
	
	for(int ff = 0; ff != 12; ff++){
		for(std::vector<atOrder>::iterator itr = OverwatchOrders.begin();
			itr != OverwatchOrders.end(); itr++){
			
				x(hwnd, ff, itr);
				
		}
	}
}

void resolveMove(){	
		for(std::vector<mvOrder>::iterator itr = moveOrders.begin();
			itr != moveOrders.end(); itr++){				
			itr->resolve();			
		}     
}   

int resDir(coord c1, coord c2){
	
 	int xp = c2.Xloc - c1.Xloc;
	int yp = c2.Yloc - c1.Yloc;
	
	if(xp == 0){xp = 1;}

	double r = atan2(yp,xp);

	int d = 90+(r * 57.2958);
	return d;
}

char gthtAngle(int d){
	
	char a;
	if((d > 330) && (d >= 0) && (d >= 30)){ a = 'a';}
	if((d > 31) && (d >= 60)){a = 'b';}
	if((d > 61) && (d >= 120)){a = 'c';}
	if((d > 121) && (d >= 150)){a = 'd';}
	if((d > 151) && (d >= 210)){a = 'e';}
	if((d > 211) && (d >= 240)){a = 'd';}
	if((d > 241) && (d >= 300)){a = 'c';}
	if((d > 301) && (d >= 329)){a = 'b';}
	
}


void x(HWND hwnd, int ff, std::vector<atOrder>::iterator& itr){
	
	if(data[itr->atDB].gtFFactor() == ff){
	
		if(AFVs[itr->atLn].isAlive()){
			
			coord atl = AFVs[itr->atLn].gtCoord();
			coord dfl = AFVs[itr->dfLn].gtCoord();
					
			int tr1 = abs(atl.Xloc - dfl.Xloc);
			int tr2 = abs(atl.Yloc - dfl.Yloc);					
			int dist = sqrt((tr1*tr1) + (tr2*tr2));			
						
						//dist = dist *4;		
			
			int hr = data[itr->atDB].gtHitRoll(dist);		
			int pen = data[itr->atDB].gtPenitrate(dist);		
						int dir = resDir(atl, dfl);
					
			AFVs[itr->atLn].shotPos(dir);
						
					
			int htRoll = roll(3);
			if(data[itr->dfDB].gtSize() == 'h'){htRoll =+ 2;}
			if(data[itr->dfDB].gtSize() == 'l'){htRoll =+ 1;}
			if(data[itr->dfDB].gtSize() == 's'){htRoll =- 1;}
			if(data[itr->dfDB].gtSize() == 'l'){htRoll =- 2;}
			if(data[itr->dfDB].gtSize() == 'a'){htRoll =- 3;}

			if(htRoll > hr){itr->hit =  true;}
								
			if(hr < 1){MessageBox(NULL, "out of Range", "Marker!", MB_OK);}
					
			if(itr->hit){
				int htLoc = roll(2);
				int tgAng;
				char l = gthtAngle(dir);
				int arm = 0;
						
				if(htLoc > 4){
					tgAng = dir + AFVs[itr->dfLn].gtTurFace();
					if(tgAng > 360){tgAng=-180;}
								
					if(htLoc == 2){
						switch(l){
							case 'a':
								arm = data[itr->dfDB].gtAFnt('t');
							break;
										
							case 'b':
								arm = data[itr->dfDB].gtAFnt45('t');
							break;
									
							case 'c':
								arm = data[itr->dfDB].gtASde('t');
							break;
										
							case 'd':
								arm = data[itr->dfDB].gtARear45('t');
							break;
										
							case 'e':
								arm = data[itr->dfDB].gtARear('t');
							break;
							}
						}
									
					if((htLoc == 3) || (htLoc == 4)){
						switch(l){
							case 'a':
								arm = data[itr->dfDB].gtAFnt('t');
							break;
							
							case 'b':
								arm = data[itr->dfDB].gtASde('t');
							break;
									
							case 'c':
								arm = data[itr->dfDB].gtASde('t');
							break;
									
							case 'd':
								arm = data[itr->dfDB].gtASde('t');
							break;
									
							case 'e':
								arm = data[itr->dfDB].gtARear('t');
							break;
							}									
					}

				}	else {						
								
					tgAng = dir + AFVs[itr->dfLn].gtFace();
					if(tgAng > 360){tgAng=-180;}
							
					if((htLoc == 5) || (htLoc == 6)){
						switch(l){
							case 'a':
								arm = data[itr->dfDB].gtAFnt('u');
							break;
										
							case 'b':
								arm = data[itr->dfDB].gtAFnt45('u');
							break;
										
							case 'c':
								arm = data[itr->dfDB].gtASde('u');
							break;
										
							case 'd':
								arm = data[itr->dfDB].gtARear45('u');
									break;
										
							case 'e':
								arm = data[itr->dfDB].gtARear('u');
							break;
							}									
						}

					if(htLoc == 7){
						switch(l){
							case 'a':
								arm = data[itr->dfDB].gtAFnt('u');
							break;
										
							case 'b':
								arm = data[itr->dfDB].gtASde('u');
							break;
										
							case 'c':
								arm = data[itr->dfDB].gtASde('u');
							break;
										
							case 'd':
								arm = data[itr->dfDB].gtASde('u');
							break;
										
							case 'e':
								arm = data[itr->dfDB].gtARear('u');
							break;
							}									
						}	
																	
					if(htLoc == 8){
						switch(l){
							case 'a':
								arm = data[itr->dfDB].gtAFnt('l');
							break;
										
							case 'b':
								arm = data[itr->dfDB].gtAFnt45('l');
							break;
										
							case 'c':
								arm = data[itr->dfDB].gtASde('l');
							break;
										
							case 'd':
								arm = data[itr->dfDB].gtASde45('l');
							break;
										
							case 'e':
								arm = data[itr->dfDB].gtARear('l');
							break;
							}
						}
								
					if((htLoc == 9) || (htLoc == 10)){
						switch(l){
							case 'a':
								arm = data[itr->dfDB].gtAFnt('l');
							break;
										
							case 'b':
								arm = data[itr->dfDB].gtAFnt45('l');
							break;
										
							case 'c':
								arm = data[itr->dfDB].gtASde('l');
							break;
										
							case 'd':
								arm = data[itr->dfDB].gtARear45('l');
							break;
										
							case 'e':
								arm = data[itr->dfDB].gtARear('l');
							break;
							}									
						}									
																	
					if((htLoc == 11) || (htLoc == 12)){
						switch(l){
							case 'a':
								arm = data[itr->dfDB].gtAFnt('s');
							break;
										
							case 'b':
								arm = data[itr->dfDB].gtASde45('s');
							break;
										
							case 'c':
								arm = data[itr->dfDB].gtASde('s');
							break;
										
							case 'd':
								arm = data[itr->dfDB].gtARear45('s');
							break;
										
							case 'e':
							arm = data[itr->dfDB].gtARear('s');
							break;
						}
					}																																				
				}
							
				if(pen > arm){	
					itr->pen = true;
					AFVs[itr->dfLn].kill();
				}							
							
			}
						
		}					
	}
}


