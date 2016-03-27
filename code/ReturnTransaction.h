#pragma once
#include "Transaction.h"
#include <cmath>
#include <stdlib.h>

class ReturnTransaction: public Transaction
{
public:
	ReturnTransaction();
	ReturnTransaction(queue<string> stringB, HashQuadCollision *customerL, HashChaining* pBooksInventoryH);
	~ReturnTransaction();

	virtual void ExecuteTransection();

private:
	HashChaining* pBooksInventoryHash;
	HashQuadCollision *customerList;
};

