#ifndef heap_H
#define heap_H

template<class ItemType>
struct HeapType {
	ItemType *elements;
	int numElements;
	void ReheapDown(int, int);
	void ReheapUp(int, int);
};
#include "heap.cpp"
#endif