#include <iostream>
#include "Stack.h"
#include "vld.h"
using namespace std;

int main() {

	/* Remove largest and return it
	STACK<int> s1;
	s1.push(5);
	s1.push(20);
	s1.push(10);
	s1.push(30);
	s1.push(15);

	STACK<int> s2;
	int largest = s1.getTop();
	while (!s1.isEmpty()) {
		int top = s1.getTop();
		if (top > largest) {
			largest = top;
		}
		if (largest != top) {
			s2.push(s1.pop());
		} else {
			s1.pop();
		}
	}
	while (!s2.isEmpty()) {
		s1.push(s2.pop());
	}

	cout << largest << endl;
	*/

	/* Palindrome check
	char *mystr = "hellolleh";
	STACK<char> s1;
	STACK<char> s2;
	STACK<char> s3;
	bool isPalindrome = true;
	for (int i = 0; i < strlen(mystr); i++) {
		s1.push(mystr[i]);
	}
	while (!s1.isEmpty()) {
		s2.push(s1.getTop());
		s3.push(s1.getTop());
		s1.pop();
	}
	while (!s2.isEmpty()) {
		s1.push(s2.pop());
	}
	while (!s1.isEmpty()) {
		if (s1.pop() != s3.pop()) {
			isPalindrome = false;
			break;
		}
	}
	if (isPalindrome) {
		cout << "Is" << endl;
	} else {
		cout << "Not" << endl;
	}
	*/
	return 0;
}