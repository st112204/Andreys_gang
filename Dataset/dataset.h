#pragma once

#include <string>
#include <fstream>
#include <iostream>

// Base class for the column class Col
// is needed to initialize the Dataset.col_array field.
// The type T of the class Col is unknown at compile time,
// Col<T>() cannot be a virtual method
class BaseCol
{
public:

	virtual ~BaseCol();
};

// Main column class
template <typename T>
class Col : public BaseCol
{
	std::string name; // Column name
	size_t size; // Column length (equal to the number of objects)
	T* data; // Array of data type T

public:

	Col(size_t size);
	~Col() override;
};


class Dataset
{
	size_t row_num; // Number of rows (objects)
	size_t col_num; // Number of columns (properties)
	BaseCol** col_array; // Data: array of pointers to Col columns

public:

	Dataset(size_t row_num, size_t col_num, std::string path);
	~Dataset();
};

#include "dataset_impl.h"