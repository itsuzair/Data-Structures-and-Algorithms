#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T [], int);
template <typename T>
void bubbleSort(T [], int);
template<typename T>
void insertionSort(T [], int);
template<typename T>
void printArray(T[], int);

int main() {
	int myArr[10] = { 8, 5, 3, 2, 2, 6, 7, 8, 9, 1 };
	insertionSort(myArr, 10);
	printArray(myArr, 10);
	return 0;
}

template <typename T>
void selectionSort(T list[], int size) {
	int temp = 0;
	int min_index = 0;
	for (int i = 0; i < size - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (list[min_index] > list[j]) {
				min_index = j;
			}
		}
		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;
	}
}

template <typename T>
void bubbleSort(T list[], int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

template <typename T>
void insertionSort(T list[], int size) {
	int  temp;
	for (int i = 0; i < size; i++) {
		for (int j = i; j > 0; j--) {
			if (list[j] < list[j - 1]) {
				temp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = temp;
			}
		}
	}
}

template <typename T>
void printArray(T list[], int size) {
	for (int i = 0; i < size-1; i++) {
		cout << list[i] << ", ";
	}
	cout << list[size - 1] << endl;
}