#include<string>
#include<fstream>
#include<cstdlib>

#include "tankData.h"

extern std::vector<gun>guns;

tankData::tankData(){}
                
tankData::tankData(std::string& n){

   name = n;
     
}

tankData::tankData(std::ifstream& f){
	
	int d;

          	
   	getline(f, name, '\0');
   	f.read((char*)&d, sizeof(char));
   	
   	getline(f, country, '\0');
    f.read((char*)&d, sizeof(char));
     
     f.read((char*) &cntry, sizeof(char));
     f.read((char*) &hasTurret, sizeof(bool));
     f.read((char*) &size, sizeof(char));
     f.read((char*) &performance, sizeof(int));
     f.read((char*) &rdSpeed, sizeof(int));
     f.read((char*) &ccSpeed, sizeof(int));
     f.read((char*) &observation, sizeof(int));
     f.read((char*) &month, sizeof(int));     
     f.read((char*) &year, sizeof(int));  
	 f.read((char*) &points, sizeof(int));  
     f.read((char*) &fireFactor, sizeof(int));
     f.read((char*) &turret.fnt, sizeof(int));
     f.read((char*) &turret.fnt45, sizeof(int));
     f.read((char*) &turret.sde, sizeof(int));
     f.read((char*) &turret.sde45, sizeof(int));
     f.read((char*) &turret.rear, sizeof(int));
     f.read((char*) &turret.rear45, sizeof(int));
     f.read((char*) &upHull.fnt, sizeof(int));
     f.read((char*) &upHull.fnt45, sizeof(int));
     f.read((char*) &upHull.sde, sizeof(int));
     f.read((char*) &upHull.sde45, sizeof(int));
     f.read((char*) &upHull.rear, sizeof(int));
     f.read((char*) &upHull.rear45, sizeof(int));
     f.read((char*) &lwHull.fnt, sizeof(int));
     f.read((char*) &lwHull.fnt45, sizeof(int));
     f.read((char*) &lwHull.sde, sizeof(int));
     f.read((char*) &lwHull.sde45, sizeof(int));
     f.read((char*) &lwHull.rear, sizeof(int));
     f.read((char*) &lwHull.rear45, sizeof(int));    
	 
	 Gun = new gun(f);
                                                         
}

tankData::tankData(std::string n, std::ifstream& F){
	name = n;
	F >> country;
	F >> hasTurret;
	F >> points ;
	F >> month;
	F >> year;
	F >> size;
	F >> main_gun;
	main_gun--;
	
	Gun = new gun(guns[main_gun]);
	std::cout<<guns[main_gun].gtName()<<"Was Added "<<std::endl;
	
	//F >> armarment;
	F >> performance;
	F >> rdSpeed;
	F >> ccSpeed;
	F >> fireFactor;
	F >> observation;
	
	 if (country == "German") {cntry = 'g';}
     if (country == "USSR")   {cntry = 'r';}
     if (country == "USA")    {cntry = 'u';}
     if (country == "British"){cntry = 'b';}	
	
	
    turret.load(F);
 	upHull.load(F);
	lwHull.load(F);	
	}

tankData::tankData(const tankData& td){
                         
    name = td.name;
    hasTurret = td.hasTurret;
    country = td.country;
    cntry = td.cntry;
    Gun  = td.Gun;
    size = td.size;
    performance = td.performance;
    rdSpeed = td.rdSpeed;
    ccSpeed = td.ccSpeed;
    fireFactor = td.fireFactor;
    observation = td.observation;
    month = td.month;
    year = td.year;
    points = td.points;
  
    turret = td.turret;
    upHull = td.upHull;
    lwHull = td.lwHull;                         
}


void tankData::save(std::ofstream& f){
	
	  size_t sz = name.size();
	 
	 f.write(name.c_str(), name.length()+1);
	 f.write("\0",sizeof(char));
	 
	 f.write(country.c_str(), country.length()+1);
	 f.write("\0",sizeof(char));

     f.write((char*) &cntry, sizeof(char));
     f.write((char*) &hasTurret, sizeof(bool));     
     f.write((char*) &size, sizeof(char));
     f.write((char*) &performance, sizeof(int));
     f.write((char*) &rdSpeed, sizeof(int));
     f.write((char*) &ccSpeed, sizeof(int));
     f.write((char*) &observation, sizeof(int));
     f.write((char*) &month, sizeof(int));     
     f.write((char*) &year, sizeof(int));  
	 f.write((char*) &points, sizeof(int));  
     f.write((char*) &fireFactor, sizeof(int));
     f.write((char*) &turret.fnt, sizeof(int));
     f.write((char*) &turret.fnt45, sizeof(int));
     f.write((char*) &turret.sde, sizeof(int));
     f.write((char*) &turret.sde45, sizeof(int));
     f.write((char*) &turret.rear, sizeof(int));
     f.write((char*) &turret.rear45, sizeof(int));
     f.write((char*) &upHull.fnt, sizeof(int));
     f.write((char*) &upHull.fnt45, sizeof(int));
     f.write((char*) &upHull.sde, sizeof(int));
     f.write((char*) &upHull.sde45, sizeof(int));
     f.write((char*) &upHull.rear, sizeof(int));
     f.write((char*) &upHull.rear45, sizeof(int));
     f.write((char*) &lwHull.fnt, sizeof(int));
     f.write((char*) &lwHull.fnt45, sizeof(int));
     f.write((char*) &lwHull.sde, sizeof(int));
     f.write((char*) &lwHull.sde45, sizeof(int));
     f.write((char*) &lwHull.rear, sizeof(int));
     f.write((char*) &lwHull.rear45, sizeof(int));   
	 
	 Gun->save(f);    

}

void tankData::addGun(gun g){
     
     Gun = new gun(g);
     
}

void tankData::addTurret(armor& a){
      
   turret.fnt    = a.fnt;
   turret.fnt45  = a.fnt45;
   turret.sde    = a.sde;
   turret.sde45  = a.sde45;
   turret.rear   = a.rear;
   turret.rear45 = a.rear45;   
}

void tankData::addUHull(armor& a){
      
   upHull.fnt    = a.fnt;
   upHull.fnt45  = a.fnt45;
   upHull.sde    = a.sde;
   upHull.sde45  = a.sde45;
   upHull.rear   = a.rear;
   upHull.rear45 = a.rear45;       
}

void tankData::addLHull(armor& a){
      
   lwHull.fnt    = a.fnt;
   lwHull.fnt45  = a.fnt45;
   lwHull.sde    = a.sde;
   lwHull.sde45  = a.sde45;
   lwHull.rear   = a.rear;
   lwHull.rear45 = a.rear45;       
}


int tankData::gtAFnt(char l){

   if(l == 't'){
   		if(name.c_str() == "PzKw_Vd_Panther"){
   			int x = choose();
			   if(x==0){return 228;}else{return 118;}
		} 
		   		if(name.c_str() == "PzKw_Vg_Panther"){
   			int x = choose();
			   if(x==0){return 223;}else{return 105;}
		} 
		   		if(name.c_str() == "PzKw_VI_Tiger_I"){
   			int x = choose();
			   if(x==0){return 228;}else{return 110;}
		}   
		   		if(name.c_str() == "PzKw_IIIj"){
   			int x = choose();
			   if(x==0){return 104;}else{return 71;}
		}   
   
   		return turret.fnt;
   }
   if(l == 'u'){
   		if(name.c_str() == "M4A3_Sherman(76)"){
   			int x = choose();
			   if(x==0){return 89;}else{return 141;}
		}  
		return upHull.fnt; 
   }
   if(l == 'l'){return lwHull.fnt;}
   if(l == 's'){
      rdSpeed = 0;
      ccSpeed = 0;
      return 0;  
       
   }
}

int tankData::gtAFnt45(char l){

   if(l == 't'){
   		if(name.c_str() == "PzKw_Vd_Panther"){
   			int x = choose();
			   if(x==0){return 376;}else{return 195;}
		} 
		   		if(name.c_str() == "PzKw_Vg_Panther"){
   			int x = choose();
			   if(x==0){return 368;}else{return 173;}
		} 
		   		if(name.c_str() == "PzKw_VI_Tiger_I"){
   			int x = choose();
			   if(x==0){return 360;}else{return 182;}
		}  
		   		if(name.c_str() == "PzKw_IIIj"){
   			int x = choose();
			   if(x==0){return 172;}else{return 117;}
		}     
   		return turret.fnt45;
		   
	}
	
   if(l == 'u'){
   		if(name.c_str() == "M4A3_Sherman(76)"){
   			int x = choose();
			   if(x==0){return 147;}else{return 233;}
		}
   return upHull.fnt45;
   }
   if(l == 'l'){return lwHull.fnt45;}
   if(l == 's'){
      rdSpeed = 0;
      ccSpeed = 0;
      return 0;  
       
   }
}

int tankData::gtASde(char l){

   if(l == 't'){return turret.sde;}
   if(l == 'u'){return upHull.sde;}
   if(l == 'l'){return lwHull.sde;}
   if(l == 's'){
      rdSpeed = 0;
      ccSpeed = 0;
      return 0;  
       
   }
}

int tankData::gtASde45(char l){

   if(l == 't'){return turret.sde45;}
   if(l == 'u'){return upHull.sde45;}
   if(l == 'l'){return lwHull.sde45;}
   if(l == 's'){
      rdSpeed = 0;
      ccSpeed = 0;
      return 0;  
       
   }
}

int tankData::gtARear(char l){

   if(l == 't'){return turret.rear;}
   if(l == 'u'){return upHull.rear;}
   if(l == 'l'){return lwHull.rear;}
   if(l == 's'){
      rdSpeed = 0;
      ccSpeed = 0;
      return 0;  
       
   }
}

int tankData::gtARear45(char l){

   if(l == 't'){return turret.rear45;}
   if(l == 'u'){return upHull.rear45;}
   if(l == 'l'){return lwHull.rear45;}
   if(l == 's'){
      rdSpeed = 0;
      ccSpeed = 0;
      return 0;  
       
   }
}

   
char tankData::gtCntry(){
		if(country == "USA"){return 'a';}
		if(country == "German"){return 'g';}
		if(country == "USSR"){return 'r';}
		if(country == "British"){return 'b';}  	    
}

int tankData::choose(){
	
	return rand()%2;
	
}
  
