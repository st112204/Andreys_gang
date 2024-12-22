#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <typeinfo>

// Base class for the Column class
// is needed to initialize the Dataset.col_array field.
// The type T of the class Col is unknown at compile time,
// Col<T>() cannot be virtual
class BaseCol
{
protected:

	std::string type;

public:
		
	BaseCol();
	virtual ~BaseCol();
	std::string getType();
};

// Column class
template <typename T>
class Col : public BaseCol
{
	std::string name; // Column name
	size_t size; // Column length (equal to the number of objects)
	using BaseCol::type; // Column type

	T* data; // Array of data type T

public:

	Col() = delete;
	Col(size_t size, std::string type);
	~Col() override;

	using BaseCol::getType;
};


class Dataset
{
	size_t row_num; // Number of rows (objects)
	size_t col_num; // Number of columns (properties)
	BaseCol** col_array; // Data: array of pointers to Col columns

	std::string file_path; // Path to file
	std::string file_ext; // .txt or .cvs

	char separator;

	std::string get_ext_by_path(std::string& file_path);
	std::string get_type_by_col(std::ifstream& file, size_t col);


public:

	Dataset();

	Dataset(size_t row_num, size_t col_num, std::string file_path, char separator);

	Dataset& operator=(const Dataset& Other);

	~Dataset();

	size_t getHeight();
	size_t getWidth();
	std::string getPath();
	std::string getExt();

	void printInfo();

};


namespace custom
{
	std::string getline(
		std::string str,
		std::string val,
		size_t pos,
		char sep);
}


#include "dataset_impl.h"