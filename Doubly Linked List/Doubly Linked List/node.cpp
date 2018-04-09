template <class TYPE>
Node<TYPE>::Node()
{
	prev = nullptr;
	next = nullptr;
}

template<class TYPE>
TYPE Node<TYPE>::getData() const {
	return data;
}

template<class TYPE>
void Node<TYPE>::setData(int val) {
	data = val;
}

template<class TYPE>
Node<TYPE>* Node<TYPE>::getNext() {
	return next;
}

template<class TYPE>
Node<TYPE>* Node<TYPE>::getPrev() {
	return prev;
}

template<class TYPE>
void Node<TYPE>::setNext(Node<TYPE>* n) {
	next = n;
}

template<class TYPE>
void Node<TYPE>::setPrev(Node<TYPE>* p) {
	prev = p;
}