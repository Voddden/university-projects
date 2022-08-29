//Лабораторная 5, задача 3 Выполнена: Воднев Д. И.

/*
Вариант 5
1)Создать двумерный динамический массив вещественных чисел.

2)Определить, встречаются ли среди них элементы с нулевым значением.

3)Если встречаются такие элементы, то определить их индексы и общее количество.

4)Переставить элементы этого массива в обратном порядке и вывести на экран.
Использовать функции.
*/

using namespace std;
#include <iostream>
#include <iomanip>

long long inputInt();
long double inputFloat();
long double inputFloatArr(int i, int j, double A);

int main() {
	setlocale(LC_ALL, "Rus");

	cout << "---Введите размерность 2-мерного массива\n";
	cout << "Кол-во строк:\n";
	int n = inputInt();
	cout << "Кол-во столбцов:\n";
	int m = inputInt();

	double** A = new double* [n];
	for (int t = 0; t < n; ++t) {
		A[t] = new double[n];
	}

	cout << "---Введите значения элементов массива A\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << "A[" << i << "][" << j << "] = ";
			A[i][j] = inputFloatArr(i, j, A[i][j]);
		}
	}

	cout << "\nМатрица А:\n\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << setw(5) << A[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;

	// 2-3 start
	int d = 0; // общее количество нулевых элементов в массиве
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (A[i][j] == 0) {
				++d;
			}
		}
	}

	if (d == 0) {
		cout << "В массиве нет нулевых элементов\n";
	}
	else {
		cout << "Количество нулевых элементов в массиве: " << d << "\n\n";
		int x = d; // x - кол-во строк массива arr
		int y = 2;
		int** arr = new int* [x];
		for (int t = 0; t < d; ++t) {
			arr[t] = new int[y];
		}

		for (int i = 0; i < d; ++i) {
			for (int j = 0; j < y; ++j) {
				arr[i][j] = 0;
			}
		}

		int g = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (A[i][j] == 0) {
					arr[g][0] = i;
					arr[g][1] = j;
					++g;
				}
			}
		}
		/*
		cout << "\nМассив индексов нулевых элементов:\n\n";
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				cout << setw(5) << arr[i][j] << " ";
			}
			cout << "\n";
		}
		cout << endl;
		*/
		cout << "Индексы нулевых элементов: ";
		for (int i = 0; i < x; ++i) {
			cout << "(" << arr[i][0] << ";" << arr[i][1] << ")" << " ";
		}
		cout << "\n";
		// 2-3 end
	}

	return 0;
}

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

long double inputFloat() {
	long double value;
	cin >> value;
	while (cin.peek() == ' ') cin.ignore(1, ' ');
	while (cin.fail() || cin.peek() != '\n') {
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cin.clear();
		cin.ignore(3256, '\n');
		cin >> value;
		while (cin.peek() == ' ') cin.ignore(1, ' ');
	}
	return value;
}

long double inputFloatArr(int i, int j, double Aij) {
	cin >> Aij;
	while (cin.peek() == ' ') cin.ignore(1, ' ');
	while (cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(3256, '\n');
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cout << "A[" << i << "][" << j << "] = ";
		cin >> Aij;
		while (cin.peek() == ' ') cin.ignore(1, ' ');
	}
	return Aij;
}