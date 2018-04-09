#include <algorithm>
#include <iostream>
#include "treeNode.h"
using namespace std;

#ifndef tree_H
#define tree_H

template <class TYPE>
class tree {
public:
	tree();
	tree(const tree<TYPE> &original);
	void makeEmpty();
	bool isEmpty() const;
	bool isFull() const;
	treeNode<TYPE>* getRoot();
	int numberOfNodes() const;
	bool retrieveItem(TYPE item);
	treeNode<TYPE>* insertItem(TYPE item);
	void deleteItem(TYPE item);
	void preOrderPrint(treeNode<TYPE>* tree);
	void inOrderPrint(treeNode<TYPE>* tree);
	void postOrderPrint(treeNode<TYPE>* tree);
	void printTree(char type);
	void operator=(const tree<TYPE>& original);
	~tree();
private:
	treeNode<TYPE>* root;
};


#endif
#include "tree.cpp"