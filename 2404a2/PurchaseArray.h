#ifndef PURCHASEARRAY_H
#define PURCHASEARRAY_H

#include "defs.h"
#include <string>
#include "Purchase.h"
using namespace std;


class PurchaseArray
{
  public:
    PurchaseArray();
    ~PurchaseArray();
    void add(Purchase*);
    Purchase* get(int);
    int getSize();
   

  protected:

    Purchase* pElements[MAX_ARR];
    int size;
};
#endif