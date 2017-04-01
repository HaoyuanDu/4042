#include <string>
#include <cstdlib>
using namespace std;

#include "PurchaseArray.h"
#include "defs.h"
#include <string>
#include "Purchase.h"

PurchaseArray::~PurchaseArray()
{
	for (int i = 0; i < size; ++i)
	{
		delete pElements[i];
	}
}

PurchaseArray::PurchaseArray()
{
  size = 0;
}

int PurchaseArray::getSize() { return size; }

Purchase* PurchaseArray::get(int index)
{
  if (index < 0 || index >= size){
	return NULL;
  } else {
	return pElements[index];
  }
}

void PurchaseArray::add(Purchase* pur)
{
  if (size >= MAX_ARR)
    return;

  pElements[size++] = pur;
}

