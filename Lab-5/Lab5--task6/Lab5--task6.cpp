//Лабораторная 5, задача 6 Выполнена: Воднев Д. И.

/*
Пусть f(n) - наибольший нечетный делитель натурального числа n. По заданному
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).
*/

using namespace std;
#include <iostream>

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

	cout << "Вводите данные:\n";
	int arr[3];
	for (int i = 0; i < 3; ++i) {
		cin >> arr[i];
		while (cin.fail() || cin.peek() != '\n' || arr[i] != (long long)arr[i] || arr[i] <= 0) {
			cin.clear();
			cin.ignore(99999, '\n');
			cout << "Введены некорректные данные, попробуйте ещё раз:\n";
			cin >> arr[i];
		}

	}
	cout << "\nРезультат:\n";
	for (int i = 0; i < 3; ++i) {
		cout << sum(arr[i]) << endl;
	}

	//cout << "Наибольший нечётный делитель числа " << n << " равен:\n" << f(n);
	//cout << "Сумма равна:\n" << sum(n) << endl;

	return 0;
}