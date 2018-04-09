//Constructor
template<class TYPE>
tree<TYPE>::tree() {
	root = nullptr;
}

//Copy Constructor
template<class TYPE>
void copyTree(treeNode<TYPE>*& copy, const treeNode<TYPE>* original) {
	if (original == nullptr) {
		copy = nullptr;
	} else {
		copy = new treeNode<TYPE>;
		copy->setData(original->getData());
		copy->setHeight(original->getHeight());
		copyTree(copy->getLeft(), original->getLeft());
		copyTree(copy->getRight(), original->getRight());
	}
}

template<class TYPE>
tree<TYPE>::tree(const tree<TYPE>& original) {
	copyTree(root, original.root);
}

//= Operator
template<class TYPE>
void tree<TYPE>::operator=(const tree<TYPE>& original) {
	if (&original == this) {
		return;
	}
	deleteTree(root);
	copyTree(root, original.root);
}

//isEmpty
template<class TYPE>
bool tree<TYPE>::isEmpty() const {
	return root == nullptr;
}

//isFull
template<class TYPE>
bool tree<TYPE>::isFull() const {
	treeNode<TYPE>* location;
	try {
		location = new treeNode<TYPE>;
		delete location;
		return false;
	} catch (bad_alloc exception) {
		return true;
	}
}

//getRoot
template<class TYPE>
treeNode<TYPE>* tree<TYPE>::getRoot() {
	return root;
}

//Count nodes
template<class TYPE>
int countNodes(treeNode<TYPE>* tree) {
	if (tree == nullptr) {
		return 0;
	} else {
		return countNodes(tree->getLeft()) + countNodes(tree->getRight()) + 1;
	}
}

template<class TYPE>
int tree<TYPE>::numberOfNodes() const {
	return countNodes(root);
}

//Retreive item
template<class TYPE>
bool retreive(treeNode<TYPE>* tree, TYPE item) {
	if (tree == nullptr) {
		return false;
	} else if (item < tree->getData()) {
		return retreive(tree->getLeft(), item);
	} else if (item > tree->getData()) {
		return retreive(tree->getRight(), item);
	} else {
		return true;
	}
}

template<class TYPE>
bool tree<TYPE>::retrieveItem(TYPE item) {
	return retreive(root, item);
}

//Get height of tree
template<class TYPE>
int calcHeight(treeNode<TYPE>* tree) {
	int h = 0;
	if (tree == nullptr) {
		return -1;
	} else {
		int lHeight = calcHeight(tree->getLeft());
		int rHeight = calcHeight(tree->getRight());
		h = max(lHeight, rHeight) + 1;
	}
	return h;
}

//Get balance factor
template<class TYPE>
int getBalFac(treeNode<TYPE>* tree) {
	if (tree == nullptr) {
		return 0;
	}
	return tree->getLeft()->getHeight() - tree->getRight()->getHeight();
}

//Rotations
template<class TYPE>
treeNode<TYPE>* singleRightRotate(treeNode<TYPE>* &t) {
	treeNode<TYPE>* u = t->getLeft();
	t->setLeft(u->getRight());
	u->setRight(t);
	t->setHeight(calcHeight(t));
	u->setHeight(calcHeight(u));
	return u;
}

template<class TYPE>
treeNode<TYPE>* singleLeftRotate(treeNode<TYPE>* &t) {
	treeNode<TYPE>* u = t->getRight();
	t->setRight(u->getLeft());
	u->setLeft(t);
	t->setHeight(calcHeight(t));
	u->setHeight(calcHeight(u));
	return u;
}

template<class TYPE>
treeNode<TYPE>* doubleLeftRotate(treeNode<TYPE>* &t) {
	t->setRight(singleRightRotate(t->getRight()));
	return singleLeftRotate(t);
}

template<class TYPE>
treeNode<TYPE>* doubleRightRotate(treeNode<TYPE>* &t) {
	t->setLeft(singleLeftRotate(t->getLeft()));
	return singleRightRotate(t);
}

//Insert item
template<class TYPE>
treeNode<TYPE>* insert(treeNode<TYPE>*& tree, TYPE item) {
	if (tree == nullptr) {
		tree = new treeNode<TYPE>;
		tree->setData(item);
	} else if (item < tree->getData()) {
		tree->setLeft(insert(tree->getLeft(), item));
		if (tree->getLeft()->getHeight() - tree->getRight()->getHeight() == 2) {
			if (item < tree->getLeft()->getData()) {
				tree = singleRightRotate(tree);
			} else {
				tree = doubleRightRotate(tree);
			}
		}
	} else {
		insert(tree->getRight(), item);
		tree->setRight(insert(tree->getRight(), item));
		if (tree->getRight()->getHeight() - tree->getLeft()->getHeight() == 2) {
			if (item > tree->getRight()->getData()) {
				tree = singleLeftRotate(tree);
			} else {
				tree = doubleLeftRotate(tree);
			}
		}
	}
	tree->setHeight(calcHeight(tree));
	return tree;
}

template<class TYPE>
treeNode<TYPE>* tree<TYPE>::insertItem(TYPE item) {
	return insert(root, item);
}

//Delete item
template<class TYPE>
TYPE getPredecessor(treeNode<TYPE>* tree) {
	while (tree->getRight() != nullptr) {
		tree = tree->getRight();
	}
	return tree->getData();
}

template<class TYPE>
void deleteNode(treeNode<TYPE>*& tree) {
	treeNode<TYPE>* temp = tree;
	if (tree->getLeft() == nullptr) {
		tree = tree->getRight();
		delete temp;
	} else if (tree->getRight() == nullptr) {
		tree = tree->getLeft();
		delete temp;
	} else {
		tree->setData(getPredecessor(tree->getLeft()));
		deleteH(tree->getLeft(), tree->getData());
	}
}

template<class TYPE>
void deleteH(treeNode<TYPE>*& tree, TYPE item) {
	if (item < tree->getData()) {
		deleteH(tree->getLeft(), item);
	} else if (item > tree->getData()) {
		deleteH(tree->getRight(), item);
	} else {
		deleteNode(tree);
	}
}

template<class TYPE>
void tree<TYPE>::deleteItem(TYPE item) {
	deleteH(root, item);
}

//Functions to traverse as required
template<class TYPE>
void tree<TYPE>::preOrderPrint(treeNode<TYPE>* tree) {
	if (tree != nullptr) {
		cout << tree->getData() << ", ";
		preOrderPrint(tree->getLeft());
		preOrderPrint(tree->getRight());
	}
}

template<class TYPE>
void tree<TYPE>::inOrderPrint(treeNode<TYPE>* tree) {
	if (tree != nullptr) {
		inOrderPrint(tree->getLeft());
		cout << tree->getData() << ", ";
		inOrderPrint(tree->getRight());
	}
}

template<class TYPE>
void tree<TYPE>::postOrderPrint(treeNode<TYPE>* tree) {
	if (tree != nullptr) {
		postOrderPrint(tree->getLeft());
		postOrderPrint(tree->getRight());
		cout << tree->getData() << ", ";
	}

}

//Print Tree
template<class TYPE>
void tree<TYPE>::printTree(char type) {
	type = tolower(type);
	if (type == 'i') {
		inOrderPrint(root);
	} else if (type == 'p') {
		preOrderPrint(root);
	} else if (type == 'o') {
		postOrderPrint(root);
	}
}

//Destroy tree
template<class TYPE>
void deleteTree(treeNode<TYPE>*& tree) {
	if (tree != nullptr) {
		deleteTree(tree->getLeft());
		deleteTree(tree->getRight());
		delete tree;
	}
}

template<class TYPE>
void tree<TYPE>::makeEmpty() {
	deleteTree(root);
	root = nullptr;
}

template<class TYPE>
tree<TYPE>::~tree() {
	deleteTree(root);
}
