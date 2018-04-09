#include <iostream>
#include "Stack.h"
using namespace std;

void getInput(char &, char[]);
void processInput(char, char[]);
bool isBalanced(char[]);
void infixToPostfix(char[]);
int evalPostfix(char *);

int main() {
	char expression[50];
	char option;
	getInput(option, expression);
	processInput(option, expression);
	cout << endl << endl;
	return 0;
}

//Menu display function
void getInput(char &option, char expression[]) {
	do {
		cout << "Please select what operation would you like to perform : " << endl << endl;
		cout << "1. Check for balanced parantheses. [B/B]" << endl;
		cout << "2. Convert infix expression to postfix expression [C/c]" << endl;
		cout << "3. Evaluate a postfix expression [E/e]" << endl << endl;
		cout << "Enter option : ";
		cin >> option;
		if (option != 'B' && option != 'b' && option != 'C' && option != 'c' && option != 'E' && option != 'e') {
			cout << "Invalid option entered, Please enter again." << endl << endl;
		}
	} while (option != 'B' && option != 'b' && option != 'C' && option != 'c' && option != 'E' && option != 'e');

	cout << "Enter expression : ";
	cin.ignore();
	cin.getline(expression, 50);
	cout << endl;
}

//Input handler function
void processInput(char option, char expression[]) {
	switch (option) {
	case 'B': case 'b':
		if (isBalanced(expression)) {
			cout << "Expression is balanced";
		} else {
			cout << "Expression is unbalanced";
		}
		break;
	case 'C': case 'c':
		infixToPostfix(expression);
		break;
	case 'E': case 'e':
		int res = evalPostfix(expression);
		cout << "Answer to postfix expression is : " << res;
		break;
	}
}

// Code for Parantheses balance check
bool isPair(char a, char b) {
	if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')) {
		return true;
	}
	return false;
}

bool isBalanced(char expression[]) {
	STACK<char> myStack(sizeof(expression));
	for (int i = 0; i < sizeof(expression); i++) {
		if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
			if (!myStack.isFull()) {
				myStack.push(expression[i]);
			}
		} else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
			if (myStack.isEmpty() || !isPair(myStack.getTop(), expression[i])) {
				return false;
			} else {
				if (!myStack.isEmpty()) {
					myStack.pop();
				}
			}
		}
	}
	return myStack.isEmpty();
}

// Code for Infix to Postfix conversion
bool isValidOperand(char operand) {
	char valids[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
	for (int i = 0; i < strlen(valids); i++) {
		if (operand == valids[i]) {
			return true;
		}
	}
	return false;
}

bool isOperator(char character) {
	if (character == '+' || character == '-' || character == '*' || character == '/') {
		return true;
	}
	return false;
}

bool hasPrecendence(char character, char top) {
	bool precedence = false;
	if (character == '*' || character == '/') {
		if (top == '+' || top == '-') {
			precedence = true;
		}
	}
	return precedence;
}

void infixToPostfix(char expression[]) {
	STACK<char> myStack(sizeof(expression));
	STACK<char> reverse(sizeof(expression));
	bool isValid = true;

	for (int i = 0; i < strlen(expression); i++) {
		if (isOperator(expression[i]) && isOperator(expression[i+1])) {
			isValid = false;
			break;
		}
		if (isValidOperand(expression[i]) && isValidOperand(expression[i+1])) {
			isValid = false;
			break;
		}
		char character = expression[i];
		if (isOperator(character)) {
			if (myStack.isEmpty()) {
				myStack.push(character);
			} else {
				while (!myStack.isEmpty() && !hasPrecendence(character, myStack.getTop())) {
					reverse.push(myStack.pop());
				}
				if (!myStack.isFull()) {
					myStack.push(character);
				}
			}
		} else {
			reverse.push(character);
		}
	}

	if (isValid == true) {
		while (!myStack.isEmpty()) {
			reverse.push(myStack.pop());
		}
		while (!reverse.isEmpty()) {
			myStack.push(reverse.pop());
		}
		while (!myStack.isEmpty()) {
			cout << myStack.pop();
		}
	} else {
		cout << "Invalid expression entered";
	}
	cout << endl << endl;
}

//Code for evaluating a Postfix expression
int operate(int a, int b, char op) {
	switch (op) {
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	default :
		return NULL;
		break;
	}
}

int evalPostfix(char *expression) {
	STACK<int> myStack(sizeof(expression));
	for (int i = 0; i < strlen(expression); i++) {
		char character = expression[i];
		if (isOperator(character)) {
			int a, b;
			if (!myStack.isEmpty()) {
				a = myStack.pop();
			}
			if (!myStack.isEmpty()) {
				b = myStack.pop();
			}
			int res = operate(b, a, character);
			if (!myStack.isFull()) {
				myStack.push(operate(b, a, character));
			}
		} else {
			if (!myStack.isFull()) {
				myStack.push(atoi(&character));
			}
		}
	}
	return myStack.pop();
}