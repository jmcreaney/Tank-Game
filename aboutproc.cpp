#include<windows.h>

#include "game.h"

BOOL CALLBACK aboutProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){ 
     
  switch(msg){
              
    case WM_INITDIALOG:
      return TRUE;   
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
