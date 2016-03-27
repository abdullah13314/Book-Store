#pragma once
#include "Transaction.h"
#include <cmath>
#include <stdlib.h>

class TradeInTransaction : public Transaction
{
public:
	TradeInTransaction();
	TradeInTransaction(queue<string> stringB, HashQuadCollision *customerL, HashChaining* pBooksInventoryH, BST* pAudioBooksInventoryTree, BST* pOtherBooksInventoryTree);
	~TradeInTransaction();
	virtual void ExecuteTransection();

private:
	HashChaining* pBooksInventoryHash;
	BST* pAudioBooksInventoryTree;
	BST* pOtherBooksInventoryTree;
	HashQuadCollision *customerList;
	bool isAudioBook(Book * pBook);

};

