#include "stdafx.h"
#include "InventoryTransaction.h"


InventoryTransaction::InventoryTransaction()
{
	pAudioBooksInventoryTree = NULL;
	pOtherBooksInventoryTree = NULL;
}

InventoryTransaction::InventoryTransaction(BST * pAudioBooksInventoryT, BST * pOtherBooksInventoryT)
{
	pAudioBooksInventoryTree = pAudioBooksInventoryT;
	pOtherBooksInventoryTree = pOtherBooksInventoryT;
}


InventoryTransaction::~InventoryTransaction()
{
}

void InventoryTransaction::ExecuteTransection()
{
	cout << "Audio Books: " << endl;
	cout << (*pAudioBooksInventoryTree) << endl;
	cout << "Standard Books and Graphic Novels: " << endl;
	cout << (*pOtherBooksInventoryTree) << endl;
}
