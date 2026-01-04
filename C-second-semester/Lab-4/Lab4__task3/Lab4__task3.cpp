#include "../../ValidationLib/Validation.h"

int** allocation(int m, int n)
{
	int** mas;
	mas = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		mas[i] = (int*)malloc(n * sizeof(int)); //*(mas + i)
	}
	return mas;
}

void Free(int** arr, int m) {
	for (int i = 0; i < m; ++i)
		free(arr[i]);
	free(arr);
}

void inputArr(int** arr, int m, int n) {
	char iHateC[] = "arr[.][.] = ";
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			iHateC[4] = i + 48;
			iHateC[7] = j + 48;
			arr[i][j] = inputInteger(iHateC);
		}
	}
}

void randArr(int** arr, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = rand() % 10 - rand() % 10;
		}
	}
}

void outputArr(int** arr, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			
			if (i + 1 > n / 2 && j + 1 > n / 2)
				printf("\x1B[31m%4d \033[0m", arr[i][j]);
			else
				printf("%4d ", arr[i][j]);
		}
		printf("\n\n");
	}
}

// задание:

int Sum(int** arr, int size) {
	int res = 0;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			if (i + 1 > size / 2 && j + 1 > size / 2) // условие входа рассматриваемого элемента в указанную область
				res += arr[i][j];
	return res;
}

/* В-12
В квадратной матрице размером NxN найти сумму элементов в 4-ой области
*/

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	printf("ЛР 4, таска 3\n\n");
	printf("Квадрат N x N\n");

	int n = inputNatural("N = ");

	int** arr = allocation(n, n);

	int choice = inputNatural("---Заполнить квадрат с клавиатуры - 1\tслучайными значениями - 2\n");
	while (choice != 1 && choice != 2) {
		choice = inputNatural("Error\n---Заполнить квадрат с клавиатуры - 1\tслучайными значениями - 2\n");
	}

	switch (choice) {
	case 1:
		inputArr(arr, n, n); break;
	case 2:
		randArr(arr, n, n);
	}

	printf("\nКвадрат:\n\n");
	outputArr(arr, n, n);
	// работа с квадратом:
	printf("\nСумма = %d\n", Sum(arr, n));

	Free(arr, n);
}