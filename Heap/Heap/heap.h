#ifndef heap_H
#define heap_H

template<class ItemType>
class HeapType {
private:
	ItemType *elements;
	int numElements;
	int entries;
public:
	HeapType();
	HeapType(int);
	void ReheapDown(int, int);
	void ReheapUp(int, int);
	void insert(ItemType);
	ItemType del();
	void print();
	~HeapType();
};
#include "heap.cpp"
#endif