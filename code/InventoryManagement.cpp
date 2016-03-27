#include "stdafx.h"
#include "InventoryManagement.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
const int MAX_LINE_SIZE1 = 2048;
const int MAX_TITLE1 = 256;

InventoryManagement::InventoryManagement()
{
	pBooksInventoryHash = new HashChaining;
	pAudioBooksInventoryTree = new BST;
	pOtherBooksInventoryTree = new BST;

}


InventoryManagement::~InventoryManagement()
{
}

void InventoryManagement::setFileName(string fileName)
{
	this->filename = fileName;
}

HashChaining * InventoryManagement::getPBooksInventoryHash()
{
	return pBooksInventoryHash;
}


BST * InventoryManagement::getPAudioBooksInventoryTree()
{
	return pAudioBooksInventoryTree;
}

BST * InventoryManagement::getPOtherBooksInventoryTree()
{
	return pOtherBooksInventoryTree;
}


void InventoryManagement::CreateInventory()
{
	fstream myFile;
	char line[MAX_LINE_SIZE1];
	char delim = ',';
	//BookBlock* bb[10];
	//int count = 0;

	myFile.open(filename);
	if (!myFile.is_open())
	{
		cout << "File not found!" << endl;
	}
	else
	{

		char token[MAX_TITLE1];
		string title, author, narrator, artist;
		bool isNew;
		char condition;
		double cost;
		int countB;
		Book * pBook;
		BookBlock *pBlock;
		while (myFile.getline(line, MAX_LINE_SIZE1))
		{

			stringstream ss;
			ss << line;
			//cout << line << endl;
			ss.getline(token, MAX_TITLE1, ',');
			//cout << token << endl;
			switch (token[0])
			{
				case 'B':
				{
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					if (token[0] == 'N')
					{
						isNew = true;
						//cout << "New Book" << endl;
					}
					else
					{
						isNew = false;
					}
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					countB = atoi(((string)token).c_str());
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					author = token;
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					title = token;
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					cost = atof(((string)token).c_str());
			//		cout << cost << endl;
					cost = (ceil(cost * 100)) / 100;
			//		cout << cost << endl;

					if (!isNew)
					{
						ss.getline(token, MAX_TITLE1, ',');
			//			cout << token[0] << endl;

						condition = token[0];
					}
					pBook = new Book(title, author);
					break;

				}
				case 'G':
				{
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					if (token[0] == 'N')
					{
						isNew = true;
						//cout << "New Book" << endl;

					}
					else
					{
						isNew = false;
					}
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					countB = atoi(((string)token).c_str());
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					author = token;
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					title = token;
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					cost = atof(((string)token).c_str());
					cost = (ceil(cost * 100)) / 100;
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					artist = token;
					if (!isNew)
					{
						ss.getline(token, MAX_TITLE1, ',');
			//			cout << token[0] << endl;

						condition = token[0];
					}
					pBook = new GraphicNovel(title, author, artist);
					break;

				}
				case 'A':
				{
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					if (token[0] == 'N')
					{
						isNew = true;
						//cout << "New Book" << endl;
					}
					else
					{
						isNew = false;
					}
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					countB = atoi(((string)token).c_str());
					ss.getline(token, MAX_TITLE1, ',');
					author = token;
			//		cout << token << endl;

					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					title = token;
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					cost = atof(((string)token).c_str());
					cost = (ceil(cost * 100)) / 100;
					ss.getline(token, MAX_TITLE1, ',');
			//		cout << token << endl;

					narrator = token;
					if (!isNew)
					{
						ss.getline(token, MAX_TITLE1, ',');
			//			cout << token[0] << endl;

						condition = token[0];
					}
					pBook = new AudioBook(title, author, narrator);
					break;
				}
				default:
				{

				}
			}
			//cout << (*pBook).getTitle() << ", " << (*pBook).getAuthor() << endl;

			if (!(*pBooksInventoryHash).Retrive(pBlock, pBook))
			{
				pBlock = new BookBlock;
				(*pBlock).setPBook(pBook);
				(*pBooksInventoryHash).Add(pBlock);
				if (isAudioBook(pBook))
				{
					(*pAudioBooksInventoryTree).Add(pBlock);

				}
				else
				{
					(*pOtherBooksInventoryTree).Add(pBlock);

				}

			}
			else
			{
				delete pBook;
				pBook = NULL;
			}

			if (isNew)
			{
				(*pBlock).setNewCost(cost);
				(*pBlock).setnewCount(countB+ (*pBlock).getnewCount());
			}
			else
			{
				switch (condition)
				{
					case 'E':
					{
						(*pBlock).setUsedExcellentCost(cost);
						(*pBlock).setUsedExcellentCount(countB + (*pBlock).getUsedExcellentCount());
						break;

					}
					case 'G':
					{
						(*pBlock).setUsedGoodCost(cost);
						(*pBlock).setUsedGoodCount(countB + (*pBlock).getUsedGoodCount());
						break;

					}
					case 'F':
					{
						(*pBlock).setUsedFairCost(cost);
						(*pBlock).setUsedFairCount(countB + (*pBlock).getUsedFairCount());
						break;

					}
				}
			}


			//bb[count] = pBlock;
			//pBlock = NULL;
			//cout << count << endl;
			//Book *p1 = (*bb[count]).getPBook();
			//cout << (*p1).getTitle() << ", " << (*p1).getAuthor() << endl;
			//count++;

		}
		/*
	//	cout << "Exit Loop " << endl;
		for (int i = 0; i < count; i++)
		{
		//	cout << "Enter Loop " << endl;

			Book *p = (*bb[i]).getPBook();
		//	cout << "Next Step 1 " << endl;
			cout << (*p).getTitle() << ", " << (*p).getTitle() << endl;
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
			cout << (*bb[i]).getNewCost() << ", " << (*bb[i]).getnewCount() << ", " << (*bb[i]).getUsedExcellentCost() << ", " << (*bb[i]).getUsedExcellentCount() << ", " << (*bb[i]).getUsedGoodCost() << ", " << (*bb[i]).getUsedGoodCount() << ", " << (*bb[i]).getUsedFairCost() << ", " << (*bb[i]).getUsedFairCount() << endl;
		}
		*/
	}
	//Book b1("The Dying Grass", "William Vollmann");
	//Book *sBookb = &b1;
	//BookBlock *pBlk;
	//(*pBooksInventoryHash).Retrive(pBlk, sBookb);
	//(*pBooksInventoryTree).Remove(pBlk);
	//(*pBooksInventoryHash).Remove(pBlk);
	//cout << (*pBooksInventoryTree);
	//(*pBooksInventoryHash).PrintALL();
	//(*customerList).PrintAllCustomers();
	//Customer* c10 = (*customerList).Retrive("Ray", "Lewis");
	//cout << (*c10).getFirstName() << " " << (*c10).getLastName() << " " << isSeniorCustomer(c10) << endl;
}

bool InventoryManagement::isAudioBook(Book * pBook)
{
	AudioBook *pAB = dynamic_cast<AudioBook *>(pBook);
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
bool InventoryManagement::isGraphicNovel(Book * pBook)
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