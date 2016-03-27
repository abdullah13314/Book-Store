#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
//#include "Book.h"
#include "AudioBook.h"

using namespace std;
class Customer
{
public:
	Customer();
	Customer(string firstName, string lastName);
	virtual ~Customer();

	string getFirstName() const;
	string getLastName() const;
	double getBalance() const;
	vector<string> getHistory() const;
	vector<string> getBookTitleBought() const;
	vector<double> getBookBoughtCost() const;
	vector<bool> getIsBookAudio() const;

	void setFirstName(string s);
	void setLastName(string s);
	void setBalance(double d);
	void setHistory(vector<string> v);
	void setBookTitleBought(vector<string> v);
	void setBookBoughtCost(vector<double> v);
	void setIsBookAudio(vector<bool> v);


	virtual bool purchaseBook(Book* book, double cost);
	bool returnBook(Book* book);
	bool tradeInBook(Book* book, double cost);

protected:
	string firstName;
	string lastname;
	double balance;
	vector<string> history;
	vector<string> bookTitleBought;
	vector<double> bookBoughtCost;
	vector<bool> isBookAudio;
	bool isAudioBook(Book* pBook);


};
#endif
