#include "stdafx.h"
#include "Customer.h"
//#include "Book.h"
#include <sstream>

Customer::Customer()
{
	balance = 0;
}

Customer::Customer(string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastname = lastName;
	this->balance = 0;
}


Customer::~Customer()
{
}

string Customer::getFirstName() const
{
	return firstName;
}

string Customer::getLastName() const
{
	return lastname;
}

double Customer::getBalance() const
{
	return balance;
}

vector<string> Customer::getHistory() const
{
	return history;
}

vector<string> Customer::getBookTitleBought() const
{
	return bookTitleBought;
}

vector<double> Customer::getBookBoughtCost() const
{
	return bookBoughtCost;
}

vector<bool> Customer::getIsBookAudio() const
{
	return isBookAudio;
}

void Customer::setBalance(double d)
{
	balance = d;
}

void Customer::setHistory(vector<string> v)
{
	history = v;
}

void Customer::setBookTitleBought(vector<string> v)
{
	bookTitleBought = v;
}

void Customer::setBookBoughtCost(vector<double> v)
{
	bookBoughtCost = v;
}

void Customer::setIsBookAudio(vector<bool> v)
{
	isBookAudio = v;
}

void Customer::setFirstName(string s) 
{
	firstName = s;
}

void Customer::setLastName(string s) 
{
	lastname = s;
}

bool Customer::purchaseBook(Book * book, double cost)
{
	ostringstream convert;

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

bool Customer::returnBook(Book * book)
{
	bool bookIsBought = false;
	double cost;

	for (int i = 0; i < bookTitleBought.size(); i++)
	{
		string j = bookTitleBought[i];
		if ((*book).getTitle() == j)
		{
			if (isAudioBook(book))
			{
				if (isBookAudio[i])
				{
					bookIsBought = true;
					cost = bookBoughtCost[i];
					bookBoughtCost[i] = bookBoughtCost[bookBoughtCost.size() - 1];
					bookBoughtCost.pop_back();
					bookTitleBought[i] = bookTitleBought[bookTitleBought.size() - 1];
					bookTitleBought.pop_back();
					isBookAudio[i] = isBookAudio[isBookAudio.size() - 1];
					isBookAudio.pop_back();
					i = bookTitleBought.size() + 10;

				}
			}
			else
			{
				bookIsBought = true;
				cost = bookBoughtCost[i];
				bookBoughtCost[i] = bookBoughtCost[bookBoughtCost.size() - 1];
				bookBoughtCost.pop_back();
				bookTitleBought[i] = bookTitleBought[bookTitleBought.size() - 1];
				bookTitleBought.pop_back();
				isBookAudio[i] = isBookAudio[isBookAudio.size() - 1];
				isBookAudio.pop_back();
				i = bookTitleBought.size() + 10;
			}
		}
	}
	//cout << "Hello World 1" << endl;
	if (bookIsBought)
	{
		//cout << "Hello World 2" << endl;

		ostringstream convert;

		convert << cost;

		balance -= cost;
		string h = "Returned Book " + (*book).getTitle() + " for $" + convert.str();
		history.push_back(h);
		return true;
	}
	return false;

}

bool Customer::tradeInBook(Book * book, double cost)
{
	ostringstream convert;   

	convert << cost; 

	balance -= cost;



	string h = "Traded In Book " + (*book).getTitle() + " for $" + convert.str();
	history.push_back(h);
	return true;
	
}

bool Customer::isAudioBook(Book * pBook)
{
	AudioBook *pAB = dynamic_cast<AudioBook *>(pBook);
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
