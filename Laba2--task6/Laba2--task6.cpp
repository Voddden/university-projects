//Лабораторная 2, задача 6. Выполнена: Воднев Д. И.

/*
    Составить программу используя переключатель switch:
*/

#include <iostream>
using namespace std;
#include <cmath>

int main() {
    setlocale(LC_ALL, "Rus");
    double a, b, c, Y;
    char N;
    a = -13.8;
    b = 8.9;
    c = 25;
    cout << "Введите переменную N\n";
    cin >> N;
    switch (N) {
        case '2' :
            cout << "Y равно " << b * c - a * a << endl;
        case '56' : 
            cout << "Y равно " << b * c << endl;
        case '7' :
            cout << "Y равно " << a * a + c << endl;
        case '3' :
            cout << "Y равно " << a - b * c << endl;
        default :
            cout << "Y равно " << pow(a + b, 3) << endl;
    }
    return 0;
}
