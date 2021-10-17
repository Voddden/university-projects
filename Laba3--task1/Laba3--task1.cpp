//Лабораторная 3, задача 1 Выполнена: Воднев Д. И.

/*
    вычислить сумму, использую цикл while
*/

using namespace std;
#include <iostream>

int main() {
    setlocale(LC_ALL, "Rus");

    double N = 0, a, b;
    int i = 1;
    while (i <= 30) {
        if (i % 2 == 1) { // нечётное
            a = i;
            b = i * i;
            N = N + (a - b) * (a - b);
        }
        else if (i % 2 == 0) { // чётное
            a = i / 2;
            b = i * i * i;
            N = N + (a - b) * (a - b);
        }

        ++i;
    }
    cout << "Ответ:\n" << N << endl;

    return 0;
}