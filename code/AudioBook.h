#pragma once
#include "Book.h"
#include <cmath>
#include <stdlib.h>


class AudioBook : public Book
{
public:
	AudioBook();
	AudioBook(string title, string author, string narrator);
	~AudioBook();

	void setNarrator(string s);
	virtual void a() const;


	string getNarrator() const;


private:
	string narrator;
};

