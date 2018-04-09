#include <iostream>
#include "Queue.h"
using namespace std;
#ifndef tree_H
#define tree_H

template <class itemType>
struct treeNode {
	treeNode* left;
	itemType data;
	treeNode* right;
};

enum orderType{PRE_ORDER, IN_ORDER, POST_ORDER};

template <class itemType>
class tree {
public:
	tree();
	tree(const tree<itemType> &original);
	void makeEmpty();
	bool isEmpty() const;
	bool isFull() const;
	int numberOfNodes() const;
	bool retrieveItem(itemType item);
	void insertItem(itemType item);
	void deleteItem(itemType item);
	void printTree() const;
	void PreOrder(treeNode<itemType>* tree, QUEUE<itemType>& preQue);
	void InOrder(treeNode<itemType>* tree, QUEUE<itemType>& inQue);
	void PostOrder(treeNode<itemType>* tree, QUEUE<itemType>& postQue);
	void resetTree(orderType order);
	void getNextItem(itemType& item, orderType order, bool& found);
	void operator=(const tree<itemType>& original);
	~tree();
private:
	treeNode<itemType>* root;
	QUEUE<itemType> preQue;
	QUEUE<itemType> inQue;
	QUEUE<itemType> postQue;
};


#endif
#include "tree.cpp"