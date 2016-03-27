#include "stdafx.h"
#include "BookBlock.h"


BookBlock::BookBlock()
{
	pBook = NULL;
	newCount = 0;
	usedExcellentCount = 0;
	usedGoodCount = 0;
	usedFairCount = 0;

	newCost = 0;
	usedExcellentCost = 0;
	usedGoodCost = 0;
	usedFairCost = 0;
}


BookBlock::~BookBlock()
{
}

void BookBlock::setPBook(Book *& book)
{
	pBook = book;
}

void BookBlock::setnewCount(int c)
{
	newCount = c;
}

void BookBlock::setUsedExcellentCount(int c)
{
	usedExcellentCount = c;
}

void BookBlock::setUsedGoodCount(int c)
{
	usedGoodCount = c;
}

void BookBlock::setUsedFairCount(int c)
{
	usedFairCount = c;
}

void BookBlock::setNewCost(double c)
{
	newCost = c;
}

void BookBlock::setUsedExcellentCost(double c)
{
	this->usedExcellentCost = c;
}

void BookBlock::setUsedGoodCost(double c)
{
	usedGoodCost = c;
}

void BookBlock::setUsedFairCost(double c)
{
	usedFairCost = c;
}

Book * BookBlock::getPBook() const
{
	return pBook;
}

int BookBlock::getnewCount() const
{
	return newCount;
}

int BookBlock::getUsedExcellentCount() const
{
	return usedExcellentCount;
}

int BookBlock::getUsedGoodCount() const
{
	return usedGoodCount;
}

int BookBlock::getUsedFairCount() const
{
	return usedFairCount;
}

double BookBlock::getNewCost() const
{
	return newCost;
}

double BookBlock::getUsedExcellentCost() const
{
	return usedExcellentCost;
}

double BookBlock::getUsedGoodCost() const
{
	return usedGoodCost;
}

double BookBlock::getUsedFairCost() const
{
	return usedFairCost;
}
