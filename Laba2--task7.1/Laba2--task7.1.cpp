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
        // переход к ay^2 + by + c = 0
        double D;
        D = b * b - 4 * a * c;
        if (D < 0) {
            cout << "Решений нет\n";
        }
        else if (D > 0) {
            double y1, y2;
            y1 = (-b + sqrt(D)) / (2 * a);
            y2 = (-b - sqrt(D)) / (2 * a);
            if (y1 > 0 && y2 > 0) {
                double x1, x2;
                x1 = sqrt(y1);
                x2 = sqrt(y2);
                cout << "Решения уравнения: " << x1 << " " << x2 << endl;
            }
            else if (y1 < 0 && y2 > 0) {
                double x2;
                x2 = sqrt(y2);
                cout << "Решение уравнения: " << x2 << endl;
            }
            else if (y1 > 0 && y2 < 0) {
                double x1;
                x1 = sqrt(y1);
                cout << "Решение уравнения: " << x1 << endl;
            }
            else if (y1 < 0 && y2 < 0) {
                cout << "Решений нет\n";
            }
            // варианты с нулями
            else if (y1 == 0 && y2 > 0) { // 1
                cout << "Решения уравнения: " << 0 << " " << sqrt(y2) << endl;
            }
            else if (y1 == 0 && y2 < 0) { // 2
                cout << "Решение уравнения: " << 0 << endl;
            }
            else if (y1 > 0 && y2 == 0) { // 3
                cout << "Решения уравнения: " << sqrt(y1) << " " << 0 << endl;
            }
            else if (y1 < 0 && y2 == 0) { // 4
                cout << "Решение уравнения: " << 0 << endl;
            }
            else if (y1 == 0 && y2 == 0) {
                cout << "Решение уравнения: " << 0 << endl;
            }
            else {
                cout << "Ошибка1\n";
            }
        }
        else {
            cout << "Ошибка\n";
        }
    }
    return 0;
}
