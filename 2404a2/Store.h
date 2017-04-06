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

#ifndef STORE_H
#define STORE_H

#include "ProdList.h"
#include "Product.h"
#include "Customer.h"
#include <list>
#include <iterator>
#include <algorithm>
class Store
{
  public:
    void       addProd(Product*);
    void       addCust(Customer*);
    ProdList& getStock();
    list<Customer*>& getCustomers();
  private:
    ProdList  stock;
    list<Customer*>  customers;
};

#endif
