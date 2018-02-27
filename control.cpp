#include "control.h"

control::control(char p1, char p2){

 	pl1 = p1;
 	pl2 = p2;
 	
 	current =  pl1;
 	currentTank = -1;
 	
 	pl1Done = false;
 	pl2Done = false;
}    

control::~control(){}


void control::swap(){
	if(current == pl1){ current = pl2;}
	else{ current = pl1;}
}

void control::chooseInit(){
     
   int num = roll(1);
 
   if((pl1 != 'g') || (pl2 != 'g')){
     if(pl2 == 'g'){swap();}
   
     if(pl2 == 'r'){
       if(num >= 4){swap();}
     }
   if(num >= 3){swap();}               
   }                           
   if(num >= 3){swap();}      
}

int control::roll(int n){
    
    srand (time(NULL));
    
    int total = 0;
    for(int lp = 0; lp != n; lp++){
       total = total + (rand()%6)+1;
    }

    return total;
   
}

bool control::playerPlaced(){
	
	if(current == pl1){	
		swap();			
	}
	
	if(current == pl2){		
		swap();		
	}
	
	
}

int control::gtWhoCurent(){
	
	if(current == pl1){return 1;}
	else{return 2;}
}

void control::reset(){
	pl1Done = false;
	pl2Done = false;
	currentTank = -1;
	
}

void control::done(){
	
	if(current == pl1){pl1Done = true;}
	if(current == pl2){pl2Done = true;}
}


bool control::allDone(){
	
	if(pl1Done && pl2Done) {return true;}
	return false;
}


