OBJ = main.o InvControl.o Store.o Product.o UI.o ProdList.o Date.o ExpirationBehaviour.o  TaxationBehaviour.o Customer.o PurchaseArray.o Purchase.o

cushop:	$(OBJ)
	g++ -o cushop $(OBJ)

main.o:	main.cc 
	g++ -c main.cc

InvControl.o:	InvControl.cc InvControl.h Store.h UI.h
	g++ -c InvControl.cc

UI.o:	UI.cc UI.h 
	g++ -c UI.cc

Order.o:	Order.cc Order.h 
	g++ -g -c Order.cc

OrderArray.o:	OrderArray.cc OrderArray.h 
	g++ -g -c OrderArray.cc

OrderServer.o:	OrderServer.cc OrderServer.h 
	g++ -g -c OrderServer.cc

Date.o:	Date.cc Date.h defs.h
	g++ -c Date.cc


TaxationBehaviour.o:	TaxationBehaviour.cc TaxationBehaviour.h   
	g++ -c TaxationBehaviour.cc


ExpirationBehaviour.o:	ExpirationBehaviour.cc ExpirationBehaviour.h Date.h defs.h
	g++ -c ExpirationBehaviour.cc


Store.o:	Store.cc Store.h ProdList.h Customer.h 
	g++ -c Store.cc

Product.o:	Product.cc Product.h Date.h defs.h
	g++ -c Product.cc

ProdList.o:	ProdList.cc ProdList.h Product.h defs.h Date.h

	g++ -c ProdList.cc


Customer.o:	Customer.cc Customer.h 
	g++ -c Customer.cc

PurchaseArray.o:	PurchaseArray.cc PurchaseArray.h Purchase.h defs.h
	g++ -c PurchaseArray.cc

Purchase.o:	Purchase.cc Purchase.h 
	g++ -c Purchase.cc




clean:
	rm -f $(OBJ) cushop
