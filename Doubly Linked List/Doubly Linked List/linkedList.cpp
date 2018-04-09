//ANY AND ALL PRECONDITION(S)
//MUST BE CHECKED IN CLIENT CODE.

template<class TYPE>
linkedList<TYPE>::linkedList() {
	first = nullptr;
}

template<class TYPE>
linkedList<TYPE>::linkedList(const linkedList &list) {
	first = nullptr;
	if (!list.isEmpty()) {
		Node<TYPE> *curr = list.first;
		while (curr->getNext() != nullptr) {
			insertLast(curr->getData());
			curr = curr->getNext();
		}
		insertLast(curr->getData());
	}
}

template<class TYPE>
bool linkedList<TYPE>::isEmpty() const {
	return (first == nullptr);
}

//Pre-Condition : List is not empty
template<class TYPE>
bool linkedList<TYPE>::inList(TYPE val) const {
	Node<TYPE> *base = first;
	while(base->getNext() != nullptr) {
		if (base->getData() == val) {
			return true;
		} else {
			base = base->getNext();
		}
	}
	return base->getData() == val;
}

template<class TYPE>
void linkedList<TYPE>::insertFirst(TYPE val) {
	if (isEmpty()) {
		first = new Node<TYPE>;
		first->setData(val);
	} else {
		Node<TYPE> *temp = new Node<TYPE>;
		temp->setData(val);
		temp->setNext(first);
		first->setPrev(temp);
		first = temp;
	}
}

template<class TYPE>
void linkedList<TYPE>::insertLast(TYPE val) {
	if (isEmpty()) {
		insertFirst(val);
	} else {
		Node<TYPE> *temp = first;
		while (temp->getNext() != nullptr) {
			temp = temp->getNext();
		}
		temp->setNext(new Node<TYPE>);
		temp->getNext()->setPrev(temp);
		temp->getNext()->setData(val);
	}
}

//Pre-Condition : List is not empty AND Value to insert before is present in list
template<class TYPE>
void linkedList<TYPE>::insertBefore(TYPE beforeVal, TYPE val) {
	Node<TYPE> *curr = first;
	while (curr->getNext() != nullptr && curr->getData() != beforeVal) {
		curr = curr->getNext();
	}
	Node<TYPE> *temp = new Node<TYPE>;
	temp->setNext(curr->getNext());
	temp->setData(curr->getData());
	curr->setData(val);
	curr->setNext(temp);
}

//Pre-Condition : List is not empty AND Value to insert after is present in list
template<class TYPE>
void linkedList<TYPE>::insertAfter(TYPE afterVal, TYPE val) {
	Node<TYPE> *curr = first;
	while (curr->getNext() != nullptr && curr->getData() != afterVal) {
		curr = curr->getNext();
	}
	Node<TYPE> *temp = new Node<TYPE>;
	temp->setPrev(curr);
	temp->setNext(curr->getNext());
	temp->setData(val);
	curr->setNext(temp);
}

//Pre-Condition : List is not empty
template<class TYPE>
void linkedList<TYPE>::deleteFirst() {
	Node<TYPE> *temp = first->getNext();
	delete first;
	first = temp;
}

//Pre-Condition : List is not empty
template<class TYPE>
void linkedList<TYPE>::deleteLast() {
	if (first->getNext() == nullptr) {
		deleteFirst();
	} else {
		Node<TYPE> *curr = first;
		while (curr->getNext() != nullptr) {
			curr = curr->getNext();
		}
		curr->getPrev()->setNext(nullptr);
		delete curr;
		curr = nullptr;
	}
}

//Pre-Condition : List is not empty AND Value to delete is present in list
template<class TYPE>
void linkedList<TYPE>::deleteNode(TYPE val) {
	if (first->getData() == val) {
		deleteFirst();
	} else {
		Node<TYPE> *curr = first;
		while (curr->getNext() != nullptr && curr->getData() != val) {
			curr = curr->getNext();
		}
		curr->getPrev()->setNext(curr->getNext());
		if (curr->getNext() != nullptr) {
			curr->getNext()->setPrev(curr->getPrev());
		}
		delete curr;
		curr = nullptr;
	}
}

//Pre-Condition : List is not empty
template<class TYPE>
void linkedList<TYPE>::print() const {
	cout << endl << "List Values : ";
	Node<TYPE> *base = first;
	while (base->getNext() != nullptr) {
		cout << base->getData() << ", ";
		base = base->getNext();
	}
	cout << base->getData() << endl << endl;
	/*
	Debug Print
	cout << endl;
	while (base->getNext() != nullptr) {
		cout << endl << base->getPrev() << " " << base->getData() << "(" << base  << ")" << " " << base->getNext();
		base = base->getNext();
	}
	cout << endl << base->getPrev() << " " << base->getData() << "(" << base << ")"  << " " << base->getNext();
	*/
}

template<class TYPE>
void linkedList<TYPE>::makeEmpty() {
	while (!isEmpty()) {
		deleteFirst();
	}
}

template<class TYPE>
linkedList<TYPE>& linkedList<TYPE>::operator=(const linkedList<TYPE> &list) {
	if (&list != this) {
		if (first != nullptr) {
			makeEmpty();
		}
		first = nullptr;
		if (!list.isEmpty()) {
			Node<TYPE> *curr = list.first;
			while (curr->getNext() != nullptr) {
				insertLast(curr->getData());
				curr = curr->getNext();
			}
			insertLast(curr->getData());
		}
	}
	return *this;
}

template<class TYPE>
Node<TYPE>& linkedList<TYPE>::operator[](int index) {
	Node<TYPE> *curr = first;
	int i = 0;
	while (curr->getNext() != nullptr && index !=i) {
		curr = curr->getNext();
		i++;
	}
	return *curr;
}

template<class TYPE>
linkedList<TYPE>::~linkedList() {
	makeEmpty();
}