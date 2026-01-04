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
			printf("%5d ", arr[i][j]);
		}
		printf("\n");
	}
}
// задание:

bool rowDontHasNull(int* arr, int size) {
	for (int i = 0; i < size; ++i) 
		if (arr[i] == 0)
			return false;
	return true;
}

bool allStringsHaveNull(int** arr, int m, int n) {
	for (int i = 0; i < m; ++i)
		if (rowDontHasNull(arr[i], n))
			return false;
	return true;
}

void nullAllNegative(int** arr, int m, int n) {
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (arr[i][j] < 0)
				arr[i][j] = 0;
}

/* B-12
Проверить, все ли строки матрицы содержат хотя бы один нулевой элемент. 
Если нет, то заменить значения всех отрицательных элементов матрицы на нулевые.
*/

void main() 
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	printf("ЛР 4, таска 2\n\n");
	printf("Матрица m x n\n");

	int m = inputNatural("m = ");
	int n = inputNatural("n = ");

	int** arr = allocation(m, n);

	int choice = inputNatural("---Заполнить матрицу с клавиатуры - 1\tслучайными значениями - 2\n");
	while (choice != 1 && choice != 2) {
		choice = inputNatural("Error\n---Заполнить матрицу с клавиатуры - 1\tслучайными значениями - 2\n");
	}

	switch (choice) {
	case 1:
		inputArr(arr, m, n); break;
	case 2:
		randArr(arr, m, n);
	}

	printf("\nМатрица:\n\n");
	outputArr(arr, m, n);
	// работа с массивом:
	if (allStringsHaveNull(arr, m, n)) {
		printf("\nДействия не требуются\n");
	}
	else {
		nullAllNegative(arr, m, n);
		printf("\nОбработанная матрица:\n\n");
		outputArr(arr, m, n);
	}

	Free(arr, m);
}