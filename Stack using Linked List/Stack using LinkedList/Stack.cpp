template <class TYPE>
STACK<TYPE>::STACK() {
	top = nullptr;
}

template <class TYPE>
bool STACK<TYPE>::isEmpty() const {
	return (top == nullptr);
}

template <class TYPE>
bool STACK<TYPE>::isFull() const {
	return 1;
}

template <class TYPE>
void STACK<TYPE>::empty() {
	while (!isEmpty()) {
		pop();
	}
}

template <class TYPE>
void STACK<TYPE>::push(TYPE item) {
	Node<TYPE> *temp = new Node<TYPE>;
	temp->setData(item);
	temp->setNext(top);
	top = temp;
}

template <class TYPE>
TYPE STACK<TYPE>::pop() {
	if (!isEmpty()) {
		Node<TYPE> *temp = top;
		top = top->getNext();
		TYPE retVal = temp->getData();
		delete temp;
		return retVal;
	}
	return 0;
}

template <class TYPE>
TYPE STACK<TYPE>::getTop() const {
	if (!isEmpty()) {
		return top->getData();
	}
	return 0;
}

template<class TYPE>
STACK<TYPE>::~STACK() {
	empty();
}