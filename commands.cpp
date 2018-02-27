#include "game.h"


void commands(HWND hwnd, UINT uint, WPARAM wp, LPARAM lp){
         
  switch(LOWORD(wp)){
                  
    case ID_QUIT:
      PostMessage(hwnd, WM_CLOSE, 0, 0);  
    break;
               
    case ID_ABOUT:               
      if (FAILED(DialogBox(GetModuleHandle(NULL),
      MAKEINTRESOURCE(IDD_ABOUT), hwnd, aboutProc))){
         MessageBox(NULL, "Box Failed!", "Error!", MB_OK);}   
	
	case ID_HELP:               
      if (FAILED(DialogBox(GetModuleHandle(NULL),
      MAKEINTRESOURCE(IDD_HELP), hwnd, aboutProc))){
         MessageBox(NULL, "Box Failed!", "Error!", MB_OK);}         


    break;  
  }  
       
}
