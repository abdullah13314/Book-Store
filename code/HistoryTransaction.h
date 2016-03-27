#pragma once
#include "Transaction.h"
#include <cmath>
#include <stdlib.h>

class HistoryTransaction: public Transaction
{
public:
	HistoryTransaction();
	HistoryTransaction(queue<string> stringB, HashQuadCollision *customerL);
	~HistoryTransaction();

	virtual void ExecuteTransection();

private:
	HashQuadCollision *customerList;
	//void printCustomerHistory();
};

