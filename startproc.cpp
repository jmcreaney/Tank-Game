#include<windows.h>

#include "game.h"

static int choice1 = IDC_USA;
static int choice2 = IDC_NAZIII;

extern char pl1;
extern char pl2;
extern bool aii;

extern int plPoints1;
extern int plPoints2;
extern int year;
extern int month;

extern control * manage;


BOOL    CALLBACK startProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){
	
	
  int points [] = {200,300,400,500,600,700,800};
  const char * StPoints [] = {"200","300","400","500","600","700","800"};
  int months [] = {1,2,3,4,5,6,7,8,9,10,11,12};
  const char * StMonths [] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  int years [] = {40,41,42,43,44};
  const char * StYrs [] = {"40","41","42","43","44"};
  
  int index = 0;
  
  switch(msg){
              
    case WM_INITDIALOG:
    	   	
         choice1 = IDC_USA;
         choice2 = IDC_NAZIII,
         CheckRadioButton(hwnd, IDC_USA,   IDC_SOVIET,   choice1);
         CheckRadioButton(hwnd, IDC_USAII, IDC_SOVIETII, choice2);
         SetFocus(GetDlgItem(hwnd, choice1));
         SetFocus(GetDlgItem(hwnd, choice2));
         pl1 = 'a';
         pl2 = 'g';
         
         
         for(int lp = 0; lp < 7; lp++){
         	SendDlgItemMessage(hwnd, IDC_POINTS_BOX, CB_ADDSTRING, 0, (LPARAM) StPoints[lp]);
		}
		
		for(int lp = 0; lp < 6; lp++){
         	SendDlgItemMessage(hwnd, IDC_YEAR_BOX, CB_ADDSTRING, 0, (LPARAM) StYrs[lp]);
		}
		
		for(int lp = 0; lp < 12; lp++){
         	SendDlgItemMessage(hwnd, IDC_MONTH_BOX, CB_ADDSTRING, 0, (LPARAM) StMonths[lp]);
		}
	
	
		SendDlgItemMessage(hwnd, IDC_POINTS_BOX, CB_SETCURSEL, 1, (LPARAM) StPoints[1]);         
		SendDlgItemMessage(hwnd, IDC_YEAR_BOX, CB_SETCURSEL, 2, (LPARAM) StYrs[2]);
		SendDlgItemMessage(hwnd, IDC_MONTH_BOX, CB_SETCURSEL, 3, (LPARAM) StMonths[3]);     
         
    return TRUE;   
    break;
    
    case WM_COMMAND:
        switch(LOWORD(wp)){    
        	
            
        case IDOK:
          if(pl1 == pl2){
          	  MessageBox(NULL, "Player 1 and 2 can't be the same!", "Warning!", MB_OK);
			  	   	
		  }else{
		  	manage = new control(pl1, pl2);
          	EndDialog(hwnd, IDOK);
      	  }
        break;
        
    case IDC_USA:
       CheckRadioButton(hwnd, IDC_USA, IDC_SOVIET ,LOWORD(wp));
       pl1 = 'a'; 
    
    return TRUE;

    case IDC_UK:
       CheckRadioButton(hwnd, IDC_USA, IDC_SOVIET ,LOWORD(wp));
       pl1 = 'b';     
    return TRUE;
    
    case IDC_NAZI:
       CheckRadioButton(hwnd, IDC_USA, IDC_SOVIET ,LOWORD(wp));
       pl1 = 'g'; 
    
    return TRUE;
    
    case IDC_SOVIET:
       CheckRadioButton(hwnd, IDC_USA, IDC_SOVIET ,LOWORD(wp));
       pl1 = 'r';   
    return TRUE;

    case IDC_USAII:
       CheckRadioButton(hwnd, IDC_USAII, IDC_SOVIETII ,LOWORD(wp));
       pl2 = 'a';         
    return TRUE;
    
    case IDC_UKII:
       CheckRadioButton(hwnd, IDC_USAII, IDC_SOVIETII ,LOWORD(wp));
       pl2 = 'b';         
    return TRUE;
    
    case IDC_NAZIII:
       CheckRadioButton(hwnd, IDC_USAII, IDC_SOVIETII ,LOWORD(wp));
       pl2 = 'g';         
    return TRUE;
    
    case IDC_SOVIETII:
       CheckRadioButton(hwnd, IDC_USAII, IDC_SOVIETII ,LOWORD(wp));
       pl2 = 'r';         
    return TRUE;
    
     case IDC_AI:
        if(aii == false){aii = true;} else {aii = false;}
        SendDlgItemMessage(hwnd, IDC_AI, BM_SETCHECK, aii, 0);
     return TRUE;
       
       
    case IDC_POINTS_BOX:  		        		
		   index = SendDlgItemMessage(hwnd, IDC_POINTS_BOX, CB_GETCURSEL, 0,0);
		   plPoints2 = plPoints1 = points[index];
    return TRUE;
	break;
	
    case IDC_MONTH_BOX:      		        		
		   index = SendDlgItemMessage(hwnd, IDC_MONTH_BOX, CB_GETCURSEL, 0,0);
		   month = months[index];
	return TRUE;
	break;
	
    case IDC_YEAR_BOX:   		        		
		   index = SendDlgItemMessage(hwnd, IDC_YEAR_BOX, CB_GETCURSEL, 0,0);
		   year = years[index];
	return TRUE;
	break;
	}
  }
  
return FALSE;     
}
