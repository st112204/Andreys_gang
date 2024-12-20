#include "dataset.h"

int main()
{
	Dataset myDataset(4, 3, "dataset.txt");
	// Dataset myDataset(number of objects, number of properties, path to file);


	std::cout << myDataset.path;

	return 0;
}