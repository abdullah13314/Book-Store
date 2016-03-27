#include "stdafx.h"
#include "BookStore.h"


BookStore::BookStore()
{
}

BookStore::BookStore(string f1, string f2, string f3)
{
	fileNameCustomer = f1;
	fileNameInventory = f2;
	fileNameCommand = f3;
}


BookStore::~BookStore()
{
	(*customerList).Clear();
	(*pAudioBooksInventoryTree).Clear();
	(*pOtherBooksInventoryTree).Clear();
	(*booksInventoryHash).Clear();
	delete pAudioBooksInventoryTree;
	delete pOtherBooksInventoryTree;
	delete booksInventoryHash;
	delete customerList;

}

void BookStore::setFileNames(string f1, string f2, string f3)
{
	fileNameCustomer = f1;
	fileNameInventory = f2;
	fileNameCommand = f3;
}

void BookStore::setStorebalance(double c)
{
	storeBalance = c;
}

double BookStore::getStorebalance() const
{
	return storeBalance;
}

void BookStore::BuildCustomerList()
{
	CustomerManagement c;
	c.setFileName(fileNameCustomer);
	c.CreateCustomerList();
	customerList = c.getPointerCustomerList();
	//(*customerList).PrintAllCustomers();
}

void BookStore::BuildInventory()
{
	InventoryManagement i;
	i.setFileName(fileNameInventory);
	i.CreateInventory();
	booksInventoryHash = i.getPBooksInventoryHash();
	pAudioBooksInventoryTree = i.getPAudioBooksInventoryTree();
	pOtherBooksInventoryTree = i.getPOtherBooksInventoryTree();


}

void BookStore::CreateTransactions()
{
	fstream myFile;
	char line[MAX_LINE_SIZE3];
	char delim = ',';
	//BookBlock* bb[10];
	//int count = 0;

	myFile.open(fileNameCommand);
	if (!myFile.is_open())
	{
		cout << "File not found!" << endl;
	}
	else
	{

		char token[MAX_TITLE3];
		
		while (myFile.getline(line, MAX_LINE_SIZE3))
		{
			queue<string> stringB;
			Transaction * t1;
			stringstream ss;
			ss << line;
			//cout << line << endl;
			ss.getline(token, MAX_TITLE3, ',');
			//cout << token << endl;
			switch (token[0])
			{
			case 'I':
			{
				t1 = new InventoryTransaction(pAudioBooksInventoryTree, pOtherBooksInventoryTree);
				transactionQueue.push(t1);

				break;
			}
			case 'H':
			{
				while (ss.getline(token, MAX_TITLE3, ','))
				{
					stringB.push(token);
				}
				t1 = new HistoryTransaction(stringB, customerList);
				transactionQueue.push(t1);

				break;
			}
			case 'P':
			{
				//cout << "Hello World" << endl;
				while (ss.getline(token, MAX_TITLE3, ','))
				{
					stringB.push(token);
				}
				t1 = new PurchaseTransaction(stringB, customerList, booksInventoryHash);
				transactionQueue.push(t1);

				break;
			}
			case 'R':
			{
				while (ss.getline(token, MAX_TITLE3, ','))
				{
					stringB.push(token);
				}

				t1 = new ReturnTransaction(stringB, customerList, booksInventoryHash);
				transactionQueue.push(t1);
				break;
			}
			case 'T':
			{
				while (ss.getline(token, MAX_TITLE3, ','))
				{
					stringB.push(token);
				}
				t1 = new TradeInTransaction(stringB, customerList, booksInventoryHash, pAudioBooksInventoryTree, pOtherBooksInventoryTree);
				transactionQueue.push(t1);
				break;
			}

			default:
			{
				cerr << "Invalid data. " << endl;
			}
			}
		}
	}
}

void BookStore::RunTransaction()
{
	while (transactionQueue.size() != 0)
	{
		Transaction * t1 = transactionQueue.front();
		(*t1).ExecuteTransection();
		transactionQueue.pop();
		delete t1;
	}
}

bool BookStore::operator==(const BookStore & bStore) const
{
	if ((this->booksInventoryHash == bStore.booksInventoryHash) && (this->pAudioBooksInventoryTree == bStore.pAudioBooksInventoryTree) && (this->pOtherBooksInventoryTree == bStore.pOtherBooksInventoryTree) && (this->customerList == bStore.customerList) && (this->storeBalance == bStore.storeBalance) && (this->transactionQueue == bStore.transactionQueue))
	{
		return true;
	}
	return false;
}

bool BookStore::operator!=(const BookStore & bStore) const
{
	if ((this->booksInventoryHash == bStore.booksInventoryHash) && (this->pAudioBooksInventoryTree == bStore.pAudioBooksInventoryTree) && (this->pOtherBooksInventoryTree == bStore.pOtherBooksInventoryTree) && (this->customerList == bStore.customerList) && (this->storeBalance == bStore.storeBalance) && (this->transactionQueue == bStore.transactionQueue))
	{
		return false;
	}
	return true;
}
