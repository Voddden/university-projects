//Лабораторная 7, задача 9 Выполнена: Воднев Д. И.

/*
Вчера на уроке математики Саша (возможно Богом данный) узнал о том,
что иногда полезно использовать  вместо десятичной системы счисления какую-нибудь другую.
Однако, учительница (как иронично) не объяснила, почему в системе счисления по основанию b в
качестве цифр выбирают числа от 0 до b - 1. Немного подумав, Саша понял, что можно выбирать
и другие наборы цифр. Например, вместо троичной системы счисления можно рассмотреть систему
счисления, где вместо обычных цифр 0, 1, 2 есть цифры 1, 2 и 3.
Саша заинтересовался вопросом, а как перевести число n в эту систему счисления?
Например, число 7 в этой системе записывается как 21, так как 7 = 2*3+1,
а число 22 записывается как 211, так как 22 = 2 * 9 + 1 * 3 + 1
*/

using namespace std;
#include <iostream>
#include <string>

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

void toThree(int number, string& Number) {
	if (number / 3 > 0)
		toThree(number / 3, Number);
	Number += to_string(number % 3);
}

void toNew(string Number_, string& Number, int i) {
	string buff_;
	buff_[0] = Number_[i];

	int a = 0;

	if (atoi(buff_.c_str()) < 1) {
		string buff = to_string(atoi(buff_.c_str()) + 3);
		Number[i] = buff[0];
		if (i == 0) {
			string newNumber;
			newNumber.resize(Number.length() + 1);

			newNumber[0] = '2';
			for (short j = 0, k = 1; j < Number.length(); ++j, ++k)
				newNumber[k] = Number[j];
			cout << "Число в новой системе счисления: " << newNumber;
			return;
		}

		buff[0] = Number_[i - 1];
		a = atoi(buff.c_str()) - 1;

		if (a >= 0) {
			buff.erase(0, 1);

			string y = to_string(a);

			buff.push_back(y[0]);

			Number_[i - 1] = buff[0];
		}
		else {
			bool zero = false;

			a += 3;

			buff.erase(0, 1);

			string y = to_string(a);

			buff.push_back(y[0]);

			if (Number_[i - 1] == '0')
				zero = true;

			Number_[i - 1] = buff[0];

			if (zero) {
				buff[0] = Number_[i - 2];
				a = atoi(buff.c_str()) - 1;
				buff = to_string(a);
				Number_[i - 2] = buff[0];
			}
		}
	}
	else {
		Number[i] = Number_[i];
	}
		
	if (i - 1 == 0 && Number_[i - 1] == '0') {
		Number.erase(0, 1);
		cout << "Число в новой системе: " << Number;

		return;
	}

	if (i == 0) {
		cout << "Число в новой системе: " << Number;

		return;
	}

	return toNew(Number_, Number, --i);
}

int main() {
	setlocale(LC_ALL, "ru");

	cout << "Введите число: ";
	int number = input(1, 2e9);

	string Number;

	toThree(number, Number);

	toNew(Number, Number, Number.length() - 1);

	putchar('\n');

	return 0;
}