#pragma once

#include "dataset.h"

// BaseCol:

BaseCol::BaseCol() { type = "Undefined"; }

BaseCol::~BaseCol() {}

std::string BaseCol::getType() { return type; }

// Col:

template <typename T>
Col<T>::Col(size_t size, std::string type): name(""), size(size), data(new T[size])
{
	this->type = type;
}

template <typename T> 
Col<T>::~Col() { delete[] data; }

//template <typename T>
//std::string Col<T>::getType() { return type; }


// Dataset:

Dataset::Dataset()
{
	row_num = 0;
	col_num = 0;
	col_array = nullptr;

	file_path = "";
	file_ext = "";

	separator = ' ';
}

Dataset::Dataset(size_t row_num, size_t col_num, std::string file_path, char separator)
{
	// !
	std::ifstream file(file_path, std::ios::in);

	if (!file.is_open())
		throw std::runtime_error("Error: can't read the file \n");
	else
		std::cout << "The file was opened \n" << std::endl;

	this->row_num = row_num;
	this->col_num = col_num;
	this->file_path = file_path;
	this->file_ext = get_ext_by_path(file_path);
	this->separator = separator;

	this->col_array = new BaseCol*[col_num];

	for (size_t i = 0; i < col_num; ++i)
	{
		std::string col_type = get_type_by_col(file, i);

		if (col_type == "Float")
			col_array[i] = new Col<float>(row_num, "Float");
		else if (col_type == "String")
			col_array[i] = new Col<std::string>(row_num, "String");
		else
			throw std::runtime_error("Error: unknown column type");

		std::cout <<
			"Column " << i <<
			" type: " << col_type <<
			" created \n" << std::endl;
	}

	file.close();
}

// const arg => Copy  
// operator => Dataset is already exists
Dataset& Dataset::operator=(const Dataset& Other)
{
	if (this == &Other)
		return *this;

	if (col_array != nullptr)
	{
		for (size_t i = 0; i < col_num; ++i)
		{
			delete col_array[i];
		}

		delete col_array;
	}

	row_num = Other.row_num;
	col_num = Other.col_num;
	file_path = Other.file_path;
	file_ext = Other.file_ext;
	separator = Other.separator;

	col_array = new BaseCol * [col_num];

	for (size_t i = 0; i < col_num; ++i)
	{
		std::string other_col_type = Other.col_array[i]->getType();

		if (other_col_type == "Float")
			col_array[i] = new Col<float>(row_num, "Float");
		else if (other_col_type == "String")
			col_array[i] = new Col<std::string>(row_num, "String");
		else
			throw std::runtime_error("Error: unknown column type");

		std::cout << 
			"Column " << i << 
			" type: " << other_col_type << 
			" copied \n" << std::endl;
	}

}

// Move
// Constructor

Dataset::~Dataset()
{
	// fix
	for (size_t i = 0; i < col_num; ++i)
	{
		delete col_array[i];
	}
	delete[] col_array;
}


// Dataset public:

void Dataset::printInfo()
{
	std::cout <<
		"Rows:      " << row_num   << "\n" <<
		"Columns:   " << col_num   << "\n" <<
		"Path:      " << file_path << "\n" <<
		"Extencion: " << file_ext  << std::endl;
}

size_t Dataset::getHeight() { return row_num; }
size_t Dataset::getWidth() { return col_num; }
std::string Dataset::getPath() { return file_path; }
std::string Dataset::getExt() { return file_ext; }


// Dataset private:

std::string Dataset::get_ext_by_path(std::string& file_path)
{
	std::string file_ext = "";
	size_t start_position = file_path.size();

	for (size_t pos = file_path.size() - 1; pos >= 0; --pos)
	{
		char c = file_path[pos];

		if (c == '.')
			return file_path.substr(pos + 1, file_path.size() - pos);
	}

	throw
		std::runtime_error("Error: incorrect file extension");
}

std::string Dataset::get_type_by_col(std::ifstream& file, size_t col_index)
{
	std::string str = "STR";
	std::string val = "VAL";

	file.seekg(0, std::ios::beg);
	std::getline(file, str); // nekrasivo

	for (size_t i = 1; i < row_num; ++i)
	{
		if (!std::getline(file, str))
			throw std::runtime_error("Error: row position > rows \n");

		val = custom::getline(str, val, col_index, separator);

		for (size_t j = 0; j < val.size(); ++j)
		{
			char c = val[j];

			// c is not digit, point or minus
			if ((c < 48 || c > 57) && c != '.' && c != '-')
				return "String";

			if (c == '.')
			{
				if (j == 0 || j == val.size() - 1)
					return "String";
				if (val[j - 1] == '.' || val[j + 1] == '-')
					return "String";
			}

			if (c == '-')
			{
				if (j != 0)
					return "String";
				if (val[j + 1] == '-' || val[j + 1] == '.')
					return "String";
			}
		}
	}

	return "Float";
}


// Functions

// string stream -> (position, separator) -> subsrting
std::string custom::getline(std::string str, std::string val, size_t pos, char sep)
{

	std::istringstream stream(str);

	// !
	for (size_t i = 0; i < pos + 1; ++i)
		if (!std::getline(stream, val, sep))
			throw std::runtime_error("Error: column position > columns \n");

	return val;
}