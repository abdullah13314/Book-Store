#pragma once
#include <queue>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include "CustomerManagement.h"
#include "InventoryManagement.h"
#include "Transaction.h"
#include "InventoryTransaction.h"
#include "HistoryTransaction.h"
#include "PurchaseTransaction.h"
#include "ReturnTransaction.h"
#include "TradeInTransaction.h"


using namespace std;
const int MAX_LINE_SIZE3 = 2048;
const int MAX_TITLE3 = 256;

using namespace std;
class BookStore
{
	//Prints inventory and the balance of the book store
	friend ostream& operator<<(ostream &outstream, BookStore bStore);
public:
	BookStore();
	BookStore(string fileNameCustomer, string fileNameInventory, string fileNameCommand);
	~BookStore();

	void setFileNames(string fileNameCustomer, string fileNameInventory, string fileNameCommand);
	void setStorebalance(double c);

	double getStorebalance() const;

	void BuildCustomerList();
	void BuildInventory();
	void CreateTransactions();
	void RunTransaction();

	bool operator==(const BookStore &bStore) const;
	bool operator!=(const BookStore &bStore) const;


private:
	string fileNameCustomer, fileNameInventory, fileNameCommand;
	HashQuadCollision *customerList;
	HashChaining* booksInventoryHash;
	BST* pAudioBooksInventoryTree;
	BST* pOtherBooksInventoryTree;
	queue<Transaction *> transactionQueue;
	double storeBalance;
};

