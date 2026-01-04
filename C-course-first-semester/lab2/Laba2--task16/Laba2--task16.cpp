//Лабораторная 2, задача 16. Выполнена: 

/*
	Введены два числа. Выведите их НОД и НОК.
*/

#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int a, b, a1, b1, NOD, NOK;
	cout << "Введите переменые a, b\n";
	cin >> a1 >> b1;
	a = a1;
	b = b1;
	while (a != 0 && b != 0) {
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	NOD = a + b;
	NOK = (a1 * b1) / NOD;
	cout << endl << "НОД этих чисел равен " << NOD << endl;
	cout << "НОК этих чисел равен " << NOK << endl;
	return 0;
}
