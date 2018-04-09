#ifndef treeNode_H
#define treeNode_H
template<class TYPE>
class treeNode {
public:
	treeNode();
	treeNode<TYPE>*& getLeft();
	void setLeft(treeNode *l);
	TYPE getData();
	void setData(TYPE d);
	treeNode<TYPE>*& getRight();
	void setRight(treeNode* r);
	int getHeight();
	void setHeight(int h);
private:
	treeNode* left;
	TYPE data;
	treeNode* right;
	int height;
};
#endif
#include "treeNode.cpp"