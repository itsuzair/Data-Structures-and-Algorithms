#ifndef _QUEUE_
#define _QUEUE_H

template <class TYPE>

class QUEUE {
public:
	QUEUE(int);
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(TYPE);
	TYPE Dequeue();
	~QUEUE();
private:
	int front;
	int rear;
	TYPE *items;
	int maxItems;
};

#endif
#include "Queue.cpp"