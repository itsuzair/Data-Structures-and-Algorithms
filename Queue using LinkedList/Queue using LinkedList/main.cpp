#include <iostream>
#include "Queue.h"
#include "vld.h"
using namespace std;

int main() {
	/*Merge sort queues
	QUEUE<int> q1;
	q1.Enqueue(5);
	q1.Enqueue(15);
	q1.Enqueue(20);
	
	QUEUE<int> q2;
	q2.Enqueue(10);
	q2.Enqueue(18);
	q2.Enqueue(25);

	QUEUE<int> q3;

	while (!q1.isEmpty()) {
		q3.Enqueue(q1.Dequeue());
	}

	while (!q2.isEmpty()) {
		int top2 = q2.Dequeue();
		int top3 = q3.Dequeue();
		if (top2 > top3) {
			q3.Enqueue(top3);
			q3.Enqueue(top2);
		} else {
			q3.Enqueue(top3);
			q3.Enqueue(top2);
		}
	}

	if (q1.isEmpty()) {
		cout << "Q1 is empty" << endl;
	}

	if (q2.isEmpty()) {
		cout << "Q2 is empty" << endl;
	}

	while (!q3.isEmpty()) {
		cout << q3.Dequeue() << ", ";
	}
	*/

	/*Copy queue to another queue
	QUEUE<int> q1;
	q1.Enqueue(5);
	q1.Enqueue(15);
	q1.Enqueue(20);

	QUEUE<int> q2;
	QUEUE<int> q3;

	while (!q1.isEmpty()) {
		int top = q1.Dequeue();
		q2.Enqueue(top);
		q3.Enqueue(top);
	}
	
	while (!q3.isEmpty()) {
		q1.Enqueue(q3.Dequeue());
	}

	while (!q1.isEmpty()) {
		cout << q1.Dequeue() << ", ";
	}
	cout << endl;
	while (!q2.isEmpty()) {
		cout << q2.Dequeue() << ", ";
	}
	cout << endl;
	*/
	return 0;
}