//Лабораторная 7, задача 5 Выполнена: 

//Перевести число из арабской системы записи чисел в римскую.

using namespace std;
#include <iostream>
#include <string>

long double input_(double min, double max) {
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
	cout << "Введите число:\n";

	int input = input_(0, 40000);

	for (int i = 0; i < input / 1000; i++)
		cout << "M";

	input %= 1000;

	if ((input % 500) / 100 + 5 == 9) {
		cout << "CM";
		input %= 900;
	}
	else if (input / 500 > 0) {
		cout << "D";
		input %= 500;
	}

	for (int i = 0; i < input / 100; i++)
		cout << "C";

	input %= 100;

	if ((input % 50) / 10 + 5 == 9) {
		cout << "XC";
		input %= 90;
	}
	else if (input / 50 > 0) {
		cout << "L";
		input %= 50;
	}

	if (input / 10 == 4) {
		cout << "XL";
		input %= 40;
	}

	for (int i = 0; i < input / 10; i++) {
		cout << "X";
	}

	input %= 10;

	if (input == 1)
		cout << "I";

	if (input == 2)
		cout << "II";

	if (input == 3)
		cout << "III";

	if (input == 4)
		cout << "IV";

	if (input == 5)
		cout << "V";

	if (input == 6)
		cout << "VI";

	if (input == 7)
		cout << "VII";

	if (input == 8)
		cout << "VIII";

	if (input == 9)
		cout << "IX";

	return 0;
}