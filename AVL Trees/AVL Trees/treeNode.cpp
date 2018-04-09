template<class TYPE>
treeNode<TYPE>::treeNode() {
	left = nullptr;
	right = nullptr;
	data = TYPE();
	height = 0;
}

template<class TYPE>
treeNode<TYPE>*& treeNode<TYPE>::getLeft() {
	return left;
}

template<class TYPE>
void treeNode<TYPE>::setLeft(treeNode * l) {
	left = l;
}

template<class TYPE>
TYPE treeNode<TYPE>::getData() {
	return data;
}

template<class TYPE>
void treeNode<TYPE>::setData(TYPE d) {
	data = d;
}

template<class TYPE>
treeNode<TYPE>*& treeNode<TYPE>::getRight() {
	return right;
}

template<class TYPE>
void treeNode<TYPE>::setRight(treeNode * r) {
	right = r;
}

template<class TYPE>
int treeNode<TYPE>::getHeight() {
	if (this == nullptr) {
		return -1;
	} else {
		return height;
	}
}

template<class TYPE>
void treeNode<TYPE>::setHeight(int h) {
	height = h;
}