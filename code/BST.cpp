#include "stdafx.h"
#include "BST.h"


BST::BST()
{
	root = NULL;
}


BST::~BST()
{
}

bool BST::Add(BookBlock *& bookBlock)
{

	addRecursive(bookBlock, root);

	return true;
}

bool BST::Remove(BookBlock *& bookBlock)
{
	removeRecursive(bookBlock, root);
	return true;
}

void BST::addRecursive(BookBlock *& bookBlock, Node *& subTree)
{
	if (subTree == NULL)
	{
		Node *pNode = new Node;
		pNode->pBookBlock = bookBlock;
		pNode->left = NULL;
		pNode->right = NULL;
		subTree = pNode;
		return;
	}
	
	Book *pBook = (*(*subTree).pBookBlock).getPBook();
	Book *dBook = (*bookBlock).getPBook();
	if ((*dBook) < (*pBook))
	{
		addRecursive(bookBlock, subTree->left);
		return;
	}
	else
	{
		addRecursive(bookBlock, subTree->right);
		return;
	}
}


void BST::removeRecursive(BookBlock *& bookBlock, Node *& subTree)
{
	if (subTree == NULL)
	{
		return;
	}
	Book *pBook = (*(*subTree).pBookBlock).getPBook();
	Book *dBook = (*bookBlock).getPBook();
	if ((*dBook) == (*pBook))
	{
		cout << "Check 1" << endl;
		deleteNode(subTree);
		return;
	}
	if ((*dBook) < (*pBook))
	{
		removeRecursive(bookBlock, subTree->left);
		return;
	}
	if ((*dBook) > (*pBook))
	{
		removeRecursive(bookBlock, subTree->right);
		return;
	}
	
	
}

void BST::deleteNode(Node *& subTree)
{
	if ((subTree->left == NULL) && (subTree->right == NULL))
	{
		delete subTree;
		subTree = NULL;
		return;
	}
	if (subTree->left == NULL)
	{
		Node *temp = subTree;
		subTree = subTree->right;
		delete temp;
		return;
	}
	if (subTree->right == NULL)
	{
		Node *temp = subTree;
		subTree = subTree->left;
		delete temp;
		return;
	}
	subTree->pBookBlock = findAndDeleteSmallest(subTree->right);
}

BookBlock* BST::findAndDeleteSmallest(Node *& subTree)
{
	if (subTree->left == NULL)
	{
		Node *temp = subTree;
		subTree = subTree->right;
		BookBlock* val = temp->pBookBlock;
		delete temp;
		return val;
	}
	return findAndDeleteSmallest(subTree->left);
}


ostream& operator<<(ostream &outstream,  BST tree)
{
	tree.printTree(outstream, tree.root);
	return outstream;
}

void BST::printTree(std::ostream &outstream, Node *subTree)
{
	if (subTree != NULL)
	{
		printTree(outstream, subTree->left);
		//outstream << "Hello World " << endl;

		Book *pBook = (*(*subTree).pBookBlock).getPBook();
		BookBlock *pBB = (*subTree).pBookBlock;
		outstream << endl;
		outstream << "Title : " << (*pBook).getTitle() << endl;
		outstream << "Author : " << (*pBook).getAuthor() << endl;
		if (isAudioBook(pBook))
		{
			AudioBook *pAB = dynamic_cast<AudioBook *>(pBook);
			cout << "Narrator: " << (*pAB).getNarrator() << endl;
		}
		if (isGraphicNovel(pBook))
		{
			GraphicNovel *pAB = dynamic_cast<GraphicNovel *>(pBook);
			cout <<"Artist : " << (*pAB).getArtist() << endl;
		}
		outstream << "New Books- Count: "<< (*pBB).getnewCount() << " Cost: " << (*pBB).getNewCost()<< endl;
		outstream << "Old Books- Excellent Condition- Count: " << (*pBB).getUsedExcellentCount() << " Cost: " << (*pBB).getUsedExcellentCost() << endl;
		outstream << "Old Books- Good Condition- Count: " << (*pBB).getUsedGoodCount() << " Cost: " << (*pBB).getUsedGoodCost() << endl;
		outstream << "Old Books- Fair Condition- Count: " << (*pBB).getUsedFairCount() << " Cost: " << (*pBB).getUsedFairCost() << endl;

		printTree(outstream, subTree->right);
	}
}


bool BST::isAudioBook(Book *b)
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

bool BST::isGraphicNovel(Book * pBook)
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

void BST::Clear()
{
	clearR(root);
}

void BST::clearR(Node * tree)
{
	if (tree != NULL)
	{
		clearR(tree->left);
		clearR(tree->right);
		delete tree;
		tree = NULL;
	}
}

