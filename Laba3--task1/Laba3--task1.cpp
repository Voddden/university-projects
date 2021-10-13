//Лабораторная 3, задача 1 Выполнена: Воднев Д. И.

/*
    Вычислить N
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    double N = 0, a, b;
    int i = 1;

    //cout << "Введите N\n";
    //cin >> N;
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
