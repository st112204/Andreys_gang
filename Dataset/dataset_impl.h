#pragma once

#include "dataset.h"

// BaseCol:

BaseCol::~BaseCol()
{}


// Col:

template <typename T>
Col<T>::Col(size_t size) : name(""), size(size), data(new T[size]) {}

template <typename T>
Col<T>::~Col() { delete[] data; }


// Dataset:

// Dataset (number of objects, number of properties, path to file)
Dataset::Dataset(size_t row_num, size_t col_num, std::string path) :
	row_num(row_num),
	col_num(col_num),
	col_array(new BaseCol* [col_num]), // Initialize col_array with an array of BaseCol pointers
	path(path)
{

	std::ifstream file(path);

	if (!file.is_open())
	{

		std::cerr << "Error opening file!" << std::endl;
		return;
	}
	else
	{
		std::cout << "The file was opened successfully" << std::endl;
	}

	std::string str;
	std::getline(file, str); // Get a row of column names (1st row)
	std::getline(file, str); // Get a row of column types (2nd row)
	std::cout << "Column types row: " << str << std::endl;

	char* col_type = new char[col_num]; // Array of column type names
	size_t types_count = 0; // Received characters counter

	for (char c : str)
	{
		if (c != ' ' && types_count < col_num)
		{
			col_type[types_count] = c;
			++types_count;
		}
	}

	// What if the user filled in the row of column types incorrectly
	if (types_count != col_num)
	{
		std::cerr << "Error: incorrect number of column types" << std::endl;
		delete[] col_array; // ?
		delete[] col_type;
		file.close();
		return;
	}

	// Redirect the pointer col_array[i]
	// depending on the data type symbol col_type[i].
	// BaseCol* = Col<T>*
	for (size_t i = 0; i < col_num; ++i)
	{
		switch (col_type[i])
		{
		case 'i': // Integer type
			col_array[i] = new Col<int>(row_num);
			break;
		case 'd': // Double type
			col_array[i] = new Col<double>(row_num);
			break;
		case 's': // String type
			col_array[i] = new Col<std::string>(row_num);
			break;
		default:
			std::cerr << "Unknown column type: " << col_type[i] << std::endl;
			col_array[i] = nullptr;
			break;
		}
	}

	delete[] col_type;
	file.close();
}

Dataset::~Dataset()
{
	for (size_t i = 0; i < col_num; ++i)
	{
		delete col_array[i];
	}
	delete[] col_array;
}