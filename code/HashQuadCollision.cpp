#include "stdafx.h"
#include "HashQuadCollision.h"


HashQuadCollision::HashQuadCollision()
{
	for (int i = 0; i < HASH_SIZE; i++)
	{
		hashtable[i] = NULL;
	}
}


HashQuadCollision::~HashQuadCollision()
{
}

bool HashQuadCollision::Add(Customer *& customer)
{
	string key = (*customer).getFirstName() + (*customer).getLastName();
	int index = findIndex(key);
	hashtable[index] = customer;
	return true;
}

Customer * HashQuadCollision::Retrive(string firstName, string lastName)
{
	string key = firstName + lastName;
	int index = hash(key);
	int quad = 0;
	while (hashtable[(index + (int)pow(quad, 2))%HASH_SIZE] != NULL)
	{

		Customer* c = hashtable[(index + (int)pow(quad, 2))%HASH_SIZE];
		string fN, lN;
		fN = (*c).getFirstName();
		lN = (*c).getLastName();
		if (( fN == firstName) && ( lN == lastName))
		{
			return c;
		}
		quad++;
	}
	return (NULL);
}

bool HashQuadCollision::Remove(string firstName, string lastName)
{
	string key = firstName + lastName;
	int index = hash(key);
	int quad = 0;
	while (hashtable[(index + (int)pow(quad, 2)) % HASH_SIZE] != NULL)
	{

		Customer* c = hashtable[(index + (int)pow(quad, 2)) % HASH_SIZE];
		string fN, lN;
		fN = (*c).getFirstName();
		lN = (*c).getLastName();
		if ((fN == firstName) && (lN == lastName))
		{
			delete hashtable[(index + (int)pow(quad, 2)) % HASH_SIZE];
			hashtable[(index + (int)pow(quad, 2)) % HASH_SIZE] = NULL;
			return true;
		}
		quad++;
	}
	return false;
}

void HashQuadCollision::PrintAllCustomers() const
{
	for (int i = 0; i < HASH_SIZE; i++)
	{
		if (hashtable[i] != NULL)
		{
			cout << i << " " <<(*hashtable[i]).getFirstName() << " " << (*hashtable[i]).getLastName() << endl;
		}
	}
}

int HashQuadCollision::hash(string key)
{
	unsigned int value = 0;
	for (int i = 0; i < key.length(); i++)
		value = HASH_SIZE * value + key[i];
	return (value% HASH_SIZE);
}

int HashQuadCollision::findIndex(string key)
{
	int key_index = hash(key);
	int quad = 0;
	bool notAdded = true;
	while (notAdded)
	{
		if (hashtable[key_index + (int)pow(quad, 2)] == NULL)
		{
			return (key_index + (int)pow(quad, 2));
		}
		quad++;
	}
}


void HashQuadCollision::Clear()
{
	for (int i = 0; i < HASH_SIZE; i++)
	{
		if (hashtable[i] != NULL)
		{
			delete hashtable[i];
			hashtable[i] = NULL;
		}
	}
}

