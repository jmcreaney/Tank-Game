#include<string>
#include<iterator>
#include<vector>

#include "armor.h"
#include "gun.h"


#ifndef TANKDATA_H
#define TANKDATA_H

class tankData{
  std::string name;
  std::string country;
  char cntry;
  bool hasTurret;
  
  gun * Gun;
  int main_gun;
  
  char size;
  int performance;
  float rarity;
  
  int rdSpeed;
  int ccSpeed;
  
  int points;
  int month;
  int year;
  int armarment;
  
  int fireFactor;
  int observation;
  
  armor turret;
  armor upHull;
  armor lwHull;
  
  int choose();
  

  
public:
  
  tankData();
  tankData(std::string&);
  tankData(std::ifstream&);
  tankData(std::string, std::ifstream&);
  tankData(const tankData&);
  
  bool ifTurret(){return hasTurret;}
  
  
  void load(std::ifstream&);
  void save(std::ofstream&);

  std::string gtName(){return name;}
  const char * gtNameC(){return name.c_str();}
  std::string gtGunName(){return Gun->gtName();}
  
  int gtNameLen(){return name.size();}
  
  char gtCntry();
  std::string gtCountry(){return country;}
  int gtRdSpeed(){return rdSpeed;}
  int gtCcSpeed(){return ccSpeed;}
  int gtFFactor(){return fireFactor;}
  int gtYear(){return year;}
  int gtMonth(){return month;}
  int gtPoints(){return points;}
  
  void setCntry(char c){country = c;}
  void gtSize(char c){size = c;}
  void gtPerform(int n){performance = n;}
  void gtrSpeed(int n){rdSpeed = n;}
  void gtcSpeed(int n){ccSpeed = n;}
  void gtFFactor(int n){fireFactor = n;}
  void gtObv(int n){observation = n;}
  bool gtTurret(){return hasTurret;}
  void addGun(gun);
  void addTurret(armor&);
  void addUHull(armor&);
  void addLHull(armor&);
  
  int gtHitRoll(int r){Gun->gtHitRoll(r);}
  int gtPenitrate(int r){Gun->gtPenitrate(r);}
  char gtSize(){return size;}
  int gtAFnt(char);
  int gtAFnt45(char);
  int gtASde(char);
  int gtASde45(char);
  int gtARear(char);
  int gtARear45(char);
                        
};      
    

#endif
