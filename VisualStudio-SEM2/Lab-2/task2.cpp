#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

/*
2. Определить максимальное число, записанное в файле (если таких чисел
несколько, вывести все)
*/

void task2(FILE* fp, char* filename) {
	fp = fopen(filename, "r");

	int length = countNumbers(fp, filename);

	int* arr = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; ++i) {
		fscanf(fp, "%d", &arr[i]);
	}
	fclose(fp);

	int max = arr[0], numberOfMaximums = 1;
	for (int i = 1; i < length; ++i) {
		if (arr[i] > max) {
			max = arr[i];
			numberOfMaximums = 0;
		}
			
		if (arr[i] == max)
			++numberOfMaximums;
	}

	
	printf("task2 - максимальные числа в файле: ");
	for (int i = 0; i < numberOfMaximums; ++i) {
		printf("%d ", max);
	}
	
}