#include <fstream>

#include "game.h"

#ifndef TANKDATA_H
#define TANKDATA_H


struct gunData{
	const char * name;
	const char * country;
	
    gunStat stats[13];	
	
	gunData(std::ifstream); 
	
};

struct Armor{
	int fnt;
	int fnt45;
	int side
	int s45
	int rear;
	int rear45;
	
};

struct tankData{
	
	gunData * gun;
	
	const char * name;
	const char * country;
	bool hasTurret;
	int points;
	int month;
	int year;
	char size;
	int armament;
	int performance;
	int roadSpeed;
	int ccSpeed;
	int fireFactor;
	int observation;
	
	Armor Turret;
	Armor UpHull;
	Armor lHull;
	
	tankData(std::ifstream&);
	
};

struct gunStats{
	
	int hit;
	int pe;
	
};


#endif
