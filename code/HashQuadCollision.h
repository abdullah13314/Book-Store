#pragma once
#include "Customer.h"
#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>


using namespace std;
const int HASH_SIZE = 223;
class HashQuadCollision
{
public:
	HashQuadCollision();
	~HashQuadCollision();

	bool Add(Customer*& customer);
	Customer* Retrive(string firstName, string lastName);
	bool Remove(string firstName, string lastName);

	void Clear();
	void PrintAllCustomers() const;

private:
	Customer* hashtable[HASH_SIZE];
	int hash(string key);
	int findIndex(string key);
};

