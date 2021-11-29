//Лабораторная 5, задача 6 Выполнена: Воднев Д. И.

/*
Пусть f(n) - наибольший нечетный делитель натурального числа n. По заданному
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).
*/

using namespace std;
#include <iostream>

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

long long f(long long n) {
	if (n % 2 == 1) {
		return n;
	}
	if (n % 2 == 0) {
		long long ntemp = n;
		while (ntemp > 0 && ntemp % 2 == 0) {
			ntemp = ntemp / 2;
		}
		return ntemp;
	}
}

long long sum(long long n) {
	long long s = 0;
	for (int i = 1; i <= n; ++i) {
		s += f(i);
	}
	return s;
}

int main() {
	setlocale(LC_ALL, "Rus");

	cout << "Введите число n\n";
	long long n = inputInt();
	//cout << "Наибольший нечётный делитель числа " << n << " равен:\n" << f(n);
	cout << "Сумма равна:\n" << sum(n) << endl;

	return 0;
}