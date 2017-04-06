


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

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "UI.h"
using namespace std;


#include "PurchaseArray.h"
#include "Purchase.h"


void UI::adminMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM ADMIN MENU\n\n";
  cout<< "          1. Add new product \n\n";
  cout<< "          2. Add more inventory \n\n";
  cout<< "          3. Print inventory \n\n";
  cout<< "          4. Print customers \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 4) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void UI::productCategory(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n          Choose product category\n\n";
  cout<< "          1. Dairy \n\n";
  cout<< "          2. Bakery \n\n";
  cout<< "          3. CoffeeTea \n\n";
  cout<< "          4. Meat \n\n";
  cout<< "          5. MiscGoods\n\n";

  while (choice < 1 || choice > 5) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}
void UI::cashierMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM CASHIER MENU\n\n";
  cout<< "          1. Product purchases\n\n";
  cout<< "          2. Product returns\n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 2) {
    cout << "Enter your selection:  ";
    choice = readInt();
    if (choice == MAGIC_NUM) return;
  }
}

void UI::printStock(ProdList& arr)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.
  string s;
  
  arr.toString(s);
  cout << endl << "STOCK: " << endl << endl;
  cout << s << endl;
  cout << " --                                 ----             ----    ---    -----" << endl;

 } 

void UI::printCustomers(list<Customer*>& arr)
{
  cout << endl << "CUSTOMERS: " << endl << endl;
  for(list<Customer*>::iterator list_iter = arr.begin(); list_iter != arr.end(); list_iter++)
  {

    Customer* cust = *list_iter;
    cout<<cust->getId()<<"  "<<setw(10)<<cust->getName()
         << "  " << setw(4) << cust->getPoints() << endl;

         for (int j=0;j<cust->getPurchase().getSize();++j){
          cout<<"     Product id: "<<cust->getPurchase().get(j)->getId()<<", Units brought: "<<cust->getPurchase().get(j)->getUnits()<<endl;
         }
  }

}

/*void UI::userfound()
{
  cout<<"user found"<<endl;
}

void UI::addingNewPurchase
{
  cout<<"I am adding new Purchase!!!"<<endl;

}
*/
void UI::printSuccess(string err)
{
  cout << endl << err << "  -- press enter to continue...";
  cin.get();
}

void UI::printError(string err)
{
  cout << endl << err << " -- press enter to continue...";
  cin.get();
}

void UI::printUsageError()
{
  cout << endl << "Usage:  cushop OPTION" << endl << endl;
  cout <<         "        where OPTION is either: " << endl;
  cout <<         "              -a  Admin menu"        << endl;
  cout <<         "              -c  Cashier menu"      << endl << endl;
}

void UI::promptForInt(string prompt, int& num)
{
  cout << prompt << ": ";
  num = readInt();
}

void UI::promptForStr(string prompt, string& str)
{
  cout << prompt << ": ";
  getline(cin, str);
}

void UI::promptForFloat(string prompt, float& num)
{
  string str;

  cout << prompt << ": ";
  getline(cin, str);

  stringstream ss(str);
  ss >> num;
}

int UI::readInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

void UI::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}



