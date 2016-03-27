#include "stdafx.h"
#include "TradeInTransaction.h"


TradeInTransaction::TradeInTransaction()
{
	pBooksInventoryHash = NULL;
	customerList = NULL;
	pAudioBooksInventoryTree = NULL;
	pOtherBooksInventoryTree = NULL;
}

TradeInTransaction::TradeInTransaction(queue<string> stringB, HashQuadCollision * customerL, HashChaining * pBooksInventoryH, BST * pAudioBooksInventoryT, BST * pOtherBooksInventoryT)
{
	stringBroken = stringB;
	pBooksInventoryHash = pBooksInventoryH;
	customerList = customerL;
	pAudioBooksInventoryTree = pAudioBooksInventoryT;
	pOtherBooksInventoryTree = pOtherBooksInventoryT;
}


TradeInTransaction::~TradeInTransaction()
{
}

void TradeInTransaction::ExecuteTransection()
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
	char condition;
	string title, author, narrator, artist;
	double cost;
	Book *pBook;

	switch (token)
	{
	case 'B':
	{
		author = stringBroken.front();
		stringBroken.pop();

		title = stringBroken.front();
		stringBroken.pop();

		cost = atof((stringBroken.front()).c_str());
		cost = (ceil(cost * 100)) / 100;
		stringBroken.pop();


		condition = (stringBroken.front()).at(0);
		stringBroken.pop();

		pBook = new Book(title, author);
		break;

	}
	case 'G':
	{


		author = stringBroken.front();
		stringBroken.pop();

		title = stringBroken.front();
		stringBroken.pop();

		cost = atof((stringBroken.front()).c_str());
		cost = (ceil(cost * 100)) / 100;
		stringBroken.pop();

		artist = stringBroken.front();
		stringBroken.pop();


		condition = (stringBroken.front()).at(0);
		stringBroken.pop();
		
		pBook = new GraphicNovel(title, author, artist);
		break;

	}
	case 'A':
	{
		//cout << "Hello World " << endl;

		author = stringBroken.front();
		stringBroken.pop();

		title = stringBroken.front();
		stringBroken.pop();

		cost = atof((stringBroken.front()).c_str());
		cost = (ceil(cost * 100)) / 100;
		stringBroken.pop();

		artist = stringBroken.front();
		stringBroken.pop();


		condition = (stringBroken.front()).at(0);
		stringBroken.pop();

		//cout << "Hello World " << endl;

		
		pBook = new AudioBook(title, author, narrator);
		break;
	}
	default:
	{
		cerr << "Invalid Input." << endl;
		return;
	}
	}

	bool newBook = true;

	BookBlock *pBB;
	if (!((*pBooksInventoryHash).Retrive(pBB, pBook)))
	{
		pBB = new BookBlock;
		(*pBB).setPBook(pBook);
		(*pBooksInventoryHash).Add(pBB);
		if (isAudioBook(pBook))
		{
			(*pAudioBooksInventoryTree).Add(pBB);

		}
		else
		{
			(*pOtherBooksInventoryTree).Add(pBB);

		}
	}
	else
	{
		newBook = false;
	}
	
	switch (condition)
	{
		case 'E':
		{
			if (((*pBB).getUsedExcellentCost() == cost) || ((int)(*pBB).getUsedExcellentCost() == 0))
			{
				(*pBB).setUsedExcellentCount((*pBB).getUsedExcellentCount() + 1);
				(*pBB).setUsedExcellentCost(cost);
			}
			else
			{
				cerr << "Invalid Cost." << endl;
				return;
			}
			
			break;

		}
		case 'G':
		{
			if (((*pBB).getUsedGoodCost() == cost) || ((int)(*pBB).getUsedGoodCost() == 0))
			{
				(*pBB).setUsedGoodCount((*pBB).getUsedGoodCount() + 1);
				(*pBB).setUsedGoodCost(cost);

			}
			else
			{
				cerr << "Invalid Cost." << endl;
				return;
			}
			break;

		}
		case 'F':
		{
			if (((*pBB).getUsedFairCost() == cost) || ((int)(*pBB).getUsedFairCost() == 0))
			{
				(*pBB).setUsedFairCount((*pBB).getUsedFairCount() + 1);
				(*pBB).setUsedFairCost(cost);

			}
			else
			{
				cerr << "Invalid Cost." << endl;
				return;
			}
			break;

		}
	}
	
	(*pC).tradeInBook(pBook, cost);
	if (!newBook)
	{
		delete pBook;
	}

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

bool TradeInTransaction::isAudioBook(Book * pBook)
{
	AudioBook *pAB = dynamic_cast<AudioBook *>(pBook);
	if (pAB == NULL)
	{
		//cout << "Not Audio " << endl;

		return false;
	}
	else
	{
		//cout << "Is Audio " << endl;

		return true;

	}
}