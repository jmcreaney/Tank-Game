

#ifndef MVORDER_H
#define MVORDER_H

struct mvOrder{
	
	char cntry;
	
	int player;
	
	int lnNumber;
	int DBI;
	
	int direction;
	int speed;
	bool align;
	
	mvOrder(int,int,int,bool);
	void resolve();
};

#endif





