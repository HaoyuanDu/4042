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

#include <cmath>
#include "Customer.h"
#include "defs.h"
#include <string>
using namespace std;
#include "PurchaseArray.h"
#include "Purchase.h"
#include "Product.h"

int Customer::nextCustId = 2001;

Customer::Customer(string n)
{ 
  id     = nextCustId++;
  name   = n;
  points = 0;
}

int    Customer::getId()     { return id;     }
string Customer::getName()   { return name;   }
int    Customer::getPoints() { return points; }
PurchaseArray& Customer::getPurchase(){return p;}

void Customer::addPurchase(int idd) {
	int x=0;
	for (int i = 0; i < p.getSize(); ++i)
	{
		if (p.get(i)->getId() == idd)
		{

			p.get(i)->addUnits();
			x=10;
		}
		
	}

	if (x == 0)
	{
		Purchase *newPur = new Purchase(idd, 1);
		p.add(newPur);
	}

}


void    Customer::setPoints(int n1,int n2) { points=n1+n2; }
