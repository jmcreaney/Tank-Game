#include<windows.h>
#include<string>

#ifndef WIN_BASE_H
#define WIN_BASE_H


class win_base{
      
protected:
 
  std::string AppName;       
  WNDCLASSEX winclass;
  HWND hwnd;
  MSG msg;
  
  HINSTANCE hin; 
  PSTR CmdLn;
   
  int win_high;
  int win_wide;
  
  bool registered;
  bool use_dx;
  
  
                 
public:
  win_base(HINSTANCE, PSTR, int);
 ~win_base();
  void init(int);

  WPARAM doLoop();
  WPARAM loop();
   
  void setSize(int, int);
  void setIcon(WORD);
  void setIconSm(WORD);
  void setGrey();
  void setWhite();
  void addMenu();
  void dxPrep();
  void setPrgName(char *);
  HWND getWin(){return hwnd;}
  
      
};


#endif
