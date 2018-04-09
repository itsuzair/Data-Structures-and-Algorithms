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