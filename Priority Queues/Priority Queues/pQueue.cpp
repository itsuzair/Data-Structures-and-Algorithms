template<class type>
pQueue<type>::pQueue(int maxElems) {
	maxItems = maxElems;
	numItems = 0;
	heap.elements = new type[maxItems];
}

template<class type>
void pQueue<type>::MakeEmpty() {
	numItems = 0;
}

template<class type>
bool pQueue<type>::IsEmpty() const {
	return numItems == 0;
}

template<class type>
bool pQueue<type>::IsFull() const {
	return numItems == maxItems;
}

template<class type>
void pQueue<type>::Enqueue(type item) {
	heap.elements[numItems] = item;
	numItems++;
	heap.ReheapUp(0, numItems - 1);
}

template<class type>
type pQueue<type>::Dequeue() {
	type item = heap.elements[0];
	heap.elements[0] = heap.elements[numItems - 1];
	numItems--;
	heap.ReheapDown(0, numItems - 1);
	return item;
}

template<class type>
pQueue<type>::~pQueue() {
	delete[] heap.elements;
}