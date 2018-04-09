#include "heap.h"
#ifndef pQueue_H
#define pQueue_H

template<class type>
class pQueue {
public:
	pQueue(int);
	~pQueue();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(type);
	type Dequeue();
private:
	int numItems;
	HeapType<type> heap;
	int maxItems;
};

#endif // !pQueue_H
#include "pQueue.cpp"