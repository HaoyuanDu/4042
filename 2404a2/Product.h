/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PRODUCT_H
#define PRODUCT_H
#include "Date.h"
#include "defs.h"
#include "TaxationBehaviour.h"
#include "ExpirationBehaviour.h"
#include <string>
using namespace std;

class Product
{
  public:
    ~Product();
    Product(string="Unknown", string="Unknown", int=0, float=0.0f, int=0, int=0, int=0, int=0);
    int    getId();
    string getName();
    string getSize();
    int    getUnits();
    int    getPoints();
    float  getPrice();
    Date&   getExpireDate();
    void setUnits();
    void reduceUnits();
    int addUnits(int);
    int getTempPoints();
    float computeTax();
    void computeExpDate();
  protected:
    static int nextProdId;
    int        id;
    string     name;
    string     size;
    int        units;
    float      price;
    Date        mfDate;
    Date        eDate;
    int        lifespan;
    TaxationBehaviour *taxB;
    ExpirationBehaviour *expB;
};


class Dairy : public Product{
public:
    Dairy(string n, string s, int u, float p, int d, int m, int y,int sp) : Product(n,s,u,p,d,m,y,sp)
    {
        expB = new Perishable();
        taxB = new NonTaxable();
        computeExpDate();

    }

};

class CoffeeTea : public Product{
    public:
    CoffeeTea(string n, string s, int u, float p, int d, int m, int y) : Product(n,s,u,p,d,m,y,MAX_EXP)
    {
        expB = new NonPerishable();
        taxB = new Taxable();
        computeExpDate();
    }
};



class Bakery : public Product{
    public:
    Bakery(string n, string s, int u, float p, int d, int m, int y,int sp) : Product(n,s,u,p,d,m,y,sp)
    {
        expB = new Perishable();
        taxB = new Taxable();
        computeExpDate();
    }
};



class Meat : public Product{
    public:
    Meat(string n, string s, int u, float p, int d, int m, int y,int sp) : Product(n,s,u,p,d,m,y,sp)
    {
        expB = new Perishable();
        taxB = new NonTaxable();
        computeExpDate();
    }
};



class MiscGoods : public Product{
    public:
    MiscGoods(string n, string s, int u, float p, int d, int m, int y) : Product(n,s,u,p,d,m,y,MAX_EXP)
    {
        expB = new NonPerishable();
        taxB = new NonTaxable();
        computeExpDate();
    }
};


#endif
