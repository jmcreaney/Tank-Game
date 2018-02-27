#include "hAFV.h"
#include "tankData.h"

extern std::vector<tankData>data;

h_AFV::h_AFV(){
  pAFV = NULL;
  cnt = new int(1);
}

h_AFV::h_AFV(int d){   
                   
  if(data[d].ifTurret()){
    pAFV = new tank(d);
  }
  if(!data[d].ifTurret()){
    pAFV = new spGun(d);
  } 
  cnt = new int(1);                             
}

h_AFV::h_AFV(int i, int x, int y, int n){
                 
  if(data[i].ifTurret()){
    pAFV = new tank(i,x,y,n);
  }
  if(!data[i].ifTurret()){
    pAFV = new spGun(i,x,y,n);
  } 
 
  cnt = new int(1);                             
}

h_AFV::~h_AFV(){
   
   if(--* cnt == 0){
      delete pAFV;
      delete cnt;
   }                             
}

h_AFV& h_AFV::operator = (const h_AFV &afv){
    
    ++*cnt;
    pAFV = afv.pAFV;
    return *this;      
}

void h_AFV::create(int i, int x, int y, int n){
                 
  if(data[i].ifTurret()){
    pAFV = new tank(i,x,y,n);
  }
  if(!data[i].ifTurret()){
    pAFV = new spGun(i,x,y,n);
  } 
  
  cnt = new int(1);                             
}


