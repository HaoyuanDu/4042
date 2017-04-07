#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

#include "ProdList.h"


ProdList::ProdList():head(NULL), tail(NULL)
{

}

ProdList::~ProdList(){
	cout << "Product Destr" << endl;
	Node *currNode;
	Node *prevNode;
	int n = 0;

	currNode = head;
	prevNode = NULL;

	if(head != NULL) {
		while(currNode != NULL) {
			prevNode = currNode;
			currNode = currNode->next;
			delete prevNode->product;
			delete prevNode;
			n++;
			cout<<n<<endl;

		}
	}
}

int ProdList::getSize(){
	int size = 0;
	Node *currNode;
	
	if(head == NULL) {
		return 0;	
	} else {
		currNode = head;
		while(currNode != NULL) {
			size++;
			currNode = currNode->next;
		}

		return size;
	}
}

Product *ProdList::getById(int id){
	Node* currNode = head;
	Product* prod;

	while(currNode != NULL){
		prod = currNode->product;
		if(prod->getId() == id)
			return currNode->product;
		currNode = currNode->next;
	}

	return NULL;

}

void ProdList::add(Product *prod) {
	Node* currNode;
	Node* newNode;

	newNode = new Node;
	newNode->product = prod;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if(head != NULL) {
		tail->next = newNode;
		newNode-> prev = tail;
		tail = newNode;
		
	} else {
		head = newNode;
		tail = newNode;
	}

	ProdList::reorg();

}

void ProdList::remove(int id)
{
	Node *currNode = head;
	Node *prevNode = NULL;

	while (currNode != NULL) {
		if(currNode->product->getId() == id) {
			currNode->prev->next = currNode->next;
			currNode->next->prev = currNode->prev;
			break;

		}
		currNode = currNode->next;
	}


	if(currNode == NULL)   
		return;

	if(currNode == head) {
		if(currNode->next != NULL){
			head = currNode->next;
		} else {
			head = NULL;
			tail = NULL;
		}
	}

	delete currNode->product;
	delete currNode;
}

void ProdList::toString(string& outStr){

	Node* currNode = head;
	string s;
	stringstream ss;
	Product* prod;

	while(currNode != NULL) {
		prod = currNode->product;
		ss<<"ID: "<< prod->getId() << "    Name: " << prod->getName() << "    Size: " << prod->getSize() << "    Units: " << prod->getUnits() << "    Price: $" << prod->getPrice() <<  "   ExpireDate: ";
		prod->getExpireDate().toString(s);
		ss<< s <<endl;
		currNode = currNode->next;

	}

	/*
	while(currNode != NULL){
		prod = currNode->product;
		if(prod->getAcctType() == CHEQUING)
			ss << "Chequing ";
		else if(acct->getAcctType() == SAVINGS)
			ss << "Savings: ";
		else
			ss << "General: ";
		ss << ""prod->getId()
		ss << acct->getAcctNum()<<"    "<<setw(4)<<acct->getCust()->getName()<<" ";
		ss <<" $"<< setw(8) << fixed << setprecision(2) << acct->getBalance()<<endl;

		currNode = currNode->next;
	}
	*/
	
	outStr = ss.str();

}

void ProdList::reorg(){
        Node* currNode;
        Node* temp;

        currNode = head;

	while(currNode != NULL) {
		temp  = currNode->next;
		while( temp != NULL) {
			if(temp->product->getExpireDate() > currNode->product->getExpireDate()) {
				if(currNode == head) {
					break;
				} else {
					if(currNode->prev != NULL) {
						currNode->prev->next = currNode->next;
						currNode->next->prev = currNode->prev;	
					} else {
						currNode->next->prev = NULL;
					}

					currNode->next = temp;
					temp->prev->next = currNode;
					currNode->prev = temp->prev;
					temp->prev = currNode;
					break;
				}
				
				
			}

			if(temp->next == NULL) {
				if(currNode->prev != NULL) {
					currNode->prev->next = currNode->next;
					currNode->next->prev = currNode->prev;
				} else {
					currNode->next->prev = NULL;
				}
				
				temp->next = currNode;
				currNode->prev = temp;
				currNode->next = NULL;
				tail = currNode;

				break;
			}

			temp = temp->next;
			
		}
			
		currNode = currNode->next;
	}

}

