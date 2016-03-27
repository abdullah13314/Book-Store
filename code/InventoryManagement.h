#pragma once
#include "Book.h"
#include "AudioBook.h"
#include "GraphicNovel.h"
#include "HashChaining.h"
#include "BST.h"
#include "BookBlock.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>


using namespace std;

class InventoryManagement
{
public:
	InventoryManagement();
	~InventoryManagement();

	void setFileName(string fileName);

	HashChaining* getPBooksInventoryHash();

	BST* getPAudioBooksInventoryTree();
	BST* getPOtherBooksInventoryTree();


	void CreateInventory();

private:
	string filename;
	HashChaining* pBooksInventoryHash;
	BST* pAudioBooksInventoryTree;
	BST* pOtherBooksInventoryTree;
	bool isGraphicNovel(Book * pBook);
	bool isAudioBook(Book * pBook);

};

