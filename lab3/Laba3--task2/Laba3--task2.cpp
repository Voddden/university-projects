//Лабораторная 3, задача 2. Выполнена: 

/*
    Найти суму ряда, используя цикл do-while
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    double d = 1;
    int n = 1;
    long double sum = 0;
    do {
        d = 1. / pow(2, n) + 1. / pow(3, n);
        sum += d;
        ++n;
    } while (d >= 0.0000001);
    cout << "Ответ:\n" << sum << endl;
    return 0;
}
