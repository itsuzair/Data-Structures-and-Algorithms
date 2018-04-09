#include "tree.h"
#include "vld.h"

int main() { 
	tree<int> myTree;
	myTree.insertItem(10);
	myTree.insertItem(7);
	myTree.insertItem(6);
	myTree.insertItem(8);
	myTree.insertItem(12);
	myTree.insertItem(15);
	myTree.insertItem(11);
	myTree.insertItem(7);
	//Print tree (In-order)
	cout << endl << endl << "IN ORDER : " << endl;
	myTree.printTree('i');
	//Print tree (POST-order)
	cout << endl << endl << "POST ORDER : " << endl;
	myTree.printTree('o');
	//Print tree (PRE-order)
	cout << endl << endl << "PRE ORDER : " << endl;
	myTree.printTree('p');
	cout << endl;
}