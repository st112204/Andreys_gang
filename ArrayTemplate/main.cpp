#include <time.h>
#include "array_template.h"

int main()
{
	int m[N];

	srand(time(nullptr));

	for (int i = 0; i < N; ++i)
		m[i] = std::rand() % 100;

	Array<int> mm(m);

	mm.show();

	std::cout << mm.minimum(mm);

	return 0;
}