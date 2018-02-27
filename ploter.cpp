#include<windows.h>
#include<windowsx.h>
#include<vector>

#include "ploter.h"



ploter::ploter(std::ifstream& in){
                              
   angle  = 0;
  
  int x, y;

  if(! in.is_open()){
     MessageBox(NULL, "No Points File!", "Error!", MB_OK); }   
     
  if(in){
     plots.clear();
     while (in){
        in>>x>>y;
        plot p(x,y);
        plots.push_back(p);

     }
  }
                                                    
}

void ploter::display(HDC hdc, int x, int y, color& c){

     for(std::vector<plot>::iterator itr = plots.begin();
         itr != plots.end(); itr++){
             
         float nx;
         float ny; 
             
         nx = (float)itr->x*cos(angle) - (float)itr->y*sin(angle);
         ny = (float)itr->x*sin(angle) + (float)itr->y*cos(angle);    
         
         int x2 = nx;
         int y2 = ny;
             
         SetPixel(hdc,x+x2,y+y2,c.getCode());
         
     }
}


void ploter::display(HDC hdc, int x, int y, DWORD c){

     for(std::vector<plot>::iterator itr = plots.begin();
         itr != plots.end(); itr++){
             
         float nx;
         float ny; 
             
         nx = (float)itr->x*cos(angle) - (float)itr->y*sin(angle);
         ny = (float)itr->x*sin(angle) + (float)itr->y*cos(angle);    
         
         int x2 = nx;
         int y2 = ny;
             
         SetPixel(hdc,x+x2,y+y2,c);
         
     }
}

void ploter::setAngle(float a){
       
     angle = a * .0174532925; 
         
}

