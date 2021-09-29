//Лабораторная 2, задача 7.2 Выполнена: Воднев Д. И.

/*
    Составить программу для решения уравнения:
    7.2 ax^4 + bx^3 + cx^2 + bx + a = 0
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    // 7.2 ax^4 + bx^3 + cx^2 + bx + a = 0
    cout << "7.2 ax^4 + bx^3 + cx^2 + bx + a = 0\n";

    double a, b, c;
    cout << "Введите переменные a, b, c\n";
    cin >> a >> b >> c;
    if (a == 0) {
        cout << "Ошибка, а равен нулю\n";
    }
    else if (c == 0) {
        cout << "Ошибка, c равно нулю\n";
    }
    else {
        if (b > 0) {
            double D1, D2;
            D1 = b * b - 4 * a * (c - 2 * a);







            double x1, x2, x3, x4;
            // + +
            x1 = ((b + sqrt(b * b - 4 * a * (c - 2 * a))) / (-2 * a) + sqrt((b - sqrt(b * b - 4 * a * (c - 2 * a))) / (2 * a) - 4)) / (2 * a);
            // - -
            x2 = ((b - sqrt(b * b - 4 * a * (c - 2 * a))) / (-2 * a) - sqrt((b - sqrt(b * b - 4 * a * (c - 2 * a))) / (2 * a) - 4)) / (2 * a);
            // + -
            x3 = ((b + sqrt(b * b - 4 * a * (c - 2 * a))) / (-2 * a) - sqrt((b - sqrt(b * b - 4 * a * (c - 2 * a))) / (2 * a) - 4)) / (2 * a);
            // - +
            x4 = ((b - sqrt(b * b - 4 * a * (c - 2 * a))) / (-2 * a) + sqrt((b - sqrt(b * b - 4 * a * (c - 2 * a))) / (2 * a) - 4)) / (2 * a);

            cout << "Корни уравнения: " << x1 << " " << x2 << " " << x3 << " " << x4 << endl;

        }
        else if (b < 0) {

        }
        else {
            cout << "Произошла ошибка\n";
        }
    }
    return 0;
}
