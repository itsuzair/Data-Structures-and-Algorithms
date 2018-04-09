#ifndef _Node_H
#define _Node_H

template <class TYPE>
class Node {
public:
	Node();
	TYPE getData() const;
	void setData(int);
	Node<TYPE>* getNext();
	Node<TYPE>* getPrev();
	void setNext(Node<TYPE> *);
	void setPrev(Node<TYPE> *);
private:
	Node<TYPE>* prev;
	TYPE data;
	Node<TYPE>* next;
};

#endif
#include "node.cpp"
