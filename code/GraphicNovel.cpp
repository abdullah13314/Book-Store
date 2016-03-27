#include "stdafx.h"
#include "GraphicNovel.h"


GraphicNovel::GraphicNovel()
{
}

GraphicNovel::GraphicNovel(string title, string author, string artist)
{
	this->title = title;
	this->author = author;
	this->artist = artist;
}


GraphicNovel::~GraphicNovel()
{
}

void GraphicNovel::setArtist(string s)
{
	this->artist = s;
}

string GraphicNovel::getArtist() const
{
	return this->artist;
}

void GraphicNovel::a() const
{

}