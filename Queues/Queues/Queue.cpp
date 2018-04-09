template<class TYPE>
QUEUE<TYPE>::QUEUE(int maxItems = 10) {
	this->maxItems = (maxItems + 1);
	front = rear = maxItems;
	items = new TYPE[this->maxItems];
}

template<class TYPE>
void QUEUE<TYPE>::MakeEmpty() {
	front = rear = (maxItems - 1);
}

template<class TYPE>
bool QUEUE<TYPE>::IsEmpty() const {
	return rear == front;
}

template<class TYPE>
bool QUEUE<TYPE>::IsFull() const {
	return ((rear + 1) % maxItems == front);
}

template<class TYPE>
void QUEUE<TYPE>::Enqueue(TYPE item) {
	rear = (rear + 1) % maxItems;
	items[rear] = item;
}

template<class TYPE>
TYPE QUEUE<TYPE>::Dequeue() {
	front = (front + 1) % maxItems;
	return items[front];
}

template<class TYPE>
QUEUE<TYPE>::~QUEUE() {
	delete[]items;
}
