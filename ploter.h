#include<windows.h>
#include<vector>
#include<fstream>
#include<math.h>

#include "color.h"

#ifndef PLOTER_H
#define PLOTER_H

struct plot{
  int x;
  int y;   
  
  plot(int px, int py){x = px; y = py;}   
       
};


class ploter{

   float angle;   
   float * lkSin;
   float * lkCos;
      
   std::vector<plot>plots;
public:
          
   ploter(std::ifstream&);  
  ~ploter();   
   void display(HDC, int, int, color&);
   void display(HDC, int, int, DWORD);
   void setAngle(float a);
   
    
};

#endif
