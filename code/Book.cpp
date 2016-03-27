#include "stdafx.h"
#include "Book.h"


Book::Book()
{
}

Book::Book(string title, string author)
{
	this->title = title;
	this->author = author;
}


Book::~Book()
{
}

void Book::setTitle(string s)
{
	this->title = s;
}

void Book::setAuthor(string s)
{
	this->author = s;
}

string Book::getTitle() const
{
	return title;
}

string Book::getAuthor() const
{
	return author;
}

void Book::a() const
{

}

bool Book::operator<(const Book & b1) const
{
	if ((this->title.compare(b1.getTitle())) < 0)
	{
		return true;
	}
	return false;
}

bool Book::operator>(const Book & b1) const
{
	if ((this->title.compare(b1.getTitle())) > 0)
	{
		return true;
	}
	return false;
}

bool Book::operator==(const Book & b1) const
{
	if ((this->title.compare(b1.getTitle())) == 0)
	{
		return true;
	}
	return false;
}

bool Book::operator!=(const Book & b1) const
{
	if ((this->title.compare(b1.getTitle())) != 0)
	{
		return true;
	}
	return false;
	return false;
}
