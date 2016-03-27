#pragma once
#include <iostream>
#include "HashChaining.h"
#include "HashQuadCollision.h"
#include "BST.h"
#include <queue>
#include "SeniorCustomer.h"
#include "GoldCustomer.h"
#include <cmath>
#include <stdlib.h>


const int MAX_TITLE2 = 256;

using namespace std;

class Transaction
{
public:
	Transaction();
	//Transaction(string transactionString, HashChaining* customerList, HashQuadCollision* inventoryList);
	virtual ~Transaction();

	virtual void ExecuteTransection() = 0;
	bool isGoldCustomer(Customer * cus);
	bool isSeniorCustomer(Customer * cus);

protected:

	queue<string> stringBroken;

};

