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
		Node<TYPE> *curr = new Node<TYPE>;
		curr->setData(val);
		curr->setNext(first);
		first = curr;
	}
}

template<class TYPE>
void linkedList<TYPE>::insertLast(TYPE val) {
	if (isEmpty()) {
		insertFirst(val);
	} else {
		Node<TYPE> *curr = first;
		while (curr->getNext() != nullptr) {
			curr = curr->getNext();
		}
		curr->setNext(new Node<TYPE>);
		curr = curr->getNext();
		curr->setData(val);
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
		Node<TYPE> *prev = first;
		while (curr->getNext() != nullptr) {
			prev = curr;
			curr = curr->getNext();
		}
		delete curr;
		prev->setNext(nullptr);
	}
}

//Pre-Condition : List is not empty AND Value to delete is present in list
template<class TYPE>
void linkedList<TYPE>::deleteNode(TYPE val) {
	if (first->getData() == val) {
		deleteFirst();
	} else {
		Node<TYPE> *curr = first;
		Node<TYPE> *prev = nullptr;
		while (curr->getNext() != nullptr && curr->getData() != val) {
			prev = curr;
			curr = curr->getNext();
		}
		prev->setNext(curr->getNext());
		delete curr;
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
}

template<class TYPE>
void linkedList<TYPE>::makeEmpty() {
	while (!isEmpty()) {
		deleteFirst();
	}
}

template<class TYPE>
void linkedList<TYPE>::merge(linkedList<TYPE>& list)
{
	Node<TYPE> *listBase = list.first;
	Node<TYPE> *base = nullptr;
	while (listBase->getNext() != nullptr) {
		base = first;
		if (listBase->getData() <= base->getData()) {
			insertFirst(listBase->getData());
		} else {
			while (base->getNext() != nullptr && listBase->getData() > base->getData()) {
				base = base->getNext();
			}
			if (listBase->getData() <= base->getData()) {
				insertBefore(base->getData(), listBase->getData());
			} else {
				insertLast(listBase->getData());
			}
		}
		listBase = listBase->getNext();
	}
	base = first;
	while (base->getNext() != nullptr && listBase->getData() > base->getData()) {
		base = base->getNext();
	}
	if (listBase->getData() <= base->getData()) {
		insertBefore(base->getData(), listBase->getData());
	} else {
		insertLast(listBase->getData());
	}
	list.makeEmpty();
}

//Pre-Condition : List is not empty AND Valid index is passed
template<class TYPE>
linkedList<TYPE> linkedList<TYPE>::split(int index) {
	int counter = -1;
	linkedList<TYPE> newList;
	Node<TYPE> *splitAt = first;
	Node<TYPE> *lastToKeep = first;
	while (counter != index) {
		lastToKeep = splitAt;
		splitAt = splitAt->getNext();
		counter++;
	}
	while (splitAt->getNext() != nullptr) {
		newList.insertLast(splitAt->getData());
		splitAt = splitAt->getNext();
	}
	newList.insertLast(splitAt->getData());
	while (lastToKeep->getNext() != nullptr) {
		deleteLast();
	}
	lastToKeep->setNext(nullptr);
	return newList;
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