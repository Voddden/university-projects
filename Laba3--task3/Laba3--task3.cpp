//Лабораторная 3, задача 3 Выполнена: Воднев Д. И.

/*
    Вычислить функцию, используя цикл for
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    const double pi = 3.14;
    double A = 0, B = pi / 2, M = 20;
    double x, H;
    H = (B - A) / M;
    cout << "Вычисление значений функции на заданном промежутке аргумента [" << A << ";" << B << "]\n";
    for (int i = 0; (A + i * H) <= B; ++i) {
        x = A + i * H;
        cout << sin(x) - cos(x) << endl;
    }
    //cout << sin(x) << endl << cos(x) << endl;
    //y = sin(x) - cos(x);
    return 0;
}