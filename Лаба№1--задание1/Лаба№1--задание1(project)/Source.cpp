#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	double a, b, c, x;
	cout << "Введите значение x\n";
	cin >> x;
	c = x * x;
	a = 69 * c + 8;
	b = x * (23 * c + 32);
	cout << "В первом выражении x = " << a + b << endl << "Во втором выражении x = " << a - b << endl;
	return 0;
}

/*
Тесты:
1)
x = 1
Ответ: 132; 22 (верно)

2) 
x = 0
Ответ 8; 8 (верно)

3)
x = -5
Ответ: -1302; 4768 (верно)
*/