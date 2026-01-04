#include "../../ValidationLib/Validation.h"

int** allocation(int m, int n) { 
	int** mas;
	mas = (int**)calloc(m, sizeof(int*));
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

////  1-ая часть
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapRows(int* a, int* b, int n) {
	int* temp = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i) {
		temp[i] = a[i];
		a[i] = b[i];
		b[i] = temp[i];
	}
	free(temp);
}

int numOfEqualElements(int* arr, int size) {
	int result = 0;

	for (int u = 0; u < size; ++u) {
		int result_temp = 0, current = arr[u];
		for (int i = 0; i < size; ++i) {
			if (current == arr[i])
				++result_temp;
		}
		if (result_temp == 1)
			--result_temp; // -1, т.к. элемент 1 раз сравнивался сам с собой
		if (result_temp > result)
			result = result_temp;
	}

	return result;
}

void arrangeArr(int** arr, int m, int n) {
	int* EqualElements = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; ++i) {
		EqualElements[i] = numOfEqualElements(arr[i], n);
	}
	// причудливая модифицированная пузырьковая сортировка по убыванию
	for (int i = 0; i < m - 1; ++i) {
		for (int k = 0; k < m - 1 - i; ++k) {
			if (EqualElements[k] < EqualElements[k + 1]) {
				swap(EqualElements[k], EqualElements[k + 1]);
				swapRows(arr[k], arr[k + 1], n);
			}
		}
	}
	free(EqualElements);
}
//

////  2-ая часть

int** transpose(int** arr, int x, int y) {
	int** arr_T = allocation(y, x);
	for (int i = 0; i < x; i++) // транспонирование матрицы
		for (int j = 0; j < y; j++)
			arr_T[j][i] = arr[i][j];
	return arr_T;
}

bool noNegativeElements(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] < 0)
			return false;
	}
	return true;
}

int findIndex(int** arr, int m, int n) {	
	for (int i = 0; i < n; ++i) {
		if (noNegativeElements(arr[i], m)) {
			return i;
		}
	}

	return -1; // значит во всех столбцах матрицы есть как минимум одно отрицательное число
}
//

/* В-12
1) Упорядочить строки целочисленной прямоугольной матрицы
по возрастанию количества одинаковых элементов в каждой строке.
2) Найти номер первого из столбцов, не содержащих ни одного отрицательного элемента.
*/

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	printf("ЛР 4, таска 1\n\n");
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
	// часть 1
	arrangeArr(arr, m, n);
	printf("\n1) Упорядоченная матрица:\n\n");
	outputArr(arr, m, n);
	// часть 2
	int index = findIndex(transpose(arr, m, n), m, n); // передаём в функцию транпспонированную матрицу
	if (index >= 0)
		printf("\n2) Индекс столбца = %d\n", index);
	else
		printf("\n2) Таких столбцов нет\n");

	Free(arr, m);
}