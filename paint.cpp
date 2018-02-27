#include<windows.h>
#include "game.h"

extern std::vector<tankData>data;
extern std::vector<h_AFV>AFVs;
extern std::vector<atOrder>attackOrders;
extern std::vector<atOrder>OverwatchOrders;
extern colorStruct colors;
extern control * manage;


const char * PhaseStr[4] = {"Placement", "Orders", " Fire","Resolution" "Overwatch"};
enum phase{placement, orders, fire, resolve, overwatch, ffire, moral};
extern phase Phase;

void paint(HDC hdc){
 
     RECT board = {0,0,1100,840};
     HBRUSH grBrush = CreateSolidBrush(colors.Ground.getCode());
     DWORD mkColor;

     FillRect(hdc,&board,grBrush);
    	
    switch(Phase){ 
     	
     	case placement:{
     		mkColor = colors.markDefault.getCode();	
     		for(std::vector<h_AFV>::iterator itr = AFVs.begin(); 
	 			itr != AFVs.end(); itr++){
	 				
	 				if((itr->isPlaced()) && (data[itr->gtDBI()].gtCntry() == manage->gtCurrent())){
	 					itr->display(hdc,mkColor);					
					 }	
			}
		}
		break;
		 
		 default:{

		      for(std::vector<h_AFV>::iterator itr = AFVs.begin(); 
	 			itr != AFVs.end(); itr++){
	 			if(itr->isPlaced()){
					if(!itr->isMobile()){mkColor = colors.markImob.getCode();} 		
     				if(itr->gtMarked() == 0){mkColor = colors.markDefault.getCode();}
         			if(itr->gtMarked() == 1){mkColor = colors.markSelect.getCode();}
         			if(itr->gtMarked() == 2){mkColor = colors.markFire.getCode();}	
         			if(itr->gtMarked() == 3){mkColor = colors.markOW.getCode();}
					 					 		     	
	 				itr->display(hdc,mkColor);						 	 
		 		} 
		 	} 
		}
		 break;	
	}	
     
     char cnt = manage->gtCurrent();
        
     colors.markDefault.doColor(hdc);
     
     if(cnt == 'a'){TextOut(hdc, 1150,25, "American", 8);}
     if(cnt == 'b'){TextOut(hdc, 1150,25, "British ", 8);} 
     if(cnt == 'g'){TextOut(hdc, 1150,25, "German  ", 8);}   
     if(cnt == 'r'){TextOut(hdc, 1150,25, "Soviet  ", 8);}   
     
   
     switch(Phase){ 
     
     	case placement:{
		
     		TextOut(hdc,1125,10, "Tank Placement     ",17);
     		int count = 45;
         	for(std::vector<h_AFV>::iterator itr = AFVs.begin();
			 	itr != AFVs.end(); itr++){
			 		char c = data[itr->gtDBI()].gtCntry();
			 		if(((manage->gtCurrent()) == c) && (!itr->isPlaced())){
				 			TextOut(hdc, 1115, count, data[itr->gtDBI()].gtNameC(), data[itr->gtDBI()].gtNameLen());
				 			count = count + 15;
					 }								 		
				 }
     	}
     	break;  
     
        case orders:
             TextOut(hdc, 1125,10, "Select Orders   ", 17); 
        break;
        
        case fire:
            TextOut(hdc, 1125,10, "Select Targets   ", 17);
           
 			if(manage->gtCurrentTank() != -1){
            for(std::vector<atOrder>::iterator itr = attackOrders.begin();
				itr != attackOrders.end(); itr++){
					if(itr->atLn == manage->gtCurrentTank()){
						TextOut(hdc, 1125,45, data[itr->atDB].gtNameC(), data[itr->atDB].gtNameLen());				
					}	
				}
			}
		
        break;
        
        case resolve:
        	
        	TextOut(hdc, 1125,10, "Resolution        ", 17);
        	
        break;
        
        case overwatch:
             TextOut(hdc, 1125,10, "Sel OW Targets   ", 17);   
           
 			if(manage->gtCurrentTank() != -1){
            for(std::vector<atOrder>::iterator itr = OverwatchOrders.begin();
				itr != OverwatchOrders.end(); itr++){
					if(itr->atLn == manage->gtCurrentTank()){
						TextOut(hdc, 1125,45, data[itr->atDB].gtNameC(), data[itr->atDB].gtNameLen());				
					}	
				}
			}

        break; 
		
		case ffire:
        	
        	TextOut(hdc, 1125,10, "OW Resolution   ", 17);
        	
        break;    
      }  
	       
        DeleteObject(grBrush);           
}
