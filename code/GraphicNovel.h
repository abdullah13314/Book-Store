#pragma once
#include "Book.h"
#include <cmath>
#include <stdlib.h>

class GraphicNovel : public Book
{
public:
	GraphicNovel();
	GraphicNovel(string title, string author, string artist);
	~GraphicNovel();

	void setArtist(string s);

	string getArtist() const;
	virtual void a() const;


private:
	string artist;

};

