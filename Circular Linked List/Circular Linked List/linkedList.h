#include "node.h"
#ifndef _linkedList_H
#define _linkedList_H

template<class TYPE>
class linkedList {
public:
	linkedList();
	linkedList(const linkedList &);
	bool isEmpty() const;
	bool inList(TYPE) const;
	void insertFirst(TYPE);
	void insertLast(TYPE);
	void insertBefore(TYPE, TYPE);
	void insertAfter(TYPE, TYPE);
	void deleteFirst();
	void deleteLast();
	void deleteNode(TYPE);
	void print() const;
	void makeEmpty();
	//linkedList<TYPE>& operator=(const linkedList<TYPE> &);
	//Node<TYPE>& operator[](int index);
	~linkedList();
private:
	Node<TYPE> *last;
};

#endif
#include "linkedList.cpp"