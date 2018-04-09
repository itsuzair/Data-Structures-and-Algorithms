#include <iostream>
using namespace std;

void insert(int arr[][2], int &first, int &free, int val);
void deleteFirst(int arr[][2], int &first, int &free);
void makeEmpty(int arr[][2], int &first, int &free);

void print(int arr[][2], int first);

int main() {

	int myList[10][2]; // Create 2d array (10 rows, 2 cols) (cols for data and next ptr)
	
	for (int i = 0; i < 9; i++) {
		myList[i][1] = i + 1; //set next's for all indexes to next index
	}
	myList[9][1] = -1; //set last index's next to -1 to specify a null

	int first = -1; //first ptr to null
	int free = 0; //next free index to zero


	insert(myList, first, free, 10);
	insert(myList, first, free, 20);
	insert(myList, first, free, 30);
	insert(myList, first, free, 40);
	insert(myList, first, free, 50);
	insert(myList, first, free, 60);
	insert(myList, first, free, 70);
	insert(myList, first, free, 80);
	insert(myList, first, free, 90);
	insert(myList, first, free, 100);
	insert(myList, first, free, 110);

	print(myList, first);

	deleteFirst(myList, first, free);
	print(myList, first);
	
	insert(myList, first, free, 110);
	print(myList, first);

	makeEmpty(myList, first, free);

	print(myList, first);
	return 0;
}

void insert(int arr[][2], int &first, int &free, int val) {
	if (free == -1) {
		cout << "No more memory available" << endl;
	} else {

		if (first == -1) {
			//Insert first
			int newNode = free;
			arr[newNode][0] = val;
			free = arr[free][1];
			arr[newNode][1] = -1;
			first = newNode;
		} else {
			//Insert last
			int temp = first;
			while (arr[temp][1] != -1) {
				//loop till temp.next != nullptr and make temp point to it's next
				temp = arr[temp][1];
			}
			int newNode = free;
			arr[newNode][0] = val;
			arr[temp][1] = newNode;
			free = arr[free][1];
			arr[newNode][1] = -1;
		}

	}
}

void deleteFirst(int arr[][2], int &first, int &free) {
	int temp = first;
	first = arr[temp][1];
	arr[temp][1] = free;
	free = temp;
}

void makeEmpty(int arr[][2], int &first, int &free) {
	while (first != -1) {
		deleteFirst(arr, first, free);
	}
}

void print(int arr[][2], int first) {
	if (first == -1) {
		cout << "List is empty" << endl;
	} else {
		int temp = first;
		while (arr[temp][1] != -1) {
			cout << arr[temp][0] << ", ";
			temp = arr[temp][1];
		}
		cout << arr[temp][0] << endl;
	}
}