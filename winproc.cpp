#include<windows.h>

#include "game.h"

using namespace std;

extern int rCnt;

extern std::vector<tankData>data;
extern std::vector<h_AFV>AFVs;

extern std::vector<mvOrder>moveOrders;
extern std::vector<atOrder>attackOrders;
extern std::vector<atOrder>OverwatchOrders;

extern control * manage;

enum phase{placement, orders, fire, resolve, overwatch, ffire, moral};
extern phase Phase;


LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){
  
  HINSTANCE hInstance;
  HWND exit;
  HWND next;
             
  switch (msg){  
  
  
    case WM_CREATE:
         
         exit = CreateWindow("Button", "Quit",
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                1150, 820, 70, 20, hwnd, (HMENU) 1, hInstance, NULL);
                
         next = CreateWindow("Button", "Done",
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                1150, 800, 70, 20, hwnd, (HMENU) 2, hInstance, NULL);

         setup(hwnd); 
            
     
    break;
   
  case WM_PAINT:{
       
      PAINTSTRUCT ps; 
      HDC hdc;
      hdc = BeginPaint(hwnd, &ps);     
        paint(hdc);
      EndPaint(hwnd, &ps);   
   }  
   break;
  
  	case WM_KEYDOWN:
   
   break;
        
    case WM_COMMAND:    
      commands(hwnd, msg, wp, lp);  
      if(LOWORD(wp)== 1){ //quits game
         quit();
         SendMessage(GetParent((HWND) lp), WM_DESTROY, 0, 0);}
      
      if(LOWORD(wp) == 2){   
      
         switch(Phase){
         	
         	case placement:
         		
         		manage->done();   

				    for(std::vector<h_AFV>::iterator itr = AFVs.begin();  
				    	itr != AFVs.end(); itr++){
						
						if((!itr->isPlaced()) && (data[itr->gtDBI()].gtCntry() == manage->gtCurrent())){
								MessageBox(NULL, "Not all Tanks Placed", "Warning!", MB_OK);
							    return 0;
						}
					}
				   		
 				if(manage->allDone()){
 					Phase = orders;
 					manage->swap();
 					manage->reset();
 					resetOrders();
 					
				 }else{ 
				 	manage->swap();
				 }		    	
        		InvalidateRect(hwnd,NULL,TRUE);       		
         	break;
         	     	
            case orders:  
         		manage->done();
         		
 				if(manage->allDone()){

 					
 					if(attackOrders.size() == 0){Phase = resolve;
					 }else{Phase = fire;}
					 
					 
 					manage->swap();
 					manage->reset();
				
				 }else{ 
				 	manage->swap();
				 }
		    	manage->stCurrentTank(-1);
        		InvalidateRect(hwnd,NULL,TRUE);  

            return 0;
         
            case fire:
            	
         		manage->done();
				         		
         		 for(std::vector<atOrder>::iterator itr = attackOrders.begin();
						itr != attackOrders.end(); itr++){					
						if((itr->dfLn == -1) && (data[itr->atDB].gtCntry() == manage->gtCurrent())){
							MessageBox(NULL, "A Tank Lacks a Target", "Warning!", MB_OK);
							return 0;						
						}
					}
					        		
 				if(manage->allDone()){
 					Phase = resolve;
 					manage->swap();
 					manage->reset();
				
				 }else{ 
				 	manage->swap();
				 	manage->stCurrentTank(-1);
				 }            	

               InvalidateRect(hwnd,NULL,TRUE);     
            
         
            return 0;
         
            case resolve:    
            	
            	resolveFire(hwnd);
                 
                resolveMove();
            
				rCnt = 20;
				if(attackOrders.size() > 0){
				if (FAILED(DialogBox(GetModuleHandle(NULL),
       				MAKEINTRESOURCE(IDD_RESULTS), hwnd, resultsProc))){ 
       				MessageBox(NULL, "Box Failed!", "Error!", MB_OK);}	                
           		}
                					
				moveOrders.clear();
				attackOrders.clear();
                	
				if(OverwatchOrders.size() == 0){
					Phase = moral;
				}else{				
					Phase = overwatch;						
				}
				
				//manage->swap();
 				//manage->reset();
            	
                InvalidateRect(hwnd,NULL,FALSE);      
				 

            return 0;
          
            case overwatch:
            		
         		manage->done();
				         		
         		 for(std::vector<atOrder>::iterator itr = OverwatchOrders.begin();
						itr != OverwatchOrders.end(); itr++){					
						if((itr->dfLn == -1) && (data[itr->atDB].gtCntry() == manage->gtCurrent())){
							MessageBox(NULL, "A Tank Lacks a Target", "Warning!", MB_OK);
							return 0;						
						}
					}

 				if(manage->allDone()){
 					Phase = ffire;
 					manage->swap();
 					manage->reset();
				
				 }else{ 
				 	manage->swap();
				 	manage->stCurrentTank(-1);
				 }     
				 
                InvalidateRect(hwnd,NULL,FALSE);  				
            
            return 0;
                        
            case ffire:

            	resolveOFire(hwnd);
				rCnt = 20;				
				
				if(OverwatchOrders.size() > 0){
				if (FAILED(DialogBox(GetModuleHandle(NULL),
       				MAKEINTRESOURCE(IDD_RESULTS), hwnd, resultsProc2))){ 
       				MessageBox(NULL, "Box Failed!", "Error!", MB_OK);}	                
           		}
                
                for(std::vector<h_AFV>::iterator itr = AFVs.begin();
					itr != AFVs.end(); itr++){
						
						itr->setStat(0);
						
					}
					
                for(std::vector<h_AFV>::iterator itr = AFVs.begin();
					itr != AFVs.end(); itr++){
						
						itr->setStat(0);
						
					}
					
				OverwatchOrders.clear();
				
				//manage->swap();
 				//manage->reset();
				            	
            	Phase = moral;
                InvalidateRect(hwnd,NULL,FALSE);   
           	
            return 0;
            	
         
            case moral:
            	
            	char ply1 = manage->gtPlayer1();
            	char ply2 = manage->gtPlayer2();
            	bool pl1lost = true;
            	bool pl2lost = true;
            	
            	for(std::vector<h_AFV>::iterator itr = AFVs.begin();
            		itr != AFVs.end(); itr++){            			
            			if((itr->isAlive()) && (data[itr->gtDBI()].gtCntry() == ply1)){ pl1lost = false;}
            			if((itr->isAlive()) && (data[itr->gtDBI()].gtCntry() == ply2)){ pl2lost = false;}            			         			
						}
				 if(pl1lost){
				 	MessageBox(NULL, "Player 1 has beeb defeated", "Game Over", MB_OK);
				 	PostQuitMessage (0);
				 }
				 
				 if(pl2lost){
				 	MessageBox(NULL, "Player 2 has beeb defeated", "Game Over", MB_OK);
				 	PostQuitMessage (0);			 	
				 }
				 
                for(std::vector<h_AFV>::iterator itr = AFVs.begin();
					itr != AFVs.end(); itr++){
						
						itr->setStat(0);
						
					}				 

            	Phase = orders;
            	
            	manage->chooseInit();
                InvalidateRect(hwnd,NULL,FALSE);
                
            return 0;   
         }       
      } 
    
   break;   
    
   case WM_LBUTTONDOWN:    
   
         switch(Phase){
         	
         	case placement:{

         		
         		std::vector<h_AFV>::iterator itr = AFVs.begin();
         		
         		while(itr->isPlaced()){
					itr++;
					if(itr >= AFVs.end()){
					   MessageBox(NULL, "All Tanks Placed", "Warning!",MB_OK);
					   return 0;
					}
				}

         		if(data[itr->gtDBI()].gtCntry() == manage->gtCurrent()){
				 
				 	if(!placeTank(itr, LOWORD(lp), HIWORD(lp))){
         				MessageBox(NULL,"Incorrect Placement","Warnimg!", MB_OK);  // demo output			   			
						}else{
							itr->place(); 
				 		}
				}else{
				 			
				 	MessageBox(NULL, "All Tanks Placed", "Warning!",MB_OK);
				} 
				
				bool allPlaced = true;
								
				for(std::vector<h_AFV>::iterator itr = AFVs.begin();
					itr != AFVs.end(); itr++){
						if(data[itr->gtDBI()].gtCntry() == manage->gtCurrent()){
							if(!itr->isPlaced()){

								allPlaced = false;															
							}
						}						
					}
				
				if(allPlaced){					
					manage->done();

 					if(manage->allDone()){
						Phase = orders;
 						manage->swap();
 						manage->reset();
 						resetOrders();
				
					 }else{ 
				 		manage->swap();;
				 	}  					
					
					
				}								
					
					InvalidateRect(hwnd,NULL,TRUE); 
         	}
         	break;
         	
         	
            case orders:{

            	
            	int t= isTank(LOWORD(lp), HIWORD(lp));
            	manage->stCurrentTank(t);
					
            	if(t >= 0){ 
            		int n = AFVs[manage->gtCurrentTank()].gtDBI();
					if(data[n].gtCntry() == manage->gtCurrent()){
						
						if(AFVs[manage->gtCurrentTank()].gtMarked() != 0){
							MessageBox(NULL, "Tanks already has Orders!", "Warning!", MB_OK);
							return 0;					
						}
	
						if (FAILED(DialogBox(GetModuleHandle(NULL),
                   			MAKEINTRESOURCE(IDD_ORDERS), hwnd, ordersProc))){ 
                 			MessageBox(NULL, "Box Failed!", "Error!", MB_OK);}      
                 			manage->stCurrentTank(-1);
					}	
				}	
				
				bool allOrders = true;	
				//check if all tanks have orders then if so advance the turn	
				
				for(std::vector<h_AFV>::iterator itr = AFVs.begin();
					itr != AFVs.end(); itr++){
						if(data[itr->gtDBI()].gtCntry() == manage->gtCurrent()){
							if(itr->gtMarked() == 0){

								allOrders = false;
															
							}
						}
						
					}
				
				if(allOrders){
					
					manage->done();

 					if(manage->allDone()){
 					if(attackOrders.size() == 0){Phase = resolve;}
					    else{Phase = fire;}
 						manage->swap();
 						manage->reset();
				
					 }else{ 
				 		manage->swap();
				 		manage->stCurrentTank(-1);
				 	}  					
					
					
				}

               InvalidateRect(hwnd,NULL,FALSE); 
			}
			       	
            return 0;
              
        	case fire:{
	
 				if(manage->gtCurrentTank() == -1){
			
            		int t = isTank(LOWORD(lp), HIWORD(lp));
            		if(t == -1){return  0;}
            		if(data[AFVs[t].gtDBI()].gtCntry() != manage->gtCurrent()){return 0;}		
					manage->stCurrentTank(t);
            		for(std::vector<atOrder>::iterator itr = attackOrders.begin();
					itr != attackOrders.end(); itr++){
						if(itr->atLn == t){						
							 InvalidateRect(hwnd,NULL,TRUE); 								
						}					
					}
				} else {
										
					int t2 = isTank(LOWORD(lp), HIWORD(lp));						
					if(t2 == -1){return 0;}
				
					for(std::vector<atOrder>::iterator itr = attackOrders.begin();
						itr != attackOrders.end(); itr++){
						
							if(itr->atLn == manage->gtCurrentTank()){
								if(!itr->addTarget(t2)){
									
									MessageBox(NULL, "Invalid Target", "Info.", MB_OK);
									InvalidateRect(hwnd,NULL,TRUE); 
									
								}  else {
								
									InvalidateRect(hwnd,NULL,TRUE); 	
									manage->stCurrentTank(-1);
								}																
							}	
						}		
				}
			}
        	break;
            
        	case resolve:
        		

        	break;
        	
        	case overwatch:{			
			
			if(manage->gtCurrentTank() == -1){
			
            		int t = isTank(LOWORD(lp), HIWORD(lp));
            		if(t == -1){return  0;}
            		if(data[AFVs[t].gtDBI()].gtCntry() != manage->gtCurrent()){return 0;}		
					manage->stCurrentTank(t);
            		for(std::vector<atOrder>::iterator itr = OverwatchOrders.begin();
					itr != OverwatchOrders.end(); itr++){
						if(itr->atLn == t){						
							 InvalidateRect(hwnd,NULL,TRUE); 								
						}					
					}
				} else {
										
					int t2 = isTank(LOWORD(lp), HIWORD(lp));						
					if(t2 == -1){return 0;}
				
					for(std::vector<atOrder>::iterator itr = OverwatchOrders.begin();
						itr != OverwatchOrders.end(); itr++){
						
							if(itr->atLn == manage->gtCurrentTank()){
								if(!itr->addTarget(t2)){
									
									MessageBox(NULL, "Invalid Target", "Info.", MB_OK);
									InvalidateRect(hwnd,NULL,TRUE); 
									
								}  else {
								
									InvalidateRect(hwnd,NULL,TRUE); 	
									manage->stCurrentTank(-1);
								}																
							}	
						}			
				}
			}		
        	break;
        	      
            return 0;      
         
      

   }
           
   break;

   case WM_RBUTTONDOWN:
     PostQuitMessage (0);
   break;
   
   case WM_DESTROY:
     PostQuitMessage (0);

   break;
   default:         
     return DefWindowProc (hwnd, msg, wp, lp);
    
   }

  return 0;                                                                   
} 

