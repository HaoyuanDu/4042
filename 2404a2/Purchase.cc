#include "Purchase.h"




Purchase::Purchase(int i, int u)
{ 
  
  id  = i;
  units = u;
}

int    Purchase::getId()    { return id;    }
int    Purchase::getUnits() { return units; }

void Purchase::addUnits(){units++;}

