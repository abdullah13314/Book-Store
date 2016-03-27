#pragma once
#include<iostream>
#include<string>
#include<math.h>
#include <cmath>
#include <stdlib.h>
#include "BookBlock.h"
#include "Book.h"
#include "GraphicNovel.h"
#include "AudioBook.h"

using namespace std;
class BST
{
	friend ostream& operator<<(ostream &outstream,  BST tree);
public:
	BST();
	~BST();

	bool Add(BookBlock *&bookBlock);//
	bool Remove(BookBlock *&bookBlock);//
	void Clear();


private:
	struct Node {
		BookBlock *pBookBlock = NULL;
		Node *left = NULL;
		Node *right = NULL;
	};
	Node *root;
	void addRecursive(BookBlock *&bookBlock, Node *&subTree);//
	void printTree(ostream &outstream, Node *tree) ;
	void removeRecursive(BookBlock *&bookBlock, Node* &pNode);//
	void deleteNode(Node *&pNode);//
	BookBlock* findAndDeleteSmallest(Node *&pNode);//
	bool isAudioBook(Book *b);
	bool isGraphicNovel(Book *b);
	void clearR(Node * tree);
};

/*
class BST
{
	template<class ItemType>
	friend ostream& operator<<(ostream &outstream, const BST<ItemType> &tree);//
public:
	BST();//
	BST(const BST &tree);//
	~BST();//

	int InsertOrIncrement(ItemType *item);//
	int RemoveOrDecrement(ItemType target, ItemType &result);//
	int Count(ItemType targetItem) const;//
	int getCountNode() const;
	bool isEmpty() const;//
	void ClearTree();//
	int Height() const;//
	BST operator+(const BST &tree) const;//
	BST& operator+=(const BST &tree);
	BST& operator=(const BST &tree);//


protected:
	struct Node
	{
		ItemType *item;
		int count;
		Node *left = NULL;
		Node *right = NULL;
		color nodeColor = red;

	};
	int countNodes = 0;
	Node *root = NULL;

	void insertOrIncrementRecursive(ItemType *item, Node *&subTree, int &returnCount);//
	void printTree(ostream &outstream, Node *tree) const;//
	int countRecursive(ItemType targetItem, Node *pNode) const;//
	int removeOrDecrementRecursive(ItemType target, ItemType &result, Node* &pNode);//
	void deleteNode(Node *&pNode);
	ItemType findAndDeleteSmallest(Node *&pNode, int &count);//
	void clearTreeRecursive(Node *&pNode);//
	int heightRecursive(Node *pNode, int height) const;//
	void assignmentOperator(Node *&rNode, Node *sNode);
	void addRecursive(Node *pNode);
};

template<class ItemType>
BST<ItemType>::BST()
{
}

template<class ItemType>
BST<ItemType>::BST(const BST<ItemType> &tree)
{
	*this = tree;
}

template<class ItemType>
BST<ItemType>::~BST()
{
	ClearTree();
}

template<class ItemType>
int BST<ItemType>::getCountNode() const
{
	return countNodes;
}


template<class ItemType>
int BST<ItemType>::InsertOrIncrement(ItemType *item)
{
	int returnCount;
	insertOrIncrementRecursive(item, root, returnCount);
	return returnCount;
}

template<class ItemType>
void BST<ItemType>::insertOrIncrementRecursive(ItemType *item, Node * &subTree, int &returnCount)
{
	if (subTree == NULL)
	{
		countNodes++;
		ItemType *pItem = new ItemType;
		*pItem = *item;
		Node *pNode = new Node;
		pNode->item = pItem;
		pNode->count = 1;
		returnCount = pNode->count;
		subTree = pNode;
		return;
	}
	if (*(subTree->item) == *item)
	{
		(subTree->count)++;
		returnCount = subTree->count;
		return;
	}
	if (*(subTree->item) > *item)
	{
		insertOrIncrementRecursive(item, subTree->left, returnCount);
		return;
	}
	else
	{
		insertOrIncrementRecursive(item, subTree->right, returnCount);
		return;
	}

}

template<class ItemType>
ostream& operator<<(ostream &outstream, const BST<ItemType> &tree)
{
	tree.printTree(outstream, tree.root);
	return outstream;
}

template<class ItemType>
void BST<ItemType>::printTree(std::ostream &outstream, Node *tree) const
{
	if (tree != NULL)
	{
		printTree(outstream, tree->left);
		outstream << tree->count << " " << *(tree->item) << endl;
		printTree(outstream, tree->right);
	}
}

template<class ItemType>
bool BST<ItemType>::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class ItemType>
int BST<ItemType>::Count(ItemType targetItem) const
{
	return countRecursive(targetItem, root);

}

template<class ItemType>
int BST<ItemType>::countRecursive(ItemType targetItem, Node *pNode) const
{
	if (pNode == NULL)
	{
		return -1;
	}
	if (*(pNode->item) == targetItem)
	{
		return pNode->count;
	}
	if (*(pNode->item) > targetItem)
	{
		return countRecursive(targetItem, pNode->left);
	}
	if (*(pNode->item) < targetItem)
	{
		return countRecursive(targetItem, pNode->right);
	}
	return -1;
}

template<class ItemType>
int BST<ItemType>::RemoveOrDecrement(ItemType target, ItemType &result)
{
	return removeOrDecrementRecursive(target, result, root);
}

template<class ItemType>
int BST<ItemType>::removeOrDecrementRecursive(ItemType target, ItemType &result, Node* &pNode)
{
	if (pNode == NULL)
	{
		return -1;
	}
	if (*(pNode->item) == target)
	{
		result = *(pNode->item);
		(pNode->count)--;
		if (pNode->count == 0)
		{
			countNodes--;
			deleteNode(pNode);
			return 0;
		}
		return pNode->count;
	}
	if (*(pNode->item) > target)
	{
		return removeOrDecrementRecursive(target, result, pNode->left);
	}
	if (*(pNode->item) < target)
	{
		return removeOrDecrementRecursive(target, result, pNode->right);
	}
	return -1;
}

template<class ItemType>
void BST<ItemType>::deleteNode(Node *&pNode)
{
	if ((pNode->left == NULL) && (pNode->right == NULL))
	{
		delete pNode->item;
		delete pNode;
		pNode = NULL;
		return;
	}
	if (pNode->left == NULL)
	{
		Node *temp = pNode;
		pNode = pNode->right;
		delete temp->item;
		delete temp;
		return;
	}
	if (pNode->right == NULL)
	{
		Node *temp = pNode;
		pNode = pNode->left;
		delete temp->item;
		delete temp;
		return;
	}
	int pCount = 0;
	*(pNode->item) = findAndDeleteSmallest(pNode->right, pCount);
	pNode->count = pCount;
}

template<class ItemType>
ItemType BST<ItemType>::findAndDeleteSmallest(Node *&pNode, int &pcount)
{
	if (pNode->left == NULL)
	{
		Node *temp = pNode;
		pNode = pNode->right;
		ItemType val = *(temp->item);
		pcount = temp->count;
		delete temp->item;
		delete temp;
		return val;
	}
	return findAndDeleteSmallest(pNode->left, pcount);
}


template<class ItemType>
void BST<ItemType>::ClearTree()
{
	clearTreeRecursive(root);
}

template<class ItemType>
void BST<ItemType>::clearTreeRecursive(Node *&pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	if (pNode->left != NULL)
	{
		clearTreeRecursive(pNode->left);
	}
	if (pNode->right != NULL)
	{
		clearTreeRecursive(pNode->right);
	}
	delete pNode->item;
	delete pNode;
	pNode = NULL;
}

template<class ItemType>
int BST<ItemType>::Height() const
{
	int height = 0;
	return heightRecursive(root, height);
}

template<class ItemType>
int BST<ItemType>::heightRecursive(Node *pNode, int height) const
{
	if (pNode == NULL)
	{
		return height;
	}
	height++;
	return fmax(heightRecursive(pNode->left, height), heightRecursive(pNode->right, height));
}

template<class ItemType>
BST<ItemType>& BST<ItemType>::operator=(const BST &tree)
{
	if (this == &tree)
	{
		return *this;
	}
	this->ClearTree();
	this->root = NULL;
	assignmentOperator(root, tree.root);
	return *this;
}

template<class ItemType>
void BST<ItemType>::assignmentOperator(Node *&rNode, Node *sNode)
{
	if (sNode == NULL)
	{
		return;
	}
	ItemType *pItem = new ItemType;
	*pItem = *(sNode->item);
	Node *pNode = new Node;
	pNode->item = pItem;
	pNode->count = sNode->count;
	pNode->left = NULL;
	pNode->right = NULL;
	rNode = pNode;
	assignmentOperator(rNode->left, sNode->left);
	assignmentOperator(rNode->right, sNode->right);
}

template<class ItemType>
BST<ItemType> BST<ItemType>::operator+(const BST &tree) const
{
	BST<ItemType> t1 = *this;
	t1 += tree;
	return t1;
}

template<class ItemType>
BST<ItemType>& BST<ItemType>::operator+=(const BST<ItemType> &tree)
{
	if (tree.root != NULL)
	{
		addRecursive(tree.root);
	}
	return *this;
}

template<class ItemType>
void BST<ItemType>::addRecursive(Node *pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	for (int i = 0; i < pNode->count; i++)
	{
		InsertOrIncrement(pNode->item);
	}
	addRecursive(pNode->left);
	addRecursive(pNode->right);
}

*/