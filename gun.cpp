#include<fstream>
#include<stdexcept>

#include "gun.h"

gun::gun(std::string& n){

   name = n;
   create();
   std::cout<<name<<" Created!"<<std::endl;
}

gun::gun(std::ifstream& f){

     create();
     char d;

	  size_t sz = name.size();
	         	
   	getline(f, name, '\0');
   	f.read((char*)&d, sizeof(char));
   	
    getline(f, country, '\0');
    f.read((char*)&d, sizeof(char));

     f.read((char*) &cntry, sizeof(char));

     for(int l = 0; l != ranges; l++){

       f.read((char*) &stats[l].range, sizeof(int));
       f.read((char*) &stats[l].pen, sizeof(int));
       f.read((char*) &stats[l].hitRoll, sizeof(int));
     }

}

gun::gun(std::string n, std::ifstream& IN){
	name = n;
	IN >> country;
	
	int distances[] = {25,50,100,250,500,750,1000,1250,1500,2000,3000,4000};
	
	stats = new gunStat[ranges];
	
	for(int l = 0; l != ranges; l++){
		stats[l].range = distances[l];
		IN >> stats[l].pen;
		IN >> stats[l].hitRoll;
	}


}

gun::gun(const gun& o){

   name = o.name;
   country = o.country;
   
   create();
   for(int l = 0; l != ranges; l++){
      stats[l].range = o.stats[l].range;
      stats[l].hitRoll = o.stats[l].hitRoll;
      stats[l].pen = o.stats[l].pen;
   }
   cntry = o.cntry;

}

gun::~gun(){

  delete [] stats;

}

void gun::create(){

   stats = new gunStat[13];
}

void gun::input(int c, int d, int r, int p){

   stats[c].range = d;
   stats[c].hitRoll = r;
   stats[c].pen = p;

}

std::string gun::gtName(){
   return name;
}

void gun::save(std::ofstream& f){

	 f.write(name.c_str(), name.length()+1);
	 f.write("\0",sizeof(char));
	 
	 f.write(country.c_str(), country.length()+1);
	 f.write("\0",sizeof(char));
     

     f.write((char*) &cntry, sizeof(char));

     for(int l = 0; l != ranges; l++){
       f.write((char*) &stats[l].range, sizeof(int));
       f.write((char*) &stats[l].hitRoll, sizeof(int));
       f.write((char*) &stats[l].pen, sizeof(int));
     }
    
}

int gun::gtRange(int r){

    int place = 0;

    if(r < 25){place = 0;}
    if((r > 26) && (r < 50)){place = 1;}
    if((r > 51) && (r < 100)){place = 2;}
    if((r > 101) && (r < 250)){place = 3;}
    if((r > 251) && (r < 500)){place = 4;}
    if((r > 501) && (r < 750)){place = 5;}
    if((r > 751) && (r < 1000)){place = 6;}
    if((r > 1001) && (r < 1250)){place = 7;}
    if((r > 2151) && (r < 1500)){place = 8;}
    if((r > 1501) && (r < 2000)){place = 9;}
    if((r > 2001) && (r < 2500)){place = 10;}
    if((r > 3000) && (r < 4000)){place = 11;}
    if(r > 4001){place = 12;}

    return place;
}

int gun::gtHitRoll(int r){


   int pl  = gtRange(r);
   if(stats[pl].pen == 0){
     return -1;
   }
   return stats[pl].hitRoll;

}

int gun::gtPenitrate(int r){
   int pl = gtRange(r);
   return stats[pl].pen;

}

void gun::load(std::ifstream& f){

}



