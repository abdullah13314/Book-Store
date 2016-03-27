#include "stdafx.h"
#include "CustomerManagement.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
const int MAX_LINE_SIZE = 2048;
const int MAX_TITLE = 256;



CustomerManagement::CustomerManagement()
{
	customerList = new HashQuadCollision;
}


CustomerManagement::~CustomerManagement()
{
}

void CustomerManagement::setFileName(string s)
{
	this->setFile = s;
}

HashQuadCollision * CustomerManagement::getPointerCustomerList()
{
	return customerList;
}

void CustomerManagement::CreateCustomerList()
{
	fstream myFile;
	char line[MAX_LINE_SIZE];
	char delim = ',';
	//Customer* c1[10];
	//int count = 0;
	
	myFile.open(setFile);
	if (!myFile.is_open())
	{
		cout << "File not found!" << endl;
	}
	else
	{
		char token[MAX_TITLE];
		string firstName, lastName;
		int age;
		while (myFile.getline(line, MAX_LINE_SIZE))
		{
			stringstream ss;
			ss << line;
			//cout << line << endl;
			ss.getline(token, MAX_TITLE, ',');
			//cout << token;
			firstName = token;
			ss.getline(token, MAX_TITLE, ',');
			lastName = token;
			//cout << token;

			ss.getline(token, MAX_TITLE, ',');
			//cout << token << endl;

			age = atoi(((string)token).c_str());
			//cout << firstName << lastName  <<age << " " << endl;
			if (age > 65)
			{
				Customer* c = new SeniorCustomer(firstName, lastName);
				(*customerList).Add(c);
				//c1[count] = c;
				//count++;
			}
			else
			{
				Customer* c = new Customer(firstName, lastName);
				(*customerList).Add(c);
				//c1[count] = c;
				//count++;

			}
		}
	}
	
	/*
	for (int i = 0; i < count; i++)
	{
		cout << (*c1[i]).getFirstName() << " " << (*c1[i]).getLastName() << " isSeniorCustomer :" << isSeniorCustomer(c1[i]) << endl;
	}
	*/
	//(*customerList).PrintAllCustomers();
	//Customer* c10 = (*customerList).Retrive("Ray", "Lewis");
	//cout << (*c10).getFirstName() << " " << (*c10).getLastName() << " " << isSeniorCustomer(c10) << endl;
}



bool CustomerManagement::isGoldCustomer(Customer * cus)
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

bool CustomerManagement::isSeniorCustomer(Customer * cus)
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
