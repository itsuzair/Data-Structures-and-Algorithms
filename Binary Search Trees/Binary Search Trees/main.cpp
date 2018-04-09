#include "tree.h"
#include "vld.h"

int main() { 
	tree<int> myTree;
	/*
	//Is empty check
	if (myTree.isEmpty()) {
		cout << "Tree is empty" << endl;
	}
	
	//Insertring nodes - isFull check req'd before inserting
	if (!myTree.isFull()) {
		myTree.insertItem(8);
	}
	*/
	//Ain't nobody got time to add the check on all these
	//INSERTTTTTTTTTTT
	myTree.insertItem(10);
	myTree.insertItem(7);
	myTree.insertItem(6);
	/*
	myTree.insertItem(4);
	myTree.insertItem(12);
	myTree.insertItem(5);
	myTree.insertItem(3);
	
	//Print no. of nodes
	cout << "Tree has " << myTree.numberOfNodes() << " number of nodes" << endl;
	
	//Print tree (In-order)
	myTree.printTree();
	cout << endl;
	
	//Delete item (exists)
	if (myTree.retrieveItem(5)) {
		myTree.deleteItem(5);
		cout << "5 was deleted from tree" << endl;
	} else {
		cout << "5 was not found in tree" << endl;
	}
	
	//Delete item (doesn't exist)
	if (myTree.retrieveItem(55)) {
		myTree.deleteItem(5);
		cout << "55 was deleted from tree" << endl;
	} else {
		cout << "55 was not found in tree" << endl;
	}

	//Item search
	if (myTree.retrieveItem(3)) {
		cout << "3 was found in tree" << endl;
	} else {
		cout << "3 was not found in tree" << endl;
	}
	*/
	//Print tree (In-order)
	cout << endl << endl << "IN ORDER : " << endl;
	myTree.printTree();
	//Print tree (POST-order)
	cout << endl << endl << "POST ORDER : " << endl;
	myTree.resetTree(POST_ORDER);
	bool fin = false;
	int val;
	while (fin == false) {
		myTree.getNextItem(val, POST_ORDER, fin);
		cout << val << ", ";
	}
	//Print tree (PRE-order)
	cout << endl << endl << "PRE ORDER : " << endl;
	myTree.resetTree(PRE_ORDER);
	fin = false;
	while (fin == false) {
		myTree.getNextItem(val, PRE_ORDER, fin);
		cout << val << ", ";
	}
	cout << endl;
}