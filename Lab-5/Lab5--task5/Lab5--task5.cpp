//Лабораторная 5, задача 5 Выполнено: Воднев Д. И.

/*
Рекурсивная функция задана следующим образом:
Для каждого теста в отдельной строке вывести номер теста и значение x.
*/

#include <iostream>
using namespace std;

long long recurse(long long x, long long y, long long n) {
	if (y == 0)
		return 1;
	if (y % 2 == 1)
		return x * recurse(x * x % n, y / 2, n) % n;
	return recurse(x * x % n, y / 2, n);
}

long long recursResult(long long k, long long n, long long t) {
	long long m = pow(10, t), l = k % m;
	return recurse(l, n, m);
}

int main() {
	setlocale(LC_ALL, "ru");

	cout << "Вводите данные:\n";
	long long k, n, t;
	cin >> k >> n >> t;
	while (cin.fail() || cin.peek() != '\n' || k != (long long)k || k < 0 || n != (long long)n || n < 0 || t != (long long)t || t < 0) {
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cin >> k >> n >> t;
	}
	int caseNumber = 1;
	while (n != 0 && k != 0 && t != 0) {
		cout << "Case #" << caseNumber++ << ": " << recursResult(k, n, t) << endl;

		cin >> k >> n >> t;
		while (cin.fail() || cin.peek() != '\n' || k != (long long)k || k < 0 || n != (long long)n || n < 0 || t != (long long)t || t < 0) {
			cin.clear();
			cin.ignore(99999, '\n');
			cout << "Введены некорректные данные, попробуйте ещё раз:\n";
			cin >> k >> n >> t;
		}
	}

	return 0;
}