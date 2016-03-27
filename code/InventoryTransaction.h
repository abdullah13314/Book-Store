#pragma once
#include "Transaction.h"
#include <cmath>
#include <stdlib.h>

class InventoryTransaction: public Transaction
{
public:
	InventoryTransaction();
	InventoryTransaction(BST* pAudioBooksInventoryT, BST* pOtherBooksInventoryT);

	~InventoryTransaction();
	virtual void ExecuteTransection();

private: 
	BST* pAudioBooksInventoryTree;
	BST* pOtherBooksInventoryTree;
};

