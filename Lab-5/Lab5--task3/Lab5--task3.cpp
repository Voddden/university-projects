//Лабораторная 5, задача 3 Выполнена: Воднев Д. И.

/*
Дан двумерный динамический массив целых чисел А размерностью n x k .
Размерность массива (n = 5, k = 6) ввести с клавиатуры. Значения элементов массива
ввести с клавиатуры.

Создать динамический массив из элементов, расположенных на
главной диагонали матрицы и имеющих четное значение.

Вычислить произведение
элементов динамического массива.

Созданный массив и результат произведения вывести на экран.
Использовать функции.
*/

using namespace std;
#include <iostream>
#include <iomanip>

long long inputInt();

long long inputArr(int i, int j, int Aij);

int main() {
	setlocale(LC_ALL, "Rus");

	cout << "---Введите размерность 2-мерного массива\n"; // по условию надо ввести 5 и 6
	cout << "Кол-во строк:\n";
	int n = inputInt();
	cout << "Кол-во столбцов:\n";
	int k = inputInt();

	int** A = new int* [n];
	for (int t = 0; t < n; ++t) {
		A[t] = new int[n];
	}

	cout << "---Введите значения элементов массива\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			A[i][j] = inputArr(i, j, A[i][j]);
		}
	}


	cout << "Матрица А:\n\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			cout << setw(5) << A[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;

	int d = 0; // d - число элементов массива arr

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			if (i == j) {
				if (A[i][j] % 2 == 0) {
					++d;
				}
			}
		}
	}
	
	if (d == 0) {
		cout << "Четных чисел на главной диагонали матрицы нет\n";
	}
	else {
		int* arr = new int[d];
		int f = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				if (i == j && A[i][j] % 2 == 0) {
					arr[f] = A[i][j];
					++f;
				}
			}
		}

		cout << "Массив четных элементов главной диагонали матрицы:\n\n";
		for (int i = 0; i < d; ++i) {
			cout << setw(5) << arr[i] << " ";
		}
		cout << endl << endl;

		int s = 1;
		for (int i = 0; i < d; ++i) {
			s *= arr[i];
		}

		cout << "Произведение элементов этого массива:\n\n" << setw(5) << s << endl;
	}

	return 0;
}

long long inputInt() {
	long double value;
	cin >> value;
	// Удаление всех пробелов (если они есть) после первого числа, если оно было в потоке
	while (cin.peek() == ' ')
		cin.ignore(1, ' ');
	// Проверка состояния потока ввода, конца строки, области допустимых значений и экспоненты
	while (cin.fail() || cin.peek() != '\n' || value <= 0 || value != (long long)value) {
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cin.clear(); // Включение потока ввода
		cin.ignore(3256, '\n'); // Очищение буфера потока ввода
		cin >> value;
		while (cin.peek() == ' ')
			cin.ignore(1, ' ');
	}
	return value;
}

long long inputArr(int i, int j, int Aij) {
	cout << "A[" << i << "]" << "[" << j << "] = ";
	cin >> Aij;
	while (cin.fail() || cin.peek() != '\n' || Aij != (long long)Aij) {
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cout << "A[" << i << "]" << "[" << j << "] = ";
		cin >> Aij;
	}
	return Aij;
}