//Лабораторная 2, задача 7.3 Выполнена: 

/*
    Составить программу для решения уравнения:
    7.3 x^3 + px + q = 0

    (или x^3 + bx + c = 0)
*/

#include <iostream>
using namespace std;
#include <cmath>

int main() {
    const double pi = 3.1415926535;
    setlocale(LC_ALL, "Rus");
    cout << "Введите p и q\n";
    double a = 1, b, c;
    cin >> b >> c;
    double Q, R, S;
    Q = (a * a - 3 * b) / 9;
    R = (2 * a * a * a - 9 * a * b + 27 * c) / 54;
    S = pow(Q, 3) - pow(R, 2);
    
    if (S > 0) {
        double o, x1, x2, x3;
        o = 1 / 3 * acos(R / sqrt(Q * Q * Q));
        x1 = -2 * sqrt(Q) * cos(o) - a / 3;
        x2 = -2 * sqrt(Q) * cos(o + 2 * pi / 3) - a / 3;
        x3 = -2 * sqrt(Q) * cos(o - 2 * pi / 3) - a / 3;
        cout << "1Корни уравнения:\n" << x1 << endl << x2 << endl << x3 << endl;
    }
    if (S < 0) {
        double p = b, q = c;
        double x1;
        x1 = cbrt((-q / 2) + sqrt(q * q / 4 + p * p * p / 27)) + cbrt((-q / 2) - sqrt((q * q / 4) + p * p * p / 27));
        cout << "Корень уравнения:\n" << x1 << endl;
    }
    if (S == 0) {
        double x1, x2;
        x1 = -2 * pow(R, 1 / 3) - a / 3;
        x2 = pow(R, 1 / 3) - a / 3;
        cout << "Корни уравнения:\n" << x1 << endl << x2 << endl;
    }
    return 0;
}