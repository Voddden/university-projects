#include <stdlib.h>
#include <stdio.h>

void delete0(int* arr, int& size) {
	for (int k = 0; k < size; ++k) {
		if (arr[k] == 0) {
			for (int i = k; i < size - 1; ++i)
				arr[i] = arr[i + 1];
			arr = (int*)realloc(arr, --size * sizeof(int));
			--k;
		}
	}
}

void main()
{
	int size = 5;
	int* arr = (int*)calloc(size, sizeof(arr));
	//arr[0] = 0; arr[1] = 0; arr[2] = 5; arr[3] = 0; arr[4] = 0;
	arr[2] = 3; arr[4] = 9;

	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	// реаллоцирование массива:

	//for (int k = 0; k < size; ++k) {
	//	if (arr[k] == 0) {
	//		for (int i = k; i < size - 1; ++i)
	//			arr[i] = arr[i + 1];
	//		arr = (int*)realloc(arr, --size * sizeof(int));
	//		--k;
	//	}
	//}

	delete0(arr, size);

	//
	puts("\n");

	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}