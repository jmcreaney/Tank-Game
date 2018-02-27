#ifndef ATORDER_H
#define ATORDER_H




struct atOrder{
	
	char cntry;
	
	int atLn;
	int dfLn;
	
	int atDB;
	int dfDB;
	
	int fireFactor;
	
	atOrder(int);
	
	bool addTarget(int);
	
	bool hit;
	bool pen;
	bool imb;
	
};

#endif
