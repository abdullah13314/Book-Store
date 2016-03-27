#pragma once
#include <iostream>
#include <cmath>
#include <stdlib.h>




using namespace std;
class Book
{
public:
	Book();
	Book(string title, string author);
	virtual ~Book();

	void setTitle(string s);
	void setAuthor(string s);

	string getTitle() const;
	string getAuthor() const;

	virtual void a() const;
	//bool operator<(const Book &book) const;

	bool operator<(const Book &b1) const;
	bool operator>(const Book &b1) const;

	bool operator==(const Book &b1) const;
	bool operator!=(const Book &b1) const;



protected:
	string title, author;
};

