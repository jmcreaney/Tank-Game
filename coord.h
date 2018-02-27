#ifndef COORD_H
#define COORD_H

struct coord{

   int Xloc;
   int Yloc;
   
   coord();
   coord(int, int);
   coord& operator = (const coord&);
   bool operator ==(coord&);     
       
};

#endif
