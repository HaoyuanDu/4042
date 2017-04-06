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

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "InvControl.h"
#include "Store.h"
#include "CustArray.h"
#include "PurchaseArray.h"

InvControl::InvControl()
{
  initProducts();
  initCustomers();
}

/*void InvControl::launch()
{
  int choice = -1;

  initCustomers();
    initProducts();

  while (1) {
    view.mainMenu(choice);
    if (choice == 1) {    // Admin menu
      processAdmin();
    }
    else if (choice == 2) { // Customer menu
      processCashier();
    }
    else {
      break;
    }
  }
}*/
void InvControl::launch(int argc, char* argv[])
{
  if (argc != 2) {
    view.printUsageError();
    exit(1);
  }
 // initCustomers();
    //initProducts();

  string option(argv[1]);

  if (option == "-a") {   // Admin menu
    processAdmin();
  }
  else if (option == "-c") {  // Cashier menu
    processCashier();
  }
  else {
    view.printUsageError();
    exit(1);
  }
}



void InvControl::processAdmin()
{
  int    choice;
  string prodName, prodSize;
  int    prodUnits, prodId, amount;
  float  prodPrice;
  int    prodlifespan;
  int    prodmfDay;
  int    prodmfMonth;
  int    prodmfYear;  
  int    category; 
  

  while (1) {
    choice = -1;
    view.adminMenu(choice);
    if (choice == 1) {		// add new product
      view.productCategory(category);
      view.promptForStr("Product name", prodName);
      view.promptForStr("Product size", prodSize);
      view.promptForInt("# units", prodUnits);
      view.promptForFloat("Price", prodPrice);
      view.promptForInt("manufactured day", prodmfDay);
      view.promptForInt("manufactured month", prodmfMonth);
      view.promptForInt("manufactured year", prodmfYear);
      if(category!=3 &&category!=5){
        view.promptForInt("lifespan", prodlifespan);
      }
      Product *prod;
      if(category == 1){
           prod = new Dairy(prodName, prodSize, prodUnits, prodPrice, prodmfDay, prodmfMonth, prodmfYear, prodlifespan);
      }
      else if(category == 2){
           prod = new Bakery(prodName, prodSize, prodUnits, prodPrice, prodmfDay, prodmfMonth, prodmfYear, prodlifespan);
      }
      else if(category == 3){
           prod = new CoffeeTea(prodName, prodSize, prodUnits, prodPrice, prodmfDay, prodmfMonth, prodmfYear);
      }
      else if(category == 4){
           prod = new Meat(prodName, prodSize, prodUnits, prodPrice, prodmfDay, prodmfMonth, prodmfYear, prodlifespan);
      }
      else if(category == 5){
           prod = new MiscGoods(prodName, prodSize, prodUnits, prodPrice, prodmfDay, prodmfMonth, prodmfYear);
      }
      store.addProd(prod);
      view.pause();
    }


    else if (choice == 2) 
    {	// add inventory
      //view.printError("Feature not implemented");
      view.promptForInt("Please enter the Product ID", prodId);
      view.promptForInt("PLease enter the add amount", amount);
      addMoreInv(prodId,amount);
    }





    else if (choice == 3) {	// print inventory
      view.printStock(store.getStock());
      view.pause();
    }
    else if (choice == 4) {	// print customers
      view.printCustomers(store.getCustomers());
      view.pause();
    }
    else {
      break;
    }
  }
}

void InvControl::processCashier()
{
  int choice;
  // int prodId, custId;
  //ask user to input customer id, and keep buying multiple product 
  while (1) {
    choice = -1;
    view.cashierMenu(choice);
    // initCustomers();
    // initProducts();
    view.printCustomers(store.getCustomers());
    view.printStock(store.getStock());

    if (choice == 1) {			// purchases
      // int stop=0;
      // while (stop!=-1){
      int prodId, custId;

        view.promptForInt("please enter customer# id", custId);


        view.promptForInt("please enter product# id, enter 0 to finish purchase", prodId);

        ////-------------------------------------------------------------
        while(prodId!=0)
        {
          pPurchase(custId,prodId);
          view.promptForInt("please enter product# id", prodId);
        }

        //pPurchase(custId,prodId);

        //----------------------------------------------------------------


        // view.promptForInt("Continue purchase? (Enter -1 to stop): ", stop);

        // cout<<"Continue purchase? (Enter -1 to stop): "<<endl;
        // cin>>stop;
      // }
      
    //view.printCustomers(store.getCustomers());

      //view.printError("Feature not implemented");
    }
    else if (choice == 2) {		// return purchases
      view.printError("Feature not implemented");
    }
    else if (choice == MAGIC_NUM) {	// print inventory and customers
      view.printStock(store.getStock());
      view.printCustomers(store.getCustomers());
      view.pause();
    }
    else {
      break;
    }
  }
}


void InvControl::pPurchase(int cd, int pd)
{
  int cusFound=0;




for(int i=0; i<store.getCustomers().getSize();i++)
      {
        if(cd==store.getCustomers().get(i)->getId())
        {
          cusFound+=1;
         
          view.printSuccess("Purchase done! ");
     

          // view.printStock(store.getStock());
          // view.pause();
       

          // add product to pucharse 

          
          Product *p = store.getStock().getById(pd);
          
            //cout<<"111111111111111111"<<endl;

            if (p!=NULL && p->getUnits()>0){
              
              p->reduceUnits();
              store.getCustomers().get(i)->setPoints(p->getPrice(),store.getCustomers().get(i)->getPoints());


              //cout<<"price:"<<store.getStock().get(j)->getPrice()<<" Total Points you have is "<<store.getCustomers().get(i)->getPoints()<<endl;
              cout<<"price:"<<p->getPrice()<<" The point you get for this Product is "<< p->getPoints()<<endl;
              cout<<"-------------------------"<<endl;
              cout<<" The point you get for todays purchase is: "<<p->getTempPoints()<<endl;



              int check=0;
              for (int k=0;k<store.getCustomers().get(i)->getPurchase().getSize();++k){
               // cout<<"22222222222"<<endl;
                if (store.getCustomers().get(i)->getPurchase().get(k)->getId()==pd){
                 // cout<<"33333333333"<<endl;
                  store.getCustomers().get(i)->getPurchase().get(k)->addUnits();
                  check=10;
                }

              }
               cout<<"-----------------"<<endl;
              if (check==0){
                //view.printSuccess("Your adding new Purchase!");
                
                Purchase *p1=new Purchase(pd, 1);
                store.getCustomers().get(i)->getPurchase().add(p1);
                view.printSuccess("Purchase has been made!");
              }
            }
          }
        

       }
      
        if (cusFound==0){
          exit(1);
          cout<<"Error input customer id,please try again "<<endl;
        }
}

void InvControl::addMoreInv(int id, int amt)
{
  Product *p = store.getStock().getById(id);
	
		if(p != NULL)
		{
			p->addUnits(amt);
      
		}

	
  view.printSuccess("inventory added");
  //cout<<"inventory added"<<endl;
}


void InvControl::initProducts()
{
  /*
     This function is so ugly!  It's because we're using 
     statically allocated memory, instead of dynamically
     alloated.  Don't worry, we'll fix this in Assignment #2.
  */

  Product *prod01 = new MiscGoods("Sudzzy Dish Soap", "1 L", 10, 3.99f,5,1,2017);
  store.addProd(prod01);

  Product *prod02 = new MiscGoods("Peachy Laundry Soap", "2 L", 3, 8.99f,5,6,2017);
  store.addProd(prod02);
  Product *prod03 = new Meat("Daisy's Spicy Chili", "150 g", 5, 1.29f,12,10,2016,250);
  store.addProd(prod03);

  Product *prod04 = new Bakery("Daisy's Maple Baked Beans", "220 g", 2, 2.49f,15,10,2016,199);
  store.addProd(prod04);

  Product *prod05 = new Meat("Marmaduke Hot Dogs", "12-pack", 4, 4.99f,17,9,2016,266);
  store.addProd(prod05);

  Product *prod06 = new Meat("Garfield Hamburger Patties", "900 g", 2, 11.99f,9,9,2017,250);
  store.addProd(prod06);

  Product *prod07 = new Dairy("Chunky Munkey Ice Cream", "2 L", 1, 2.97f,9,9,2017,250);
  store.addProd(prod07);

  Product *prod08 = new Dairy("It's Your Bday Chocolate Cake", "500 g", 0, 12.99f,9,9,2017,250);
  store.addProd(prod08);

  Product *prod09 = new Bakery("Happy Baker's Hot dog buns", "12-pack", 5, 3.49f,9,9,2017,250);
  store.addProd(prod09);

  Product *prod10 = new Bakery("Happy Baker's Hamburger buns", "8-pack", 8, 3.99f,9,9,2017,250);
  store.addProd(prod10);

  Product *prod11 = new Dairy("Moo-cow 2% milk", "1 L", 7, 2.99f,9,9,2017,250);
  store.addProd(prod11);

  Product *prod12 = new Dairy("Moo-cow 2% milk", "4 L", 3, 4.99f,9,9,2017,250);
  store.addProd(prod12);

  Product *prod13 = new CoffeeTea("Moo-cow 5% coffee cream", "250 ml", 4, 1.49f,9,9,2017);
  store.addProd(prod13);

  Product *prod14 = new CoffeeTea("Mocha", "400 g", 2, 5.49f,9,9,2017);
  store.addProd(prod14);

  Product *prod15 = new CoffeeTea("Lightening Bolt Instant Coffee", "150 g", 8, 4.99f,9,9,2017);
  store.addProd(prod15);

  Product *prod16 = new CoffeeTea("Lightening Bolt Decaf Coffee", "100 g", 2, 4.99f,9,9,2017);
  store.addProd(prod16);

  Product *prod17 = new MiscGoods("Munchies BBQ Chips", "250 g", 7, 2.99f,9,9,2017);
  store.addProd(prod17);

  Product *prod18 = new MiscGoods("Munchies Ketchup Chips", "250 g", 3, 2.99f,9,9,2017);
  store.addProd(prod18);

  Product *prod19 = new MiscGoods("Dogbert Salted Chips", "210 g", 4, 1.99f,9,9,2017);
  store.addProd(prod19);

  Product *prod20 = new MiscGoods("Dogbert Sweet and Spicy Popcorn", "180 g", 5, 2.29f,9,9,2017);
  store.addProd(prod20);

}

void InvControl::initCustomers()
{
  Customer* cust01 = new Customer("Starbuck");
  Customer* cust02 = new Customer("Apollo");
  Customer* cust03 = new Customer("Boomer");
  Customer* cust04 = new Customer("Athena");
  Customer* cust05 = new Customer("Helo");
  Customer* cust06 = new Customer("Crashdown");
  Customer* cust07 = new Customer("Hotdog");
  Customer* cust08 = new Customer("Kat");
  Customer* cust09 = new Customer("Chuckles");
  Customer* cust10 = new Customer("Racetrack");

  store.addCust(cust01);
  store.addCust(cust02);
  store.addCust(cust03);
  store.addCust(cust04);
  store.addCust(cust05);
  store.addCust(cust06);
  store.addCust(cust07);
  store.addCust(cust08);
  store.addCust(cust09);
  store.addCust(cust10);
}

