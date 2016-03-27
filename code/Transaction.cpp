#include "stdafx.h"
#include "Transaction.h"


Transaction::Transaction()
{
}


Transaction::~Transaction()
{
}

bool Transaction::isGoldCustomer(Customer * cus)
{
	GoldCustomer *pAB = dynamic_cast<GoldCustomer *>(cus);
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

bool Transaction::isSeniorCustomer(Customer * cus)
{
	SeniorCustomer *pAB = dynamic_cast<SeniorCustomer *>(cus);
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