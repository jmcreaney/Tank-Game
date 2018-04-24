#ifndef CHOOSESTRUCT_H
#define CHOOSESTRUCT_H


struct chooseStruct{
  const char * name;
  int pts;
  int place; 
  int dataElement;
   
  chooseStruct(const char* n , int p, int pt, int de){ 
  	name = n; 
	place = p; 
	pts = pt;
	dataElement = de;
	}    
	
	chooseStruct(const chooseStruct& cs){
		name = cs.name;
		place = cs.place;
		pts = cs.pts;
		dataElement = cs.dataElement;
		
	}
	
	chooseStruct& operator=(const chooseStruct cs){
		name = cs.name;
		place = cs.place;
		pts = cs.pts;
		dataElement = cs.dataElement;
				
		return *this;
	}
    
};

#endif
