#include <stdio.h>
#include <stdlib.h>

void deleteElementByIndex(int* arr, int& size, int i) {
	// сдвиг влево на 1:
	for (int u = i; u < size - 1; ++u)
		arr[u] = arr[u + 1];
	// перевыделение памяти:
	arr = (int*)realloc(arr, --size * sizeof(int));
}

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

void Delete0(int arr[], int* ptrSize) {
	int length = *ptrSize;
	for (int k = 0; k < length; ++k) {
		if (arr[k] == 0) {
			for (int i = k; i < length - 1; ++i)
				arr[i] = arr[i + 1];
			arr = (int*)realloc(arr, --length * sizeof(int));
			--k;
		}
	}
	*ptrSize = length;
}

void main() 
{
	// инициализация массива:
	int size = 5;
	int* arr = (int*)calloc(size, sizeof(int));
	arr[0] = 0; arr[1] = 3; arr[2] = 0; arr[3] = 0; arr[4] = 9;
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	puts("\n");
	////// обработка массива:
	
	//delete0(arr, size);
	Delete0(arr, &size);
	
	//for (int k = 0; k < size; ++k) {
	//	if (arr[k] == 0) {
	//		for (int i = k; i < size - 1; ++i)
	//			arr[i] = arr[i + 1];
	//		arr = (int*)realloc(arr, --size * sizeof(int));
	//		--k;
	//	}
	//}
	
	// вывод массива:
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	puts("\n");
	//deleteElementByIndex(arr, size, 0);
	//for (int i = 0; i < size; ++i)
	//	printf("%d ", arr[i]);
}