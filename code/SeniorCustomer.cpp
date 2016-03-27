#include "stdafx.h"
#include "SeniorCustomer.h"
#include <sstream>



SeniorCustomer::SeniorCustomer()
{
}

SeniorCustomer::SeniorCustomer(string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastname = lastName;
}


SeniorCustomer::~SeniorCustomer()
{
}

bool SeniorCustomer::purchaseBook(Book * book, double cost)
{
	ostringstream convert;

	cost = cost * 0.85;
	cost = ceil(cost * 100) / 100;
	convert << cost;
	balance += cost;
	string h = "Purchased Book " + (*book).getTitle() + " for $" + convert.str();
	history.push_back(h);
	bookTitleBought.push_back((*book).getTitle());
	bookBoughtCost.push_back(cost);
	if (isAudioBook(book))
	{
		isBookAudio.push_back(true);
	}
	else
	{
		isBookAudio.push_back(false);
	}
	return true;
}
