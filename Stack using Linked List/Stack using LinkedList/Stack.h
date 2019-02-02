#include "node.h"
#ifndef _STACKS_H
#define _STACKS_H
const int maxItems = 10;
template <class TYPE>
class STACK
{
public:
	STACK();
	bool isEmpty() const;
	bool isFull() const;
	void empty();
	void push(TYPE);
	TYPE pop();
	TYPE getTop() const;
	~STACK();

private:
	Node<TYPE> *top;
};
#endif
#include "Stack.cpp"