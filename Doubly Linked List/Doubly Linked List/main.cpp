#include <iostream>
#include "linkedList.h"
#include <vld.h>
using namespace std;

void displayMenu();
template <class TYPE>
void handleInsert(linkedList<TYPE> &);
template <class TYPE>
void handleDelete(linkedList<TYPE> &);
int main() {
	linkedList<int> myList;
	char mainOption;
	bool keepRunning = true;
	while(keepRunning){
		displayMenu();
		cout << "Enter option : ";
		cin >> mainOption;
		switch (mainOption){
			case 'I' : case 'i':
				handleInsert(myList);
				break;
			case 'D' : case 'd':
				if(myList.isEmpty()){
					cout << endl << "List is empty, Cannot delete." << endl << endl;
				}else{
					handleDelete(myList);
				}
				break;
			case 'P' : case 'p':
				if(myList.isEmpty()){
					cout << endl << "List is empty." << endl << endl;
				}else{
					myList.print();
				}
				break;
			case 'G' : case 'g':
				if(myList.isEmpty()){
					cout << endl << "List is empty." << endl << endl;
				} else {
					int i = -1;
					do {
						cout << "Enter index no : ";
						cin >> i;
					} while (i < 0);
					cout << endl << "Value at index " << i << " is : " << myList[i].getData() << endl << endl;
				}
				break;
			case 'E' : case 'e':
				if(myList.isEmpty()){
					cout << endl << "List is already empty." << endl << endl;
				}else{
					myList.makeEmpty();
					cout << endl << "List emptied successfully." << endl << endl;
				}
				break;
			case 'Q' : case 'q':
				keepRunning = false;
				break;
			default:
				cout << endl << "Invalid option entered, please enter valid option." << endl << endl;
				break;
		}
	}
	return 0;
}

void displayMenu(){
	cout << "Please select operation you want to perform : " << endl << endl;
	cout << "Insert Element [I/i]" << endl;
	cout << "Delete Element [D/d]" << endl;
	cout << "Print List     [P/p]" << endl;
	cout << "Print Element  [G/g]" << endl;
	cout << "Empty List     [E/e]" << endl;
	cout << "Quit           [Q/q]" << endl << endl;
}

void displayInsertMenu(){
	cout << "Please select operation you want to perform : " << endl << endl;
	cout << "Insert First   [F/f]" << endl;
	cout << "Inset Last     [L/l]" << endl;
	cout << "Insert Before  [B/b]" << endl;
	cout << "Inset After    [A/a]" << endl << endl;
}

template <class TYPE>
void handleInsert(linkedList<TYPE> &myList) {
	TYPE val, searchVal;
	char secondaryOption;
	displayInsertMenu();
	cout << "Enter option : ";
	cin >> secondaryOption;
	switch (secondaryOption) {
	case 'F': case 'f':
		cout << "Enter value to insert : ";
		cin >> val;
		myList.insertFirst(val);
		cout << endl << "Value inserted successfully" << endl << endl;
		break;
	case 'L': case 'l':
		cout << "Enter value to insert : ";
		cin >> val;
		myList.insertLast(val);
		cout << endl << "Value inserted successfully" << endl << endl;
		break;
	case 'B': case 'b':
		if (myList.isEmpty()) {
			cout << endl << "List is empty, Cannot search in empty list." << endl << endl;
		} else {
			cout << "Enter value to insert before : ";
			cin >> searchVal;
			if (myList.inList(searchVal)) {
				cout << "Enter value to insert : ";
				cin >> val;
				myList.insertBefore(searchVal, val);
				cout << endl << "Value inserted successfully" << endl << endl;
			} else {
				cout << endl << "Cannot insert, Value not found" << endl << endl;
			}
		}
		break;
	case 'A': case 'a':
		if (myList.isEmpty()) {
			cout << endl << "List is empty, Cannot search in empty list." << endl << endl;
		} else {
			cout << "Enter value to insert after : ";
			cin >> searchVal;
			if (myList.inList(searchVal)) {
				cout << "Enter value to insert : ";
				cin >> val;
				myList.insertAfter(searchVal, val);
				cout << endl << "Value inserted successfully" << endl << endl;
			} else {
				cout << endl << "Cannot insert, Value not found" << endl << endl;
			}
		}
		break;
	default:
		cout << endl << "Invalid option entered, please enter valid option." << endl << endl;
		break;
	}
}


void displayDeleteMenu() {
	cout << "Please select operation you want to perform : " << endl << endl;
	cout << "Delete First   [F/f]" << endl;
	cout << "Delete Last    [L/l]" << endl;
	cout << "Delete Node    [N/n]" << endl << endl;
}

template <class TYPE>
void handleDelete(linkedList<TYPE> &myList) {
	char secondaryOption;
	displayDeleteMenu();
	cout << "Enter option : ";
	cin >> secondaryOption;
	switch (secondaryOption) {
	case 'F': case 'f':
		myList.deleteFirst();
		cout << endl << "Value deleted successfully" << endl << endl;
		break;
	case 'L': case 'l':
		myList.deleteLast();
		cout << endl << "Value deleted successfully" << endl << endl;
		break;
	case 'N': case 'n':
		TYPE val;
		cout << "Enter value to delete : ";
		cin >> val;
		if (myList.inList(val)) {
			myList.deleteNode(val);
			cout << endl << "Value deleted successfully" << endl << endl;
		} else {
			cout << endl << "Cannot delete, value not found" << endl << endl;
		}
		break;
	default:
		cout << endl << "Invalid option entered, Please enter valid option." << endl << endl;
		break;
	}
}