//Лабораторная 2, задача 5. Выполнена: Воднев Д. И.

/*
    Составить программу используя условный оператор if:
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    double a, b, c, d, Z;
    cout << "Введите переменные в таком порядке: a, b, c, d\n";
    cin >> a >> b >> c >> d;
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
