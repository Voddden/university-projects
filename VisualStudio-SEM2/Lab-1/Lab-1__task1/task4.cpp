#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"
#include "Validation.h"

/*
4. Отсортировать только числа большие заданного по убыванию
*/

void printFile2(FILE* fp, char* filename) {
	fp = freopen(filename, "rb", fp);
	char c;
	while ((c = getc(fp)) != EOF)
	{
		printf("%c", c);
	}
	//printf("\n");
	fseek(fp, 0, SEEK_SET);
}

int numOfGreaterThanInput(int* arr, int size, int input) {
	int res = 0;
	for (int i = 0; i < size; ++i) {
		if (input < arr[i])
			++res;
	}
	return res;
}

void task4(FILE* fp, char* filename) {
	fp = fopen(filename, "rb");

	int length = countNumbers(fp);

	int* arr = (int*)malloc(length * sizeof(int)); // массив всех чисел
	for (int i = 0; i < length; ++i) {
		fscanf(fp, "%d", &arr[i]);
	}
	fclose(fp);

	printf("\n");
	int input = inputInteger("Введите заданное число: ");

	int length1 = numOfGreaterThanInput(arr, length, input);
	int* arr1 = (int*)malloc(length1 * sizeof(int));
	int k = 0;
	for (int i = 0; i < length; ++i) {
		if (input < arr[i]) {
			arr1[k] = arr[i];
			++k;
		}
	}

	for (int a = 0; a < length1 - 1; ++a)
		for (int b = 0; b < length1 - 1 - a; ++b) {
			if (arr1[b] < arr1[b + 1])
				std::swap(arr1[b], arr1[b + 1]);
		}


	int u = 0;
	for (int i = 0; i < length; ++i) {
		if (input < arr[i]) {
			arr[i] = arr1[u];
			++u;
		}
	}

	fp = fopen(filename, "wb");
	for (int i = 0; i < length; ++i) {
		fprintf(fp, "%d ", arr[i]);
	}
	fclose(fp);

	printf("task4 - сортировка по убыванию чисел, больших %d: ", input);
	printFile2(fp, filename);
}