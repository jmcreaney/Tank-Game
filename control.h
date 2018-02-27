#include<algorithm>
#include<list>
#include<ctime>

//#include "player.h"
//#include "orders.h"
//#include "hAFV.h"

#ifndef CONTROL_H
#define CONTROL_H

class control{
      
    char pl1;
    char pl2;
    
    char current;

    int currentTank;
    
    bool pl1Done;
    bool pl2Done;
    
    int roll(int);

public:
	
	control(char, char);
   ~control();
	
	char gtCurrent(){return current;}
	char gtPlayer1(){return pl1;}
	char gtPlayer2(){return pl2;}
	
	void finishCurrent();	
	int gtWhoCurent();
	
	void stCurrentTank(int t){currentTank = t;}
	void resetCurrentTank(){currentTank = -1;}
	int gtCurrentTank(){return currentTank;}
	
	
	bool playerPlaced();
	bool allDone();
	
	void chooseInit();
	void swap();
	void reset();
	void done();
};
#endif
