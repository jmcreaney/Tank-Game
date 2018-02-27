#include<windows.h>

#include "game.h"


extern char pl1;
extern char pl2;
extern bool aii;

extern colorStruct colors;

extern AI * ai;
extern control * manage;

extern std::vector<int>p1chosen;
extern std::vector<int>p2chosen;
extern std::vector<tankData>data;

void setup(HWND hwnd){
	
	load();

    if (FAILED(DialogBox(GetModuleHandle(NULL),
       MAKEINTRESOURCE(IDD_SETUP), hwnd, startProc))){ 
       MessageBox(NULL, "Box Failed!", "Error!", MB_OK);}
       
    if(aii){ai = new AI(pl2);}
   
    if (FAILED(DialogBox(GetModuleHandle(NULL),
       MAKEINTRESOURCE(IDD_SELECT), hwnd, chooseProc))){ 
       MessageBox(NULL, "Box Failed!", "Error!", MB_OK);}
	if(!aii){
      if (FAILED(DialogBox(GetModuleHandle(NULL),
       MAKEINTRESOURCE(IDD_SELECT), hwnd, chooseProc2))){ 
       MessageBox(NULL, "Box Failed!", "Error!", MB_OK);}
	}
	if(aii){
		//ai.choose();
	}

       colors.Ground.set(RGB(69,232,0));
       colors.Soviet.set(RGB(0xf0,0,0));
       colors.German.set(RGB(0x67,0x85,0x81));
       colors.British.set(RGB(0xfe,0xfa,0x56));
       colors.USA.set(RGB(0,0x80,0));
       colors.markFire.set(RGB(253,19,101));
       colors.markSelect.set(RGB(78,79,211));
       colors.markDefault.set(RGB(0,0,0));
       colors.markImob.set(RGB(0x5c,0x8a,0x8a));
       colors.markOW.set(RGB(0xff,0x99,0x99));
       
       int cnt = 0;     
}
