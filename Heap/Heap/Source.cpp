#include <iostream>
#include "heap.h"
using namespace std;

int main() {
	
	
	int arr[5] = { 4,2,5,6,1 };
	HeapType<int> heap(5);
	for (int i = 0; i < 5; i++) {
		heap.insert(arr[i]);
	}
	heap.print();
	cout << endl << endl;
	for (int i = 4; i >=0; i--) {
		arr[i] = heap.del();
	}
	for (int i = 0; i <= 4; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl << endl;

	return 0;
}