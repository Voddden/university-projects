//Лабораторная 2, задача 5. Выполнена: Воднев Д. И.

/*
Составить программу используя условный оператор if:
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    double a, b, c, d, Z;
    a = 3.8;
    b = -25;
    c = 5;
    cout << "Введите переменную d\n";
    cin >> d;
    if (c >= d && a < d) {
        Z = a + b / c;
        cout << "Z равно " << Z << endl;
    }
    else if (c < d && a >= d) {
        Z = a - b / c;
        cout << "Z равно " << Z << endl;
    }
    else {
        cout << "Z равно 0\n";
    }

    return 0;
}
