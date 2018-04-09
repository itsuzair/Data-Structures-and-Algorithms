#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	QUEUE<int> q1(5);
	int i = 0;
	q1.Enqueue(0);
	q1.Enqueue(1);
	q1.Enqueue(2);
	cout << q1.Dequeue() << "YA" << endl;
	q1.Enqueue(3);
	q1.Enqueue(4);
	q1.Enqueue(5);
	q1.Enqueue(6);
	while (!q1.IsEmpty()) {
		cout << q1.Dequeue() << endl;
	}
	return 0;
}