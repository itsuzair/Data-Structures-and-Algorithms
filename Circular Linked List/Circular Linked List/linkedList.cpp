template<class TYPE>
linkedList<TYPE>::linkedList() {
	last = nullptr;
}

template<class TYPE>
linkedList<TYPE>::linkedList(const linkedList &list) {
	last = nullptr;
	if (!list.isEmpty()) {
		Node<TYPE> *curr = list.last->getNext();
		do {
			insertLast(curr->getData());
			curr = curr->getNext();
		} while (curr != list.last->getNext());
	}
}

template<class TYPE>
bool linkedList<TYPE>::isEmpty() const {
	return (last == nullptr);
}

//Pre-Condition : List is not empty
template<class TYPE>
bool linkedList<TYPE>::inList(TYPE val) const {
	Node<TYPE> *base = last->getNext();
	do {
		if (base->getData() == val) {
			return true;
		}
		base = base->getNext();
	} while (base != last->getNext());
	return false;
}

template<class TYPE>
void linkedList<TYPE>::insertFirst(TYPE val) {
	if (isEmpty()) {
		last = new Node<TYPE>;
		last->setData(val);
		last->setNext(last);
	} else {
		Node<TYPE> *temp = new Node<TYPE>;
		temp->setData(val);
		temp->setNext(last->getNext());
		last->setNext(temp);
	}
}

template<class TYPE>
void linkedList<TYPE>::insertLast(TYPE val) {
	if (isEmpty()) {
		insertFirst(val);
	} else {
		Node<TYPE>* temp = new Node<TYPE>;
		temp->setNext(last->getNext());
		temp->setData(val);
		last->setNext(temp);
		last = temp;
	}
}

//Pre-Condition : List is not empty AND Value to insert before is present in list
template<class TYPE>
void linkedList<TYPE>::insertBefore(TYPE beforeVal, TYPE val) {
	if (last->getNext()->getData() == beforeVal) {
		insertFirst(val);
	} else {
		Node<TYPE> *curr = last->getNext();
		do {
			if (curr->getData() == beforeVal) {
				Node<TYPE> *temp = new Node<TYPE>;
				temp->setNext(curr->getNext());
				temp->setData(curr->getData());
				curr->setData(val);
				curr->setNext(temp);
				if (curr == last) {
					last = temp;
				}
				break;
			}
			curr = curr->getNext();
		} while (curr != last->getNext());
	}
}

//Pre-Condition : List is not empty AND Value to insert after is present in list
template<class TYPE>
void linkedList<TYPE>::insertAfter(TYPE afterVal, TYPE val) {
	if (last->getData() == afterVal) {
		insertLast(val);
	} else {
		Node<TYPE> *curr = last->getNext();
		while (curr != last) {
			if (curr->getData() == afterVal) {
				Node<TYPE> *temp = new Node<TYPE>;
				temp->setNext(curr->getNext());
				temp->setData(val);
				curr->setNext(temp);
				break;
			}
			curr = curr->getNext();
		}
	}
}

//Pre-Condition : List is not empty
template<class TYPE>
void linkedList<TYPE>::deleteFirst() {
	if (last->getNext() == last) {
		delete last;
		last = nullptr;
	} else {
		Node<TYPE> *temp = last->getNext()->getNext();
		delete last->getNext();
		//last->getNext() = nullptr;
		last->setNext(temp);
	}
}

//Pre-Condition : List is not empty
template<class TYPE>
void linkedList<TYPE>::deleteLast() {
	if (last->getNext() == last) {
		delete last;
		last = nullptr;
	} else {
		Node<TYPE> *temp = last->getNext();
		Node<TYPE> *prev = last->getNext();
		while (temp != last) {
			prev = temp;
			temp = temp->getNext();
		}
		prev->setNext(temp->getNext());
		last = prev;
		delete temp;
		temp = nullptr;
	}
}

//Pre-Condition : List is not empty AND Value to delete is present in list
template<class TYPE>
void linkedList<TYPE>::deleteNode(TYPE val) {
	if (last->getData() == val) {
		deleteLast();
	}else if (last->getNext()->getData() == val) {
		deleteFirst();
	} else {
		Node<TYPE> *temp = last->getNext();
		Node<TYPE> *prev = last->getNext();
		do {
			if (temp->getData() == val) {
				prev->setNext(temp->getNext());
				delete temp;
				temp = nullptr;
				break;
			}
			prev = temp;
			temp = temp->getNext();
		} while (temp != last->getNext());
	}
}

//Pre-Condition : List is not empty
template<class TYPE>
void linkedList<TYPE>::print() const {
	cout << endl << "List Values : ";
	Node<TYPE> *base = last->getNext();
	do {
		cout << base << " " << base->getData() << " " << base->getNext() << endl;
		base = base->getNext();
	} while (base != last->getNext());
}

template<class TYPE>
void linkedList<TYPE>::makeEmpty() {
	while (!isEmpty()) {
		deleteFirst();
	}
}
/*
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
*/
template<class TYPE>
linkedList<TYPE>::~linkedList() {
	makeEmpty();
}