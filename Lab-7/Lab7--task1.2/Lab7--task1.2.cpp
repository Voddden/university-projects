// Лабораторная 7, задача 1(вариант 10). Выполнена: Воднев Д. И.

/* из девятичной в семнадцатеричную (без массива) */


#include <iostream>
#include <cmath>

double get_value_ninefold();
double from_ninefold_to_ten(double value_9);
char* from_ten_to_seventeenfold(double value_10, char* arr);

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Программа осуществляет перевод чисел из девятичной в семнадцатеричную систему счисления (без массива).";
	double value_9 = get_value_ninefold();

	double value_10 = from_ninefold_to_ten(value_9); //перевели из 9 в 10 систему

	char* arr = new char[20];

	cout << "\nВаше число в семнадцатиричной сс: ";
	arr = from_ten_to_seventeenfold(value_10, arr);
	cout << endl;
}

double from_ninefold_to_ten(double value_9) {
	int last_number, whole_value_10 = 0, degree = 0;
	int whole = trunc(value_9);

	while (whole > 0) {
		last_number = whole % 10;
		whole_value_10 += last_number * pow(10, degree++);
		whole /= 10;
	}

	int drob = (value_9 - trunc(value_9)) * 1000000;
	last_number = 0, degree = -6;
	double drob_value_10 = 0;

	while (drob > 0)
	{
		last_number = drob % 10;
		drob_value_10 += last_number * pow(10, degree++);
		drob /= 10;
	}
	double value_10 = (double)whole_value_10 + (double)drob_value_10;
	return value_10;
}

char* from_ten_to_seventeenfold(double value_10, char* arr) {
	int del = value_10;
	int whole, remains, i, j;

	for (j = 0; del > 0; j++) {
		del = value_10 / 17; //делим
		whole = del * 17; // целая часть от деления
		remains = value_10 - whole; //остаток

		if (remains == 10)
			arr[j] = 'a';
		if (remains == 11)
			arr[j] = 'b';
		if (remains == 12)
			arr[j] = 'c';
		if (remains == 13)
			arr[j] = 'd';
		if (remains == 14)
			arr[j] = 'e';
		if (remains == 15)
			arr[j] = 'f';
		if (remains == 16)
			arr[j] = 'g';
		if (remains < 10)
			arr[j] = remains + '0';
		value_10 /= 14;
	}
	for (int i = j - 1; i >= 0; i--) {
		cout << arr[i];
	}
	return arr;
}

double get_value_ninefold() {
	while (true) {
		double element;
		cout << "\nВведите число в девятичной системе счисления: ";
		cin >> element;
		if (element < 0)
			cout << "-";

		bool flag = false;
		int last_number;
		int element_copy = abs(element);
		while (element_copy > 0) {
			last_number = element_copy % 10;

			if (last_number >= 10) {
				flag = true;
				break;
			}
			element_copy /= 10;
		}
		int drob_part = (element - abs(trunc(element))) * 1000000;

		while (drob_part > 0) {
			last_number = drob_part % 10;

			if (last_number >= 10) {
				flag = true;
				break;
			}
			drob_part /= 10;
		}
		if (cin.fail() || cin.peek() != '\n' || flag) { // if we entered erundu
			cin.clear(); // "heal" cin
			cin.ignore(32768, '\n'); // delete all erundu out of cin
			cout << "Try again..." << endl;
		}
		else
			return abs(element);
	}
}