#include "DynamicLib.h"
#include <iostream>
int input() {
	int x;
	while (true)
	{
		std::cin >> x;
		if (!std::cin.fail())
			return x;
		std::cin.clear();
		std::cin.ignore(320000, '\n');
	}
}

int multiplyOfElements(int* array, int size, int endSize)
{
	if (size == endSize)
		return array[size] * array[size] + cos(array[size]);

	return array[size] * array[size] + cos(array[size]) * multiplyOfElements(array, size - 1, endSize);
}

