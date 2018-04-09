#include "pQueue.h"
#include <iostream>
using namespace std;

int main() {
	pQueue<int> myQ(10);
	myQ.Enqueue(10);
	myQ.Enqueue(5);
	myQ.Enqueue(8);
	myQ.Enqueue(7);
	myQ.Enqueue(12);
	myQ.Enqueue(15);
	myQ.Enqueue(13);
	myQ.Enqueue(11);
	myQ.Enqueue(12);
	while (!myQ.IsEmpty()) {
		cout << myQ.Dequeue() << ", ";
	}
	cout << endl;
	return 0;
}