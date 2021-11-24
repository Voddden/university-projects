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

	// 1
	cout << "Введите размерность 2-мерного массива Z:\n";
	int n, m;
	cin >> n >> m;
	while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0 || m != (long long)m || m <= 0) {
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cin >> n >> m;
	}
	int** Z = new int* [n];
	for (int t = 0; t < n; ++t) {
		Z[t] = new int[n];
	}

	
	// 2
	cout << "Введите размерность 1-мерного массива X:\n";
	int x;
	cin >> x;
	while (cin.fail() || cin.peek() != '\n' || x != (long long)x || x <= 0) {
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cin >> x;
	}
	int* X = new int [x];

	// 3
	cout << "Введите размерность 1-мерного массива Y:\n";
	int y;
	cin >> y;
	while (cin.fail() || cin.peek() != '\n' || y != (long long)y || y <= 0) {
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cin >> y;
	}
	int* Y = new int [y];

	//X
	for (int i = 0; i < x; ++i) {
		cout << "X[" << i << "] = ";
		cin >> X[i];
		while (cin.fail() || cin.peek() != '\n' || X[i] != (long long)X[i]) {
			cin.clear();
			cin.ignore(99999, '\n');
			cout << "Введены некорректные данные, попробуйте ещё раз:\n";
			cout << "X[" << i << "] = ";
			cin >> X[i];
		}
	}

	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < n; ++j) {
	//		Z[i][j] = X[i] * Y[j];
	//	}
	//}
	//cout << endl;
	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < n; ++j) {
	//		cout << Z[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << endl;



	//int a = 10;
	//int b = 20;
	//std::cout << Sum(a, b);
	return 0;
}