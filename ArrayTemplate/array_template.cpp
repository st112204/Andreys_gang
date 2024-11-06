#ifndef ARRAY_TEMPLATE_CPP
#define ARRAY_TEMPLATE_CPP

#include "array_template.h"

template <typename T>
Array<T>::Array()
{}

template <typename T>
Array<T>::Array(T* b)
{
	size = N;
	array = new T[size];
	for (int i = 0; i < size; ++i)
	{
		array[i] = b[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
void Array<T>::show()
{
	for (int i = 0; i < size; ++i)
		std::cout << array[i] << " ";
	std::cout << "\n\n";

	return;
}

template <typename T>
T Array<T>::minimum(Array<T>& m)
{
	T min = *m.array;
	for (int i = 0; i < m.size; ++i)
	{
		if (m.array[i] < min)
			min = m.array[i];
	}

	return min;
}

#endif