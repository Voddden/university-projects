#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

/*
3. Перевернуть в файле число, номер которого задан с клавиатуры.
*/

int number_digits(int n) {
	int count = 0;
	while (n) {
		n /= 10;
		count++;
	}
	return count;
}

int integrateDigitsToNumber(int* arr, int length) {
	int res = 0;
	int razryad = length - 1;
	for (int i = 0; i < length; ++i) {
		res += arr[i] * Pow(10, razryad);
		--razryad;
	}
	return res;
}

int flip(int num) {
	int res;
	int length = number_digits(num);
	int* arr = (int*)malloc(length * sizeof(int));

	int i = 0;
	while (num != 0) {
		res = num % 10;
		num = num / 10;
		arr[i] = res;
		++i;
	}

	res = integrateDigitsToNumber(arr, length);

	return res;
}

void task3(FILE* fp, char* filename) {
	fp = fopen(filename, "r");

	int length = countNumbers(fp, filename);
	int* arr = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; ++i) {
		fscanf(fp, "%d", &arr[i]);
	}

	fclose(fp);

	int n = inputNatural("Введите номер числа для переворота: ");

	arr[n - 1] = flip(arr[n - 1]);

	fp = fopen(filename, "w");
	for (int i = 0; i < length; ++i) {
		fprintf(fp, "%d ", arr[i]);
	}
	fclose(fp);

	printf("task3 - Переворот %d-го числа в файле: ", n);
	printFile(fp, filename);
}