//Лабораторная 3, задача 9 Выполнена: 

/*
    Вычислить сумму последовательности
*/

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введите 1-ый и 2-ой член АП\n";
    long long a1, a2, d;
    cin >> a1 >> a2;
    while (cin.fail() || cin.peek() != '\n' || a1 != (long long)a1 || a1 <= 0 || a2 != (long long)a2 || a2 <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ввести данные через пробел ещё раз:\n";
        cin >> a1 >> a2;
    }
    d = a2 - a1;
    long long sum = 0;
    for (long long Ix = 1; Ix <= 99999; ++Ix) { // Ix - индекс последовательности (Xn)
        sum = sum + pow(2, Ix - 1) * pow(-1, Ix - 1) * (a1 + d * (Ix - 2));
    }
    cout << "Ответ:\n" << sum << endl;
    return 0;
}