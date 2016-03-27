#include "stdafx.h"
#include "GoldCustomer.h"
#include <sstream>



GoldCustomer::GoldCustomer()
{
}

GoldCustomer::GoldCustomer(string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastname = lastName;
}


GoldCustomer::~GoldCustomer()
{
}

bool GoldCustomer::purchaseBook(Book * book, double cost)
{
	ostringstream convert;
	if (!isAudioBook(book))
	{
		cost = cost * 0.9;
		cost = ceil(cost * 100) / 100;
	}
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

