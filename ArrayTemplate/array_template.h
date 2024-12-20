#ifndef ARRAY_TEMPLATE_H
#define ARRAY_TEMPLATE_H

#include <iostream>
#define N 10

template <typename T>
class Array
{
	int size = 0;
	T* array = nullptr;

public:

	Array();
	Array(T* b);
	~Array();
	void show();
	T minimum(Array<T>& m);
};

#include "array_template.cpp"

#endif