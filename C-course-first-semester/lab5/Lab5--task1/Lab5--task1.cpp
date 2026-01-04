//Лабораторная 5, задача 1 Выполнена: 

/*
Вариант 5:
Cоставить программу для нахождения наибольшего элемента двумерного
динамического массива-матрицы Z, где элементы массива Z вычисляются по формуле:
Z[i][j] = X[i] * Y[j]
Использовать функции.
*/

using namespace std;
#include <iostream>
#include <iomanip>
#include "..\StaticLib\Header.h";

long long inputInt() {
	long double value;
	cin >> value;
	while (cin.peek() == ' ') cin.ignore(1, ' ');
	while (cin.fail() || cin.peek() != '\n' || value <= 0 || value != (long long)value) {
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cin.clear();
		cin.ignore(3256, '\n');
		cin >> value;
		while (cin.peek() == ' ') cin.ignore(1, ' ');
	}
	return value;
}

long long inputArrX(int i, int Xi) {
	cout << "X[" << i << "] = ";
	cin >> Xi;
	while (cin.fail() || cin.peek() != '\n' || Xi != (long long)Xi) {
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cout << "X[" << i << "] = ";
		cin >> Xi;
	}
	return Xi;
}

long long inputArrY(int i, int Yi) {
	cout << "Y[" << i << "] = ";
	cin >> Yi;
	while (cin.fail() || cin.peek() != '\n' || Yi != (long long)Yi) {
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cout << "Y[" << i << "] = ";
		cin >> Yi;
	}
	return Yi;
}

int main() {
	setlocale(LC_ALL, "Rus");

	cout << "Массив целочисленный\n";
	cout << "---Введите размерность 2-мерного массива Z:\n";
	cout << "Кол-во строк:\n";
	int n = inputInt();
	cout << "Кол-во столбцов:\n";
	int m = inputInt();
	
	int** Z = new int* [n];
	for (int t = 0; t < n; ++t) {
		Z[t] = new int[n];
	}

	int* X = new int [n];
	int* Y = new int [m];

	//X
	cout << "---Введите элементы массива X:\n";
	for (int i = 0; i < n; ++i) {
		X[i] = inputArrX(i, X[i]);
	}

	//Y
	cout << "Введите элементы массива Y:\n";
	for (int i = 0; i < m; ++i) {
		Y[i] = inputArrY(i, Y[i]);
	}

	//Z
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			//Z[i][j] = X[i] * Y[j];
			Z[i][j] = func(X[i], Y[j]);
		}
	}

	cout << "\nМассив Z:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << setw(5) << Z[i][j] << " ";
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
	return 0;
}