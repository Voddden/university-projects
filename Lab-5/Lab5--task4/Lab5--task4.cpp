//Лабораторная 5, задача 4 Выполнена: Воднев Д. И.

/*
По заданным p и q необходимо вычислить S (p, q)
*/

using namespace std;
#include <iostream>

long long inputInt();
int F(int n);
int S(int p, int q);

int main() {
	setlocale(LC_ALL, "Rus");

	cout << "---Введите p и q\n";
	int p, q;
	cin >> p >> q;
	while (cin.fail() || cin.peek() != '\n' || p != (long long)p || p <= 0 || q != (long long)q || q <= 0) {
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "Введены некорректные данные, попробуйте ещё раз:\n";
		cin >> p >> q;
	}
	cout << "Результат:\n" << S(p, q) << endl;

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

int F(int n) {
	if (n % 10 > 0) {
		return n % 10;
	}
	else if (n == 0) {
		return 0;
	}
	else {
		return F(n / 10);
	}
}

int S(int p, int q) {
	long long result = 0;
	for (int i = p; i <= q; ++i) {
		result += F(i);
	}
	return result;
}