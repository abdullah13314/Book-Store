#pragma once
#include "Book.h"
#include <cmath>
#include <stdlib.h>

class BookBlock
{
public:
	BookBlock();
	~BookBlock();

	void setPBook(Book *&book);
	void setnewCount(int c);
	void setUsedExcellentCount(int c);
	void setUsedGoodCount(int c);
	void setUsedFairCount(int c);
	void setNewCost(double c);
	void setUsedExcellentCost(double c);
	void setUsedGoodCost(double c);
	void setUsedFairCost(double c);

	Book* getPBook() const;
	int getnewCount() const;
	int getUsedExcellentCount() const;
	int getUsedGoodCount() const;
	int getUsedFairCount() const;
	double getNewCost() const;
	double getUsedExcellentCost() const;
	double getUsedGoodCost() const;
	double getUsedFairCost() const;
private:
	Book *pBook;
	int newCount;
	int usedExcellentCount;
	int usedGoodCount;
	int usedFairCount;

	double newCost;
	double usedExcellentCost;
	double usedGoodCost;
	double usedFairCost;

};

