#pragma once
#include "Customer.h"
#include <cmath>
#include <stdlib.h>

class SeniorCustomer : public Customer
{
public:
	SeniorCustomer();
	SeniorCustomer(string firstName, string lastName);

	~SeniorCustomer();

	virtual bool purchaseBook(Book* book, double cost);

};

