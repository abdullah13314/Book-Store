#include "stdafx.h"
#include "HashChaining.h"


HashChaining::HashChaining()
{
	for (int i = 0; i < HASH_SIZE1; i++)
	{
		hashtable[i] = NULL;
	}
}


HashChaining::~HashChaining()
{
}

bool HashChaining::Add(BookBlock *& bookBlock)
{
	Book * pBook = (*bookBlock).getPBook();
	string key;
	if (isAudioBook(pBook))
	{
		key = (*pBook).getTitle() + "a";
	}
	else
	{
		key = (*pBook).getTitle();

	}
	int index = findIndex(key);
	if (hashtable[index] == NULL)
	{
		Bucket* buck = new Bucket;
		buck->pBookBlock = bookBlock;
		buck->next = NULL;
		hashtable[index] = buck;
	}
	else
	{
		Bucket* pNode;
		pNode = hashtable[index];
		while (pNode != NULL)
		{
			pNode = pNode->next;
		}
		Bucket* buck = new Bucket;
		buck->pBookBlock = bookBlock;
		buck->next = NULL;
		pNode = buck;
	}
	return true;
}

bool HashChaining::Retrive(BookBlock *& bookBlock, Book * pBook)
{
	string key;
	if (isAudioBook(pBook))
	{
		key = (*pBook).getTitle() + "a";
	}
	else
	{
		key = (*pBook).getTitle();

	}
	int index = hash(key);
	Bucket *pNode = hashtable[index];
	bool notFound = true;
	while (notFound && (pNode != NULL))
	{
		BookBlock *pBlock = (*pNode).pBookBlock;
		Book * pBook2 = (*pBlock).getPBook();
		if ((*pBook2).getTitle()==(*pBook).getTitle())
		{
			bookBlock = pBlock;
			return true;
		}
		pNode = pNode->next;
	}
	return false;
}

bool HashChaining::Remove(BookBlock *& bookBlock)
{
	Book *pBook = (*bookBlock).getPBook();
	string key;
	if (isAudioBook(pBook))
	{
		key = (*pBook).getTitle() + "a";
	}
	else
	{
		key = (*pBook).getTitle();

	}
	int index = hash(key);
	Bucket *pNode = hashtable[index];
	BookBlock *pBlock = (*pNode).pBookBlock;
	Book * pBook2 = (*pBlock).getPBook();
	if ((*pBook2).getTitle() == (*pBook).getTitle())
	{
		hashtable[index] = pNode->next;
		delete pBook2;
		delete pBlock;
		delete pNode;
		return true;
	}
	bool notFound = true;
	while (notFound && (pNode->next != NULL))
	{
		pBlock = (*pNode->next).pBookBlock;
		pBook2 = (*pBlock).getPBook();
		if ((*pBook2).getTitle() == (*pBook).getTitle())
		{
			Bucket *dNode = pNode->next;
			pNode->next = pNode->next->next;
			delete pBook2;
			delete pBlock;
			delete dNode;			
			return true;
		}
		pNode = pNode->next;
	}
	return false;
}

void HashChaining::PrintALL()
{
	for (int i = 0; i < HASH_SIZE1; i++)
	{
		if (hashtable[i] != NULL)
		{
			Bucket *pBuc = hashtable[i];
			while (pBuc != NULL)
			{
				Book *p = (*(pBuc->pBookBlock)).getPBook();
				//	cout << "Next Step 1 " << endl;
				cout << (*p).getTitle() << ", " << (*p).getAuthor() << endl;
				if (isAudioBook(p))
				{
					AudioBook *pAB = dynamic_cast<AudioBook *>(p);
					cout << (*pAB).getNarrator() << endl;
				}
				if (isGraphicNovel(p))
				{
					GraphicNovel *pAB = dynamic_cast<GraphicNovel *>(p);
					cout << (*pAB).getArtist() << endl;
				}
				cout << (*(pBuc->pBookBlock)).getNewCost() << ", " << (*(pBuc->pBookBlock)).getnewCount() << ", " << (*(pBuc->pBookBlock)).getUsedExcellentCost() << ", " << (*(pBuc->pBookBlock)).getUsedExcellentCount() << ", " << (*(pBuc->pBookBlock)).getUsedGoodCost() << ", " << (*(pBuc->pBookBlock)).getUsedGoodCount() << ", " << (*(pBuc->pBookBlock)).getUsedFairCost() << ", " << (*(pBuc->pBookBlock)).getUsedFairCount() << endl;
				pBuc = pBuc->next;
			}
		}
	}
}

int HashChaining::hash(string key)
{
	unsigned int value = 0;
	for (int i = 0; i < key.length(); i++)
		value = HASH_SIZE1 * value + key[i];
	return (value% HASH_SIZE1);
}

int HashChaining::findIndex(string key)
{
	return hash(key);
}

bool HashChaining::isAudioBook(Book *b)
{
	AudioBook *pAB = dynamic_cast<AudioBook *>(b);
	if (pAB == NULL)
	{
		//cout << "Not Audio " << endl;

		return false;
	}
	else
	{
		//cout << "Is Audio " << endl;

		return true;
	}
}

bool HashChaining::isGraphicNovel(Book * pBook)
{
	GraphicNovel *pAB = dynamic_cast<GraphicNovel *>(pBook);
	if (pAB == NULL)
	{
		//cout << "Not Audio " << endl;

		return false;
	}
	else
	{
		//cout << "Is Audio " << endl;

		return true;

	}
}

void HashChaining::Clear()
{
	for (int i = 0; i < HASH_SIZE1; i++)
	{
		if (hashtable[i] != NULL)
		{
			Bucket *pBuc = hashtable[i];
			while (pBuc != NULL)
			{
				Bucket *dBuc = pBuc;
				pBuc = pBuc->next;
				BookBlock *dBB = dBuc->pBookBlock;
				Book *dBook = (*dBB).getPBook();
				delete dBook;
				delete dBB;
				delete dBuc;

			}
			hashtable[i] = NULL;
		}
	}
}

