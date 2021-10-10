//Лабораторная 2, задача 7.2 Выполнена: Воднев Д. И.

/*
    Составить программу для решения уравнения:
    7.2 ax^4 + bx^3 + cx^2 + bx + a = 0
*/

#include <iostream>
using namespace std;
#include <cmath>

int main() {
    double X1 = 0, X2 = 0, X3 = 0, X4 = 0; // конечные ответы
    setlocale(LC_ALL, "Rus");
    cout << "7.2 ax^4 + bx^3 + cx^2 + bx + a = 0\n";
    cout << "Введите переменные a, b, c\n";
    double a, b, c;
    cin >> a >> b >> c;
    // 1-ое уравнение
    if (a == 0) {
        cout << "Ошибка, a = 0\n";
    }
    else {
        double a1, b1, c1, D1, x1_1, x1_2;
        a1 = a;
        b1 = b;
        c1 = c - 2 * a;
        D1 = b1 * b1 - 4 * a1 * c1;
        if (D1 < 0) {
            //cout << "Решений нет\n";
        }
        else if (D1 == 0) {
            cout << "error";
        }
        else {
            x1_1 = (-b1 + sqrt(D1)) / (2 * a1);
            x1_2 = (-b1 - sqrt(D1)) / (2 * a1);

            // 2-ое уравнение
            double a2, b2, c2, D2, x2_1, x2_2;
            a2 = 1;
            b2 = -x1_1;
            c2 = 1;
            D2 = b2 * b2 - 4 * a2 * c2;
            if (D2 < 0) {
                cout << "Решений нет\n";
            }
            else if (D2 == 0) {
                cout << "error1\n";
            }
            else {
                x2_1 = (-b2 + sqrt(D2)) / (2 * a2);
                x2_2 = (-b2 - sqrt(D2)) / (2 * a2);
                cout << "Корни уравнения:\n" << x2_1 << endl << x2_2 << endl;

                // 3-ее уравнение

                double a3, b3, c3, D3, x3_1, x3_2;
                a3 = 1;
                b3 = -x1_2;
                c3 = 1;
                D3 = b3 * b3 - 4 * a3 * c3;
                if (D3 < 0) {
                    cout << "Решений нет\n";
                }
                else if (D3 == 0) {
                    cout << "error3\n";
                }
                else {
                    x3_1 = (-b3 + sqrt(D3)) / (2 * a3);
                    x3_2 = (-b3 - sqrt(D3)) / (2 * a3);
                    cout << x3_1 << endl << x3_2 << endl;
                }
            }
        }
    }
    return 0;
}
