#ifndef _STACKS_H
#define _STACKS_H

template <class TYPE>
class STACK {
public:
	STACK(int);
	bool isEmpty() const;
	bool isFull() const;
	void empty() const;
	void push(TYPE);
	TYPE pop();
	TYPE getTop() const;
	~STACK();

private:
	int top;
	int size;
	TYPE *items;
};
#endif
#include "Stack.cpp";