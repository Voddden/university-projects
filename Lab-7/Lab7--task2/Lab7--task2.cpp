//Лабораторная 7, задача 2. Выполнена: Воднев Д. И.

/*
Перевести числа. Предусмотреть ввод положительных и
отрицательных чисел.
5. Из прямого кода в дополнительный
*/

using namespace std;
#include <iostream>
#include <string>

string to_obrCode(string str) {
	for (int i = 1; i < str.length(); ++i) {
		if (str[i] == '1')
			str[i] = '0';
		else
			str[i] = '1';
	}
	return str;
}

string to_dopCode(string str) {
	int count = 7;
	if (str[count] == '0') { // добавление единицы 
		str[count] = '1';
	}
	else if (str[count] == '1') {
		while (str[count] != '0') {
			str[count] = '0';
			--count;
		}
		str[count] = '1';
	}
	return str;
}

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Введите число в прямом коде:\n";
	string number;
	cin >> number;
	string obrCode = to_obrCode(number);
	//cout << "Обратный код:\n" << obrCode << endl;
	string dopCode = to_dopCode(obrCode);
	cout << "Дополнительный код:\n" << dopCode << endl;	
	return 0;
}