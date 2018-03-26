#include<windows.h>
#include<vector>
#include "game.h"

extern std::vector<atOrder>attackOrders;
extern std::vector<atOrder>OverwatchOrders;
extern int rCnt;

BOOL CALLBACK resultsProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){ 


  switch(msg){
              
    case WM_INITDIALOG:
    
    return TRUE;   
    
    break;
    
    case WM_PAINT:{
    	
		PAINTSTRUCT ps; 
      	HDC hdc;
      	hdc = BeginPaint(hwnd, &ps);     
      	for(std::vector<atOrder>::iterator itr = attackOrders.begin();
		  	itr != attackOrders.end(); itr++){
	  		
		  		if((itr->hit) && (!itr->pen)){
		  			
		  			  char msg[50] = {0};
					  strcat(msg,"The ");
					  strcat(msg, data[itr->dfDB].gtNameC());
					  int sze =  data[itr->dfDB].gtNameLen();
					  strcat(msg," Was Hit!");
		  			
		  			  TextOut(hdc,5,rCnt, msg , sze +13);
		  			  rCnt+=20;
		  			  
				  }
				  
		  		if(!itr->hit){
		  			
		  			  char msg[50] = {0};
					  strcat(msg,"The ");
					  strcat(msg, data[itr->atDB].gtNameC());
					  int sze =  data[itr->atDB].gtNameLen();
					  strcat(msg," Missed.");
		  			
		  			  TextOut(hdc,5,rCnt, msg , sze +12);
		  			  rCnt+=20;
		  			  
				  }
		  		if((itr->hit) && (itr->pen)){
		  			
		  			char msg[50] = {0};
					strcat(msg,"The ");
					strcat(msg, data[itr->dfDB].gtNameC());
					int sze =  data[itr->dfDB].gtNameLen();
		  			strcat(msg," Was Destroyed!");
		  			
		  			TextOut(hdc,5,rCnt, msg , sze +19);		  			
					rCnt+=20;
		  			
				  }
				  
		  		if((itr->hit) && (itr->imb)){
		  			
		  			char msg[50] = {0};
					strcat(msg,"The ");
					strcat(msg, data[itr->dfDB].gtNameC());
					int sze =  data[itr->dfDB].gtNameLen();
		  			strcat(msg,"Was Imobolized.");
		  			
		  			TextOut(hdc,5,rCnt, msg , sze +19);							  		  			
					rCnt+=20;
		  			
				  }				  				  

			  }
        
      	EndPaint(hwnd, &ps);  
	}
    break;
    
    case WM_COMMAND:
        switch(LOWORD(wp)){    
        case IDOK:
          EndDialog(hwnd, IDOK);
        break;
       }
  }
return FALSE;     
}


BOOL CALLBACK resultsProc2(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){ 


  switch(msg){
              
    case WM_INITDIALOG:
    
    return TRUE;   
    
    break;
    
    case WM_PAINT:{
    	
		PAINTSTRUCT ps; 
      	HDC hdc;
      	hdc = BeginPaint(hwnd, &ps);     
      	for(std::vector<atOrder>::iterator itr = OverwatchOrders.begin();
		  	itr != OverwatchOrders.end(); itr++){
	  		
		  		if((itr->hit) && (!itr->pen)){
		  			
		  			  char msg[50] = {0};
					  strcat(msg,"The ");
					  strcat(msg, data[itr->dfDB].gtNameC());
					  int sze =  data[itr->dfDB].gtNameLen();
					  strcat(msg," Was Hit!");
		  			
		  			  TextOut(hdc,5,rCnt, msg , sze +13);
		  			  rCnt+=20;
		  			  
				  }
				  
		  		if(!itr->hit){
		  			
		  			  char msg[50] = {0};
					  strcat(msg,"The ");
					  strcat(msg, data[itr->atDB].gtNameC());
					  int sze =  data[itr->atDB].gtNameLen();
					  strcat(msg," Missed.");
		  			
		  			  TextOut(hdc,5,rCnt, msg , sze +12);
		  			  rCnt+=20;
		  			  
				  }
		  		if((itr->hit) && (itr->pen)){
		  			
		  			char msg[50] = {0};
					strcat(msg,"The ");
					strcat(msg, data[itr->dfDB].gtNameC());
					int sze =  data[itr->dfDB].gtNameLen();
		  			strcat(msg,"Was Destroyed!");
		  			
		  			TextOut(hdc,5,rCnt, msg , sze +18);		  			
					rCnt+=20;
		  			
				  }
				  
		  		if((itr->hit) && (itr->imb)){
		  			
		  			char msg[50] = {0};
					strcat(msg,"The ");
					strcat(msg, data[itr->dfDB].gtNameC());
					int sze =  data[itr->dfDB].gtNameLen();
		  			strcat(msg,"Was Imobolized.");
		  			
		  			TextOut(hdc,5,rCnt, msg , sze +19);							  		  			
					rCnt+=20;
		  			
				  }				  				  

			  }
        
      	EndPaint(hwnd, &ps);  
	}
    break;
    
    case WM_COMMAND:
        switch(LOWORD(wp)){    
        case IDOK:
          EndDialog(hwnd, IDOK);
        break;
       }
  }
return FALSE;     
}

