//Лабораторная 3, задача 2. Выполнена: Воднев Д. И.

/*
    Найти суму ряда, используя цикл do-while
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    double d = 1;
    int n = 0;
    while (d >= 0.001) {
        d = 1 / pow(2, n) + 1 / pow(3, n);
        ++n;
    }
    cout << "Ответ: " << d << endl;
    return 0;
}
