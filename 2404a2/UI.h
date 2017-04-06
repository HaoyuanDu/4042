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

#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

#include "ProdList.h"
#include "PurchaseArray.h"
#include "Purchase.h"
#include "Customer.h"
#include <list>
#include <iterator>
#include <algorithm>

class UI
{
  public:
    
    void mainMenu(int&);
    void adminMenu(int&);
    void cashierMenu(int&);
    void productCategory(int&);
    void promptForInt(string, int&);
    void promptForStr(string, string&);
    void promptForFloat(string, float&);
    void printError(string);
    void printSuccess(string);
    void printUsageError();
    void printStock(ProdList&);
    void printCustomers(list<Customer*>&);
    void pause();

  private:
    int    readInt();
};

#endif
