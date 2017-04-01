#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>
using namespace std;

class Purchase
{
  public:
    Purchase(int=0,int=0);

    int    getId();
    int    getUnits();
    void    addUnits();
  protected:
    int        id;
    int        units;
};
#endif