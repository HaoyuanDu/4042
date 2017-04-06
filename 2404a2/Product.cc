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
using namespace std;
#include "Product.h"

int Product::nextProdId = 5001;
int i=0;
Product::Product(string n, string s, int u, float p, int d, int m, int y, int sp)
{ 
  id    = nextProdId++;
  name  = n;
  size  = s;
  units = (u >= 0) ? u : 0;
  price = (p >= 0) ? p : 0;
  mfDate = Date(d, m, y);
  lifespan = (sp >= 0) ? sp: 0;


}
int    Product::getTempPoints()    { return i;    }
int    Product::getId()    { return id;    }
string Product::getName()  { return name;  }
string Product::getSize()  { return size;  }
int    Product::getUnits() { return units; }
Date&   Product::getExpireDate(){return eDate;}
float  Product::getPrice() { return price+computeTax(); }

Product::~Product(){
 
      delete expB;
      delete taxB;
    }
 

int Product::getPoints()
{
	i+=price;
	return price;
}
void   Product::reduceUnits() { units-=1; }
float   Product::computeTax() {
  return taxB-> computeTax(price);

}
void   Product::computeExpDate(){
  eDate = expB->computeExpDate(mfDate,lifespan);



}
int Product::addUnits(int newU){return units+=newU;}
/*Product::Product(string n, string s, int u, float p, int m, int e, int l) : Product(n,s,u,p,m,e,l){}
Product::Product(string n, string s, int u, float p, int m, int e, int l) : Product(n,s,u,p,m,e,l){}
Product::Product(string n, string s, int u, float p, int m, int e, int l) : Product(n,s,u,p,m,e,l){}
Product::Product(string n, string s, int u, float p, int m, int e, int l) : Product(n,s,u,p,m,e,l){}
Product::Product(string n, string s, int u, float p, int m, int e, int l) : Product(n,s,u,p,m,e,l){}
*/

