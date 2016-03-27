#pragma once
#include "Book.h"
#include "BookBlock.h"
#include "GraphicNovel.h"
#include "AudioBook.h"
#include <string>
#include <iostream>

#include <cmath>
#include <stdlib.h>

using namespace std;
const int HASH_SIZE1 = 223;
class HashChaining
{
public:
	HashChaining();
	~HashChaining();

	bool Add(BookBlock *& bookBlock);
	bool Retrive(BookBlock *&bookBlock, Book *book);
	bool Remove(BookBlock *&bookBlock);
	void PrintALL();
	void Clear();

private:
	struct Bucket {
		BookBlock* pBookBlock;
		Bucket *next = NULL;
	};
	Bucket* hashtable[HASH_SIZE1];
	int hash(string key);
	int findIndex(string key);
	bool isAudioBook(Book *b);
	bool isGraphicNovel(Book *b);

};

