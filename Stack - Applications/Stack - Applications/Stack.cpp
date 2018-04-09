template <class TYPE>
STACK<TYPE>::STACK(int size = 100) {
	this->size = size;
	items = new TYPE[size];
	top = -1;
}

template <class TYPE>
bool STACK<TYPE>::isEmpty() const {
	return (top == -1);
}

template <class TYPE>
bool STACK<TYPE>::isFull() const {
	return (top == size - 1);
}

template <class TYPE>
void STACK<TYPE>::empty() const {
	top = -1;
}

template <class TYPE>
void STACK<TYPE>::push(TYPE item) {
	top++;
	items[top] = item;
}

template <class TYPE>
TYPE STACK<TYPE>::pop() {
	TYPE temp = items[top];
	top--;
	return temp;
}

template <class TYPE>
TYPE STACK<TYPE>::getTop() const {
	return items[top];
}

template<class TYPE>
STACK<TYPE>::~STACK() {
	delete items;
}