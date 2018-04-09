#ifndef _ARRAYS_H
#define _ARRAYS_H
template <class TYPE>
class Array
{
public:
	Array();
	Array(int);
	Array(int, int *);
	Array(const Array &);
	~Array();
	void get();

private:
	TYPE *arr;
	TYPE size;
};
#endif
#include "Arrays.cpp"