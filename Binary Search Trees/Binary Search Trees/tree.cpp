//Constructor
template<class itemType>
tree<itemType>::tree() {
	root = nullptr;
}

//Copy Constructor
template<class itemType>
void copyTree(treeNode<itemType>*& copy, const treeNode<itemType>* original) {
	if (original == nullptr) {
		copy = nullptr;
	} else {
		copy = new treeNode<itemType>;
		copy->data = original->data;
		copyTree(copy->left, original->left);
		copyTree(copy->right, original->right);
	}
}

template<class itemType>
tree<itemType>::tree(const tree<itemType>& original) {
	copyTree(root, original.root);
}

//= Operator
template<class itemType>
void tree<itemType>::operator=(const tree<itemType>& original) {
	if (&original == this) {
		return;
	}
	deleteTree(root);
	copyTree(root, original.root);
}

//isEmpty
template<class itemType>
bool tree<itemType>::isEmpty() const {
	return root == nullptr;
}

//isFull
template<class itemType>
bool tree<itemType>::isFull() const {
	treeNode<itemType>* location;
	try {
		location = new treeNode<itemType>;
		delete location;
		return false;
	} catch (bad_alloc exception) {
		return true;
	}
}

//Count nodes
template<class itemType>
int countNodes(treeNode<itemType>* tree) {
	if (tree == nullptr) {
		return 0;
	} else {
		return countNodes(tree->left) + countNodes(tree->right) + 1;
	}
}

template<class itemType>
int tree<itemType>::numberOfNodes() const {
	return countNodes(root);
}

//Retreive item
template<class itemType>
bool retreive(treeNode<itemType>* tree, itemType item) {
	if (tree == nullptr) {
		return false;
	} else if (item < tree->data) {
		return retreive(tree->left, item);
	} else if (item > tree->data) {
		return retreive(tree->right, item);
	} else {
		return true;
	}
}

template<class itemType>
bool tree<itemType>::retrieveItem(itemType item) {
	return retreive(root, item);
}

//Insert item
template<class itemType>
void insert(treeNode<itemType>*& tree, itemType item) {
	if (tree == nullptr) {
		tree = new treeNode<itemType>;
		tree->right = nullptr;
		tree->data = item;
		tree->left = nullptr;
	} else if (item < tree->data) {
		insert(tree->left, item);
	} else {
		insert(tree->right, item);
	}
}

template<class itemType>
void tree<itemType>::insertItem(itemType item) {
	insert(root, item);
}

//Delete item
template<class itemType>
itemType getPredecessor(treeNode<itemType>* tree) {
	while (tree->right != nullptr) {
		tree = tree->right;
	}
	return tree->data;
}

template<class itemType>
void deleteNode(treeNode<itemType>*& tree) {
	treeNode<itemType>* temp = tree;
	if (tree->left == nullptr) {
		tree = tree->right;
		delete temp;
	} else if (tree->right == nullptr) {
		tree = tree->left;
		delete temp;
	} else {
		tree->data = getPredecessor(tree->left);
		deleteH(tree->left, data);
	}
}

template<class itemType>
void deleteH(treeNode<itemType>*& tree, itemType item) {
	if (item < tree->data) {
		deleteH(tree->left, item);
	} else if (item > tree->data) {
		deleteH(tree->right, item);
	} else {
		deleteNode(tree);
	}
}

template<class itemType>
void tree<itemType>::deleteItem(itemType item) {
	deleteH(root, item);
}

//Print Tree
template<class itemType>
void print(treeNode<itemType>* tree) {
	if (tree != nullptr) {
		print(tree->left);
		cout << tree->data << ", ";
		print(tree->right);
	}
}

template<class itemType>
void tree<itemType>::printTree() const {
	print(root);
}

//Function to traverse as required
template<class itemType>
void tree<itemType>::PreOrder(treeNode<itemType>* tree, QUEUE<itemType>& preQue) {
	if (tree != nullptr) {
		preQue.Enqueue(tree->data);
		PreOrder(tree->left, preQue);
		PreOrder(tree->right, preQue);
	}
}

template<class itemType>
void tree<itemType>::InOrder(treeNode<itemType>* tree, QUEUE<itemType>& inQue) {
	if (tree != nullptr) {
		InOrder(tree->left, inQue);
		inQue.Enqueue(tree->data);
		InOrder(tree->right, inQue);
	}
}

template<class itemType>
void tree<itemType>::PostOrder(treeNode<itemType>* tree, QUEUE<itemType>& postQue) {
	if (tree != nullptr) {
		PostOrder(tree->left, postQue);
		PostOrder(tree->right, postQue);
		postQue.Enqueue(tree->data);
	}

}

template<class itemType>
void tree<itemType>::resetTree(orderType order) {
	switch (order) {
	case PRE_ORDER:
		PreOrder(root, preQue);
		break;
	case IN_ORDER:
		InOrder(root, inQue);
		break;
	case POST_ORDER:
		PostOrder(root, postQue);
		break;
	}
}

template<class itemType>
void tree<itemType>::getNextItem(itemType& item, orderType order, bool& finished) {
	finished = false;
	switch (order) {
	case PRE_ORDER:
		item = preQue.Dequeue();
		if (preQue.isEmpty())
			finished = true;
		break;
	case IN_ORDER:
		item = inQue.Dequeue();
		if (inQue.isEmpty())
			finished = true;
		break;
	case POST_ORDER:
		item = postQue.Dequeue();
		if (postQue.isEmpty())
			finished = true;
		break;
	}
}

//Destroy tree
template<class itemType>
void deleteTree(treeNode<itemType>*& tree) {
	if (tree != nullptr) {
		deleteTree(tree->left);
		deleteTree(tree->right);
		delete tree;
	}
}

template<class itemType>
void tree<itemType>::makeEmpty() {
	deleteTree(root);
	root = nullptr;
}

template<class itemType>
tree<itemType>::~tree() {
	deleteTree(root);
}
