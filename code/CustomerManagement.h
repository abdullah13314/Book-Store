#pragma once
//#include "Customer.h"
#include "GoldCustomer.h"
#include "SeniorCustomer.h"
#include "HashQuadCollision.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>


using namespace std;

class CustomerManagement
{
public:
	CustomerManagement();
	~CustomerManagement();

	void setFileName(string s);

	HashQuadCollision* getPointerCustomerList() ;

	void CreateCustomerList();

private:
	HashQuadCollision *customerList;
	string setFile;
	bool isGoldCustomer(Customer *cus);
	bool isSeniorCustomer(Customer *cus);

};

