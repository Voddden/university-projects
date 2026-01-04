#include "../../ValidationLib/Validation.h"

/*
Заполнить одномерный массив чётными натуральными числами до 99. 
Удалить все числа, не принадлежащие отрезку [a;b].
*/

void output(int* arr, int size) {
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

bool ElemBelong(int a, int b, int num) {
	if (a <= num && num <= b)
		return true;
	else
		return false;
}

void deleteElementByIndex(int* arr, int& size, int i) {
	// сдвиг влево на 1:
	for (int u = i; u < size - 1; ++u)
		arr[u] = arr[u + 1];
	// перевыделение памяти:
	arr = (int*)realloc(arr, --size * sizeof(int));
}

void main()
{
	setlocale(LC_ALL, "ru");
	int a = inputInteger("a = ");
	int b = inputInteger("b = ");
	while (b < a)
		b = inputInteger("Error. b must be bigger than a\nb = ");

	int size = 49; // количество чётных натуральных чисел на отрезке [1;99]
	int* arr = (int*)malloc(sizeof(int) * size);

	int u = 2;
	for (int i = 0; i < size; ++i) {
		arr[i] = u;
		u += 2;
	}

	///printf("\nМассив:\n");
	//output(arr, size);

	int firstSize = size;
	for (int i = 0; i < firstSize; ++i)
		if (!ElemBelong(a, b, arr[i]))
			deleteElementByIndex(arr, size, i);
			//printf("%d ", arr[i]);

	//printf("\n\nМассив после удаления:\n");
	output(arr, size);
	puts("\n");
}