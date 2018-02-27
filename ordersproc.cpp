#include "game.h"

extern std::vector<tankData>data;
extern std::vector<h_AFV>AFVs;
extern std::vector<mvOrder>moveOrders;
extern std::vector<atOrder>attackOrders;
extern std::vector<atOrder>OverwatchOrders;
extern control * manage;


int facing;
int speed;
int select;
int dataRef;
int allign;
int DBI;
    
BOOL CALLBACK ordersProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){ 
  
    switch(msg){
              
    case WM_INITDIALOG:     
        select = 0;
        speed = 100;
        facing = 0;
        allign = false;
                  
        dataRef = AFVs[ manage->gtCurrentTank()].gtDBI();

      
        SendDlgItemMessage(hwnd, IDC_ORDER_BOX, CB_ADDSTRING, 0, (LPARAM)"Move");
        SendDlgItemMessage(hwnd, IDC_ORDER_BOX, CB_ADDSTRING, 0, (LPARAM)"Fire");
        SendDlgItemMessage(hwnd, IDC_ORDER_BOX, CB_ADDSTRING, 0, (LPARAM)"OverWatch");
        facing = AFVs[manage->gtCurrentTank()].gtFace();
        SetDlgItemInt(hwnd, ID_MOVEDIR, facing, false);
        SetDlgItemInt(hwnd, ID_MOVE_CENT, speed, false);
        if(select != 1){
          SendDlgItemMessage(hwnd, ID_MOVEDIR, WM_ENABLE,FALSE,0);
          SendDlgItemMessage(hwnd, ID_MOVE_CENT, WM_ENABLE,FALSE,0);
          SendDlgItemMessage(hwnd, ID_ALLIGN_TURRET, WM_ENABLE,FALSE,0);
        } else {
          SendDlgItemMessage(hwnd, ID_MOVEDIR, WM_ENABLE,TRUE,0);
          SendDlgItemMessage(hwnd, ID_MOVE_CENT, WM_ENABLE,TRUE,0);
          SendDlgItemMessage(hwnd, ID_ALLIGN_TURRET, WM_ENABLE,TRUE,0);        
        }
      return TRUE; 
	
    break;
    
         

    case WM_PAINT:
      PAINTSTRUCT ps; 
      HDC hdc;
      hdc = BeginPaint(hwnd, &ps);      
      TextOut(hdc, 5,5,data[dataRef].gtNameC() ,
              data[dataRef].gtNameLen());
              
      EndPaint(hwnd, &ps);  
    break;       
           
    case WM_COMMAND:
    	
        switch(LOWORD(wp)){   
         
        case IDOK:{
          
        if(select == 0){
			atOrder ao(manage->gtCurrentTank());
			AFVs[ao.atLn].setStat(2);
			attackOrders.push_back(ao);
			
			} 
        if(select == 1){
        	
           if(!AFVs[manage->gtCurrentTank()].isMobile()){
           	
           		MessageBox(NULL, "Vehicle is not Mobile", "Info.", MB_OK);
           		return 0;
           	
		   }	
           facing = GetDlgItemInt(hwnd, ID_MOVEDIR, &facing, false);
           speed = GetDlgItemInt(hwnd, ID_MOVE_CENT, &speed, false); 
           if(speed > 100){speed = 100;}  
           if(speed < 0){speed = 0;}    
		    
           mvOrder mo(manage->gtCurrentTank(), facing, speed, allign);
           AFVs[mo.lnNumber].setStat(1);
           moveOrders.push_back(mo);
	                                    
        }
        if(select == 2){
        
		    atOrder ao(manage->gtCurrentTank());
			AFVs[ao.atLn].setStat(3);
			OverwatchOrders.push_back(ao);
		    
		    
		}             
		
        EndDialog(hwnd, IDOK);
        
        }
        break;
       
        case IDC_ORDER_BOX:
           select = SendMessage((HWND)lp,
           (UINT)CB_GETCURSEL,
           (WPARAM)0, (LPARAM) 0);
           if(select == 1){
              SendDlgItemMessage(hwnd, ID_MOVEDIR, WM_ENABLE,TRUE,0);
              SendDlgItemMessage(hwnd, ID_MOVE_CENT, WM_ENABLE,TRUE,0);  
              SendDlgItemMessage(hwnd, ID_ALLIGN_TURRET, WM_ENABLE,TRUE,0);           
              } else {
              SetDlgItemInt(hwnd, ID_MOVEDIR, facing, false);
              SetDlgItemInt(hwnd, ID_MOVE_CENT, speed, false);
              SendDlgItemMessage(hwnd, ID_MOVEDIR, WM_ENABLE,FALSE,0);
              SendDlgItemMessage(hwnd, ID_MOVE_CENT, WM_ENABLE,FALSE,0);
              SendDlgItemMessage(hwnd, ID_ALLIGN_TURRET, WM_ENABLE,FALSE,0);  
              }
           InvalidateRect(hwnd,NULL,FALSE);
        break;
        
        case ID_ALLIGN_TURRET:
            if(!allign){
              allign = true;
              CheckDlgButton(hwnd, ID_ALLIGN_TURRET, BST_CHECKED); 
              
            }else{
               allign = false;
               CheckDlgButton(hwnd, ID_ALLIGN_TURRET, BST_UNCHECKED); 
               }

        break; 
       } 
  }
  
return FALSE;     
}
