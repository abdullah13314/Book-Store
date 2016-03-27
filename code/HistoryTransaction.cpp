#include "stdafx.h"
#include "HistoryTransaction.h"


HistoryTransaction::HistoryTransaction()
{
	customerList = NULL;
}

HistoryTransaction::HistoryTransaction(queue<string> stringB, HashQuadCollision * customerL)
{
	customerList = customerL;
	stringBroken = stringB;
}


HistoryTransaction::~HistoryTransaction()
{
}

void HistoryTransaction::ExecuteTransection()
{
	string firstName = stringBroken.front();
	stringBroken.pop();
	string lastName = stringBroken.front();
	stringBroken.pop();
	Customer *pC = (*customerList).Retrive(firstName, lastName);
	if (pC == NULL)
	{
		cerr << "Customer does not exist. " << endl;
		return;
	}
	cout << "History for " << (*pC).getFirstName() << " " << (*pC).getLastName() << ". Balance: " << (*pC).getBalance() << endl;
	vector<string> history = (*pC).getHistory();
	for (int i = 0; i < history.size(); i++)
	{
		cout << history[i] << endl;
	}
}
