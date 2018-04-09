template<class ItemType>
HeapType<ItemType>::HeapType() {

}

template<class ItemType>
HeapType<ItemType>::HeapType(int num) {
	numElements = num;
	entries = -1;
	elements = new ItemType[numElements];
}

template<class itemType>
void Swap(itemType* elements, itemType a, itemType b) {
	itemType c = elements[a];
	elements[a] = elements[b];
	elements[b] = c;
}

template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom) {
	int maxChild, rightChild, leftChild;
	leftChild = 2 * root + 1;
	rightChild = 2 * root + 2;
	if (leftChild <= bottom) {
		if (leftChild == bottom){
			maxChild = leftChild;
		} else {
			maxChild = (elements[leftChild] <= elements[rightChild]) ? rightChild : leftChild;
		}
		if (elements[root] < elements[maxChild]) {
			Swap(elements, root, maxChild);
			ReheapDown(maxChild, bottom);
		}
	}
}

template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom) {
	int parent;
	if (bottom > root) {
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom]) {
			Swap(elements, parent, bottom);
			ReheapUp(root, parent);
		}
	}
}

template<class ItemType>
void HeapType<ItemType>::insert(ItemType val) {
	if (entries+1 < numElements) {
		entries++;
		elements[entries] = val;
		ReheapUp(0, entries);
	} else {
		cout << "Max entries inserted" << endl;
	}
}

template<class ItemType>
ItemType HeapType<ItemType>::del() {
	int root = elements[0];
	elements[0] = elements[entries];
	entries--;
	ReheapDown(0, entries);
	return root;
}

template<class ItemType>
void HeapType<ItemType>::print() {
	cout << "Total entries : " << entries+1 << endl;
	for (int i = 0; i < entries; i++) {
		cout << elements[i] << ", ";
	}
	cout << elements[entries];
	cout << endl;
}

template<class ItemType>
HeapType<ItemType>::~HeapType() {
	delete[] elements;
}