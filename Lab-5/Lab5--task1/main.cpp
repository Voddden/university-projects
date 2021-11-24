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

	cout << "Все массивы целочисленные\n";
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

	int* X = new int [n];
	int* Y = new int [m];

	//X
	cout << "Введите элементы массива X:\n";
	for (int i = 0; i < n; ++i) {
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

	//Y
	cout << "Введите элементы массива Y:\n";
	for (int i = 0; i < m; ++i) {
		cout << "Y[" << i << "] = ";
		cin >> Y[i];
		while (cin.fail() || cin.peek() != '\n' || Y[i] != (long long)Y[i]) {
			cin.clear();
			cin.ignore(99999, '\n');
			cout << "Введены некорректные данные, попробуйте ещё раз:\n";
			cout << "Y[" << i << "] = ";
			cin >> Y[i];
		}
	}

	//Z
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			Z[i][j] = X[i] * Y[j];
		}
	}

	cout << "\nМассив Z:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << Z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;

	// Алгоритм нахождения наиб. элемента
	int s = 0, I = 0, J = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Z[i][j] > s) {
				s = Z[i][j];
				I = i;
				J = j;
			}
		}
	}
	cout << "Наибольший элемент массива Z и его значение:\n Z[" << I << "][" << J << "] == " << s << endl;



	//int a = 10;
	//int b = 20;
	//std::cout << Sum(a, b);
	return 0;
}