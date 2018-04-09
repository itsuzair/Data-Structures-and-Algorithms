#include <iostream>

template <class TYPE>
Array<TYPE>::Array() {
	size = 0;
	arr = NULL;
}

template <class TYPE>
Array<TYPE>::Array(int s) {
	size = s;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = TYPE();
	}
}

template <class TYPE>
Array<TYPE>::Array(int s, int *a) {
	size = s;
	arr = new int[size];
	if (a) {
		for (int i = 0; i < size; i++) {
			arr[i] = a[i];
		}
	}
}

template <class TYPE>
Array<TYPE>::Array(const Array &a) {
	size = a.size;
	arr = new int[size];
	if (a) {
		for (int i = 0; i < size; i++) {
			arr[i] = a[i];
		}
	}
}

template <class TYPE>
Array<TYPE>::~Array() {
	if (arr) {
		delete[] arr;
	}
}

template <class TYPE>
void Array<TYPE>::get() {
	if (arr) {
		for (int i = 0; i < size - 1; i++) {
			cout << arr[i] << ",";
		}
		cout << arr[size - 1];
	}
}