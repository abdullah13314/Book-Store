#pragma once
#include "Customer.h"
#include <cmath>
#include <stdlib.h>

class GoldCustomer : public Customer
{
public:
	GoldCustomer();
	GoldCustomer(string firstName, string lastName);

	~GoldCustomer();
	virtual bool purchaseBook(Book* book, double cost);


};

