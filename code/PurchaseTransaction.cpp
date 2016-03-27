#include "stdafx.h"
#include "PurchaseTransaction.h"


PurchaseTransaction::PurchaseTransaction()
{
	pBooksInventoryHash = NULL;
	customerList = NULL;
}

PurchaseTransaction::PurchaseTransaction(queue<string> stringB, HashQuadCollision * customerL, HashChaining * pBooksInventoryH)
{
	stringBroken = stringB;
	pBooksInventoryHash = pBooksInventoryH;
	customerList = customerL;
}


PurchaseTransaction::~PurchaseTransaction()
{
}

void PurchaseTransaction::ExecuteTransection()
{
	string firstName = stringBroken.front();
	stringBroken.pop();
	string lastName = stringBroken.front();
	stringBroken.pop();

	Customer *pC = (*customerList).Retrive(firstName, lastName);

	//cout << "Hello World";

	if (pC == NULL)
	{
		cerr << "Customer does not exist. " << endl;
		return;
	}

	char token = (stringBroken.front()).at(0);

	stringBroken.pop();
	bool isNew;
	char condition;
	string title, author, narrator, artist;
	Book *pBook;
	switch (token)
	{
	case 'B':
	{
		token = (stringBroken.front()).at(0);
		stringBroken.pop();

		if (token == 'N')
		{
			isNew = true;
			//cout << "New Book" << endl;
		}
		else
		{
			isNew = false;
		}

		author = stringBroken.front();
		stringBroken.pop();

		title = stringBroken.front();
		stringBroken.pop();

		
		if (!isNew)
		{
			condition = (stringBroken.front()).at(0);
			stringBroken.pop();
		}
		pBook = new Book(title, author);
		break;

	}
	case 'G':
	{
		token = (stringBroken.front()).at(0);
		stringBroken.pop();

		if (token == 'N')
		{
			isNew = true;
			//cout << "New Book" << endl;
		}
		else
		{
			isNew = false;
		}

		author = stringBroken.front();
		stringBroken.pop();

		title = stringBroken.front();
		stringBroken.pop();

		artist = stringBroken.front();
		stringBroken.pop();

		if (!isNew)
		{
			condition = (stringBroken.front()).at(0);
			stringBroken.pop();
		}
		pBook = new GraphicNovel(title, author, artist);
		break;

	}
	case 'A':
	{
		token = (stringBroken.front()).at(0);
		stringBroken.pop();

		if (token == 'N')
		{
			isNew = true;
			//cout << "New Book" << endl;
		}
		else
		{
			isNew = false;
		}

		author = stringBroken.front();
		stringBroken.pop();

		title = stringBroken.front();
		stringBroken.pop();

		artist = stringBroken.front();
		stringBroken.pop();

		if (!isNew)
		{
			condition = (stringBroken.front()).at(0);
			stringBroken.pop();
		}
		pBook = new AudioBook(title, author, narrator);
		break;
	}
	default:
	{
		cerr << "Invalid Input." << endl;
		return;
	}
	}

	BookBlock *pBB;
	if (!((*pBooksInventoryHash).Retrive(pBB, pBook)))
	{
		cerr << "Book doesn't exist in inventory. " << endl;
		return;
	}
	double cost;
	if (isNew)
	{
		if ((*pBB).getnewCount() < 1)
		{
			cerr << "We are out of this book. " << endl;
			return;
		}
		cost = (*pBB).getNewCost();
		(*pBB).setnewCount((*pBB).getnewCount()-1);
	}
	else
	{
		switch (condition)
		{
		case 'E':
		{
			if ((*pBB).getUsedExcellentCount() < 1)
			{
				cerr << "We are out of this book. " << endl;
				return;
			}
			cost = (*pBB).getUsedExcellentCost();
			(*pBB).setUsedExcellentCount( (*pBB).getUsedExcellentCount() - 1);
			break;

		}
		case 'G':
		{
			if ((*pBB).getUsedGoodCount() < 1)
			{
				cerr << "We are out of this book. " << endl;
				return;
			}
			cost = (*pBB).getUsedGoodCost();

			(*pBB).setUsedGoodCount( (*pBB).getUsedGoodCount() - 1);
			break;

		}
		case 'F':
		{
			if ((*pBB).getUsedFairCount() < 1)
			{
				cerr << "We are out of this book. " << endl;
				return;
			}
			cost = (*pBB).getUsedFairCost();

			(*pBB).setUsedFairCount((*pBB).getUsedFairCount() - 1);
			break;

		}
		}
	}
	
	(*pC).purchaseBook(pBook, cost);
	delete pBook;
	
	if (((*pC).getBalance() > 200) && (!isSeniorCustomer(pC)) && (!isGoldCustomer(pC)))
	{
		//cout << "Hello World" << endl;
		Customer *c1 = new GoldCustomer();
		(*c1).setBalance((*pC).getBalance());
		(*c1).setBookBoughtCost((*pC).getBookBoughtCost());
		(*c1).setBookTitleBought((*pC).getBookTitleBought());
		(*c1).setFirstName((*pC).getFirstName());
		(*c1).setHistory((*pC).getHistory());
		(*c1).setIsBookAudio((*pC).getIsBookAudio());
		(*c1).setLastName((*pC).getLastName());
		if ((*customerList).Remove((*pC).getFirstName(), (*pC).getLastName()))
		{
			//cout << "Hello World";
			(*customerList).Add(c1);
		}

	}
	//cout << "Hello World";

}
