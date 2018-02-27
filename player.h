#include<vector>
#include<list>

#include "hAFV.h"
#include "color.h"
#include "coord.h"
#include "tankData.h"
#include "colorStruct.h"
#include "chooseStruct.h"



#ifndef PLAYER_H
#define PLAYER_H

extern std::vector<tankData>data;
extern colorStruct colors;

class player{
	
	char cntry;
      
 
public:
   
   player();
   player(char);
       
      
};

#endif
