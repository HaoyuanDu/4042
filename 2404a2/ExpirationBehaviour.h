#ifndef EXPIRATIONBEHAVIOUR_H
#define EXPIRATIONBEHAVIOUR_H
#include "Date.h"
#include "defs.h"
class ExpirationBehaviour
{
  public:
    virtual Date computeExpDate(Date&,int) = 0;
};

class Perishable : public ExpirationBehaviour
{
  public:
    virtual Date computeExpDate(Date&,int);
};

class NonPerishable : public ExpirationBehaviour
{
  public:
    virtual Date computeExpDate(Date&,int);
};



#endif
