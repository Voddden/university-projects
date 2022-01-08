//Лабораторная 7, задача 4. Выполнена Воднев Д. И.

/*
Осуществить сложение и вычитание чисел в заданной системе счисления.
5) в девятнадцатеричной;
*/

using namespace std;
#include <iostream>
#include <string>

int num19_to_num10(string num19) {
	int* arr = new int[num19.length()]; // массив цифр числа num19
	for (int i = 0; i < num19.length(); ++i) {
		if (num19[i] == 'a') {
			arr[i] = 10;
		}
		else if (num19[i] == 'b') {
			arr[i] = 11;
		}
		else if (num19[i] == 'c') {
			arr[i] = 12;
		}
		else if (num19[i] == 'd') {
			arr[i] = 13;
		}
		else if (num19[i] == 'e') {
			arr[i] = 14;
		}
		else if (num19[i] == 'f') {
			arr[i] = 15;
		}
		else if (num19[i] == 'g') {
			arr[i] = 16;
		}
		else if (num19[i] == 'h') {
			arr[i] = 17;
		}
		else if (num19[i] == 'i') {
			arr[i] = 18;
		}
		else {
			arr[i] = num19[i] - 48;
		}
	}

	int num10 = 0;
	int razryad = 0;
	for (int i = num19.length() - 1; i >= 0; --i) {
		num10 = num10 + arr[i] * pow(19, razryad);
		++razryad;
	}

	return num10;
}

string num10_to_num19(int num10) {
	string num19;

	int number_of_digits_in_num19 = 1;
	int num10_1 = num10;
	while (num10_1 / 19 > 0) {
		++number_of_digits_in_num19;
		num10_1 = num10_1 / 19;
	}
	int* arr = new int[number_of_digits_in_num19]; // массив цифр num19 (задом наперед)
	for (int i = 0; i < number_of_digits_in_num19; ++i) {
		arr[i] = num10 % 19;
		num10 /= 19;
	}

	int c;
	for (int i = 0; i < (number_of_digits_in_num19 / 2); i++) { // переворачивание массива цифр num19
		c = arr[i];
		arr[i] = arr[number_of_digits_in_num19 - 1 - i];
		arr[number_of_digits_in_num19 - 1 - i] = c;
	}

	return num19;
}

int main() {
	setlocale(LC_ALL, "ru");
	string num1_cc19;
	string num2_cc19;

	cout << "Введите 1-ое число в 19-чной сс: ";
	cin >> num1_cc19;
	cout << "Введите 2-ое число в 19-чной сс: ";
	cin >> num1_cc19;

	int num1_cc10 = num19_to_num10(num1_cc19);
	int num2_cc10 = num19_to_num10(num2_cc19);
	int sum = num1_cc10 + num2_cc10;
	
	//cout << "Ваше число в 10-чной сс: " << num19_to_num10(num19) << endl;
	return 0;
}