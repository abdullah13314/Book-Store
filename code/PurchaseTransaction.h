#pragma once
#include "Transaction.h"
//#include "GoldCustomer.h"
#include <cmath>
#include <stdlib.h>

class PurchaseTransaction: public Transaction
{
public:
	PurchaseTransaction();
	PurchaseTransaction(queue<string> stringB, HashQuadCollision *customerL, HashChaining* pBooksInventoryH);
	~PurchaseTransaction();

	virtual void ExecuteTransection();

private:
	HashChaining* pBooksInventoryHash;
	HashQuadCollision *customerList;
};

