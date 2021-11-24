//Лабораторная 5, задача 1 Выполнена: Воднев Д. И.

/*
Cоставить программу для нахождения наибольшего элемента двумерного
динамического массива-матрицы Z.
Использовать функции.
*/

using namespace std;
#include <iostream>
#include "..\StaticLib\Header.h";

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	const int n = 3, m = 3; // размерность массива Z
	int** Z = new int* [n];
	for (int t = 0; t < n; ++t) {
		Z[t] = new int[n];
	}

	const int x = 5; // размерность массива X 
	int** X = new int* [x];

	const int y = 5; // размерность массива Y
	int** Y = new int* [y];



	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			Z[i][j] = X[i] * Y[j];
		}
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << Z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;



	//int a = 10;
	//int b = 20;
	//std::cout << Sum(a, b);
	return 0;
}