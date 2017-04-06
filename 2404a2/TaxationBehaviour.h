#ifndef TAXATIONBEHAVIOUR_H
#define TAXATIONBEHAVIOUR_H

class TaxationBehaviour
{
  public:
    virtual float computeTax(float) = 0;
};

class Taxable : public TaxationBehaviour
{
  public:
    virtual float computeTax(float);
};

class NonTaxable : public TaxationBehaviour
{
  public:
    virtual float computeTax(float);
};



#endif
