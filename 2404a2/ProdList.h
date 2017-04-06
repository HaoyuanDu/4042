#ifndef PRODLIST_H
#define PRODLIST_H

#include "defs.h"
#include "Product.h"


class ProdList{
	public:
		ProdList();
		~ProdList();
		void add(Product *);
		void remove(int);
		int getSize();
		Product *getById(int);
		void reorg();
		void toString(string& outStr);
	private:
		class Node{
			friend class ProdList;
			private:
				Product *product;
				Node *next;
				Node *prev;
		};
		
		Node* head;
		Node* tail;
};

#endif
