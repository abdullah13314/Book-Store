#include "stdafx.h"
#include "ReturnTransaction.h"


ReturnTransaction::ReturnTransaction()
{
	pBooksInventoryHash = NULL;
	customerList = NULL;
}

ReturnTransaction::ReturnTransaction(queue<string> stringB, HashQuadCollision * customerL, HashChaining * pBooksInventoryH)
{
	stringBroken = stringB;
	pBooksInventoryHash = pBooksInventoryH;
	customerList = customerL;
}


ReturnTransaction::~ReturnTransaction()
{
}

void ReturnTransaction::ExecuteTransection()
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

	if (!((*pC).returnBook(pBook)))
	{
		cout << "Unable to return the book." << endl;
		return;
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
		(*pBB).setnewCount((*pBB).getnewCount() + 1);
	}
	else
	{
		switch (condition)
		{
		case 'E':
		{
			(*pBB).setUsedExcellentCount((*pBB).getUsedExcellentCount() + 1);
			break;

		}
		case 'G':
		{
			(*pBB).setUsedGoodCount((*pBB).getUsedGoodCount() + 1);
			break;

		}
		case 'F':
		{
			(*pBB).setUsedFairCount((*pBB).getUsedFairCount() + 1);
			break;

		}
		}
	}

	delete pBook;

	if (((*pC).getBalance() < 200) && (isGoldCustomer(pC)))
	{
		//cout << "Hello World" << endl;
		Customer *c1 = new Customer();
		(*c1).setBalance((*pC).getBalance());
		(*c1).setBookBoughtCost((*pC).getBookBoughtCost());
		(*c1).setBookBoughtCost((*pC).getBookBoughtCost());
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
}
