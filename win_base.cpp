#include<string>


#include "game.h"
#include "win_base.h"

win_base::win_base(HINSTANCE hinstance, PSTR szCmdLn, int iCmdShow){
                             
  AppName = "Graphics Display Demo";  
  win_high = 100;
  win_wide = 100;
  
  hin = hinstance; 
  CmdLn = szCmdLn; 

  winclass.cbSize        = sizeof(winclass);
  winclass.style         = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
  winclass.lpfnWndProc   = WinProc;
  winclass.hInstance     = hin;
  winclass.cbClsExtra    = 0;
  winclass.cbWndExtra    = 0;
  winclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
  winclass.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
  winclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
  winclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);          
  winclass.lpszMenuName  = NULL;
  winclass.lpszClassName = AppName.c_str();
  
  registered = false;
  use_dx = false;
}


void win_base::init(int iCmdShow){
     
  RegisterClassEx(&winclass);

  if(use_dx){

    hwnd = CreateWindowEx (
      0,                  
      AppName.c_str(),         
      AppName.c_str(),      
      WS_POPUP | WS_VISIBLE,
      CW_USEDEFAULT,      
      CW_USEDEFAULT,      
      win_high,                
      win_wide,             
      NULL,        
      NULL,              
      hin,    
      NULL); 
  }else{

    hwnd = CreateWindowEx (
      0,                  
      AppName.c_str(),      
      AppName.c_str(),      
      WS_OVERLAPPEDWINDOW, 
      CW_USEDEFAULT,       
      CW_USEDEFAULT,       
      win_high,                 
      win_wide,               
      NULL,        
      NULL,               
      hin,       
      NULL); 
      
  }
   
  ShowWindow (hwnd, iCmdShow); 
  UpdateWindow(hwnd);
  
  registered = true;
     
}

win_base::~win_base(){}
 

WPARAM win_base::doLoop(){
       
   while(GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

   return msg.wParam;    
     
}  

WPARAM win_base::loop(){
       
 float d=0;
 
  while(TRUE){
  if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)){ 
    if (msg.message == WM_QUIT)
      break;
    TranslateMessage(&msg);
    DispatchMessage(&msg);
    }   else{ 
     InvalidateRect(hwnd,NULL,true); 
     while(d < 100000){d=d+.001;}
    }

  } 
return(msg.wParam);

}

void win_base::setSize(int acc = 100, int hi = 100){
     
  if(!registered){
    win_wide = acc;                
    win_high = hi;              
  }
}

void win_base::setIcon(WORD ico){
  if(!registered){  
    winclass.hIcon = LoadIcon(hin, MAKEINTRESOURCE(ico));
  }

}

void win_base::setIconSm(WORD ico){
  if(!registered){
    winclass.hIconSm = LoadIcon(hin, MAKEINTRESOURCE(ico));
  }
}

void win_base::setGrey(){
  if(!registered){
    winclass.hbrBackground =(HBRUSH) (COLOR_WINDOW);  
  }
}

void win_base::setWhite(){
  if(!registered){
    winclass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
  }
}

void win_base::addMenu(){
  if(!registered){
    winclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
  }
}

void win_base::setPrgName(char * n){
  if(!registered){  
    AppName = n;
  }
   
}

