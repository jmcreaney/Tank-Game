#include "game.h"
#include "hAFV.h"
#include "coord.h"
/*
extern control * manage;
extern std::vector<h_AFV>AFVs;
extern std::vector<tankData>data;

extern std::vector<atOrder>attackOrders;
extern std::vector<atOrder>OverwatchOrders;


void resolveFire(HWND hwnd){
	
	
	for(int ff = 0; ff != 12; ff++){
		for(std::vector<atOrder>::iterator itr = attackOrders.begin();
			itr != attackOrders.end(); itr++){
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
	}			
}

void resolveOFire(HWND hwnd){
	
	for(int ff = 0; ff != 12; ff++){
		for(std::vector<atOrder>::iterator itr = OverwatchOrders.begin();
			itr != OverwatchOrders.end(); itr++){
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
	}			
}


*/
