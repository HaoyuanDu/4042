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

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "defs.h"
#include <string>
using namespace std;
#include "PurchaseArray.h"
#include "Purchase.h"
#include "Product.h"

class Customer
{

  public:

    Customer(string="Unknown");
    int    getId();
    string getName();
    int    getPoints();
    PurchaseArray& getPurchase();
    void addPurchase(int);
    void setPoints(int,int);
  protected:
    static int nextCustId;
    int        id;
    string     name;
    int        points;
    PurchaseArray p;
    int amount;


};

#endif
