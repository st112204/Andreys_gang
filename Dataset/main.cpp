#include "dataset.h"

int main()
{
	std::string file_path = "dataset.csv";
	
	Dataset D;

	try
	{
		D = Dataset(5, 3, file_path, ';');
		// By default:
		// D.col_array = (tmp).col_array
		// D.col_array -> [ MEMORY ] <- (tmp).col_array
	}
		// delete (tmp):
		// delete col_array[i], delete col_array
		// D.col_array -> [  X  ]

	// solutions:
	// 1. Copy constructor [v]
	// 2. Move constructor [ ]
	// 3. Smart pointers   [ ]

	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	D.printInfo();

	return 0;
}