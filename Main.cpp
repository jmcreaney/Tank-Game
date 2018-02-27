#include "game.h"

char PrgName[] = "Simple Tank Game";

bool animate = false;



int h = 940;
int w = 1300;

char pl1;
char pl2;

int plPoints1 = 300;
int plPoints2 = 300;
int year = 42;
int month = 3;
int rCnt = 20;

std::vector<h_AFV>AFVs;
std::vector<gun>guns;
std::vector<tankData>data;

std::vector<mvOrder>moveOrders;
std::vector<atOrder>attackOrders;
std::vector<atOrder>OverwatchOrders;

colorStruct colors;

control * manage;
AI * ai;


enum phase{placement, orders, fire, resolve, overwatch, ffire, moral};
phase Phase = placement;
bool aii = false;


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevinstance,
                   PSTR szCmdLn, int iCmdShow){
                        
   srand (time(NULL));
   MSG msg;
                        
   win_base win(hinstance, szCmdLn, iCmdShow);    

   win.setSize(h,w);    
   win.setPrgName(PrgName);
   win.setWhite();
   win.addMenu();
   win.setIcon(IDI_ICON);
   win.setIconSm(IDI_ICONSM);
   win.init(iCmdShow);
   
   win.doLoop();

return 0;                       
}
