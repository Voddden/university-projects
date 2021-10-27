#include <iostream>
using namespace std;

long double fact(long double x) {

	if (x == 0 || x == 1) {

		return 1;
	}
	else {

		return x * fact(x - 1);
	}
}

long double power(long double x, long double y) {

	long double s = 1;

	while (y > 0) {

		s = s * x;
		y--;
	}

	return s;
}

long double ln(long double x) {

	double s = 0;

	for (int i = 1; i < 101; i += 2) {

		s += power((x - 1) / (x + 1), i) / i;
	}

	s *= 2;

	return s;
}

long double power_d(long double y, long  double x) {

	double s = 1;

	for (int i = 1; i < 100; i++) {

		s += power(x * ln(y), i) / fact(i);
	}

	return s;
}

int main() {
	setlocale(LC_ALL, "Rus");
	long double x, s;
	int n, nx, i = 0, j;

	cout << "Эта программа находит значение (1+2x^2)e^x^2 двумя способами:\n1.Через функцию \n";
	cout << "2.Через ряд Тейлора\n\nВведите количество членов ряда которые вы хотите использовать(n): ";
	cin >> n;

	while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {

		cin.clear();
		cin.ignore(99999, '\n');

		cout << "\nВы ввели неверное значение n, введите целое положительное число: ";
		cin >> n;
	}

	cout << "\nВведите количество чисел, от которых хотите посчитать функцию: ";
	cin >> nx;

	while (cin.fail() || cin.peek() != '\n' || nx != (long long)nx || nx <= 0) {

		cin.clear();
		cin.ignore(99999, '\n');

		cout << "\nВы ввели неверное значение, введите целое положительное число: ";
		cin >> nx;
	}

	while (++i <= nx) {

		cout << "\nВведите " << i << " значение x [0.1;1] : ";
		cin >> x;

		while (cin.fail() || cin.peek() != '\n' || x > 1 || x < 0.1) {

			cin.clear();
			cin.ignore(99999, '\n');

			cout << "\nВы ввели неверное значение x, попробуйте ввести число в промежутке от 0.1 до 1: ";
			cin >> x;
		}

		j = 0;
		s = 0;
		/*
		while (++j <= n) {

			s += power(2 * x, j) / fact(j);
		}
		*/
		while (++j <= n) { // n == j

			s += ((2 * j + 1) / fact(j)) * power(x, 2 * j);
		}
		cout << "1.Через функцию: " << (1 + 2 * x * x) * power_d(2.71828182846, x * x) << endl;
		cout << "2.Через ряд Тейлора: " << s << endl;
	}

	return 0;
}