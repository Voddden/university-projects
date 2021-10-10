//Лабораторная 2, задача 7.1 Выполнена: Воднев Д. И.

/*
    Составить программу для решения уравнения:
    7.1 ax^4 + bx^2 + c = 0;
*/

#include <iostream>
using namespace std;
#include <cmath>

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "7.1 ax^4 + bx^2 + c = 0\n\n";
    cout << "Введите переменные a, b, c\n";
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
        cout << "a = 0, ошибка\n";
    }
    else {
        // Решение уравнения #1
        double a1, b1, c1, D1, x1_1 = 0, x1_2 = 0;
        a1 = a;
        b1 = b;
        c1 = c;
        D1 = b1 * b1 - 4 * a1 * c1;
        if (D1 < 0) {
            cout << "Действительных корней нет\n";
        }
        else if (D1 == 0) {
            double x1_0;
            x1_0 = (-b1) / (2 * a1);
            if (x1_0 > 0) {
                cout << "Корни уравнения:\n" << sqrt(x1_0) << endl << -sqrt(x1_0) << endl;
            }
            else if (x1_0 < 0) {
                cout << "Действительных корней нет\n";
            }
            else if (x1_0 == 0) {
                cout << "Корень уравнения:\n" << 0 << endl;
            }
        }
        else if (D1 > 0) {
            x1_1 = (-b1 + sqrt(D1)) / (2 * a1);
            x1_2 = (-b1 - sqrt(D1)) / (2 * a1);
            if (x1_1 > 0 && x1_2 > 0) { // + +
                cout << "Корни уравнения:\n" << sqrt(x1_1) << endl << -sqrt(x1_1) << endl << sqrt(x1_2) << endl << -sqrt(x1_2) << endl;
            } 
            else if (x1_1 > 0 && x1_2 < 0) { // + -
                cout << "Корни уравнения:\n" << sqrt(x1_1) << endl << -sqrt(x1_1) << endl;
            }
            else if (x1_1 < 0 && x1_2 > 0) { // - +
                cout << "Корни уравнения:\n" << sqrt(x1_2) << endl << -sqrt(x1_2) << endl;
            }
            else if (x1_1 < 0 && x1_2 < 0) { // - -
                cout << "Действительных корней нет\n";
            }
            else if (x1_1 == 0 && x1_2 > 0) { // 0 +
                cout << "Корни уравнения:\n" << 0 << endl << sqrt(x1_2) << endl << -sqrt(x1_2) << endl;
            }
            else if (x1_1 == 0 && x1_2 < 0) { // 0 -
                cout << "Корень уравнения:\n" << 0 << endl;
            }
            else if (x1_1 > 0 && x1_2 == 0) { // + 0
                cout << "Корни уравнения:\n" << sqrt(x1_1) << endl << -sqrt(x1_1) << endl << 0 << endl;
            }
            else if (x1_1 < 0 && x1_2 == 0) { // - 0
                cout << "Корень уравнения:\n" << 0 << endl;
            }
            else if (x1_1 == 0 && x1_2 == 0) {
                cout << "Корень уравнения:\n" << 0 << endl;
            }
        }
    }
    return 0;
}