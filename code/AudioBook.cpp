#include "stdafx.h"
#include "AudioBook.h"


AudioBook::AudioBook()
{
}

AudioBook::AudioBook(string title, string author, string narrator)
{
	this->title = title;
	this->author = author;
	this->narrator = narrator;
}


AudioBook::~AudioBook()
{
}

void AudioBook::setNarrator(string s)
{
	this->narrator = s;
}

string AudioBook::getNarrator() const
{
	return this->narrator;
}

void AudioBook::a() const
{

}