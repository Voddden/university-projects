//Лабораторная 7, задача 6. Выполнена: 

/*
Мы будем называть число х интересным, если S(x + 1) < S(x).
1 <= x <= n
n - число
Посчитать количество х таких, что х - интересное.
*/

using namespace std;
#include <iostream>

long double input(double min, double max) {
	long double x;
	while (true) {
		cin >> x;
		if (!cin.fail() && cin.peek() == '\n' && x <= max && x >= min)
			return x;
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	cout << "Введите количество наборов данных: ";
	int count = input(1, 1e9);

	while (count-- != 0) {
		cout << "Введите целое число[1;10^9]: ";
		int x = input(1, 1e9);

		int num = x / 10;

		if (x % 10 == 9)

			num++;

		cout << "Количество интересных " << num << '\n';
	}

	return 0;
}