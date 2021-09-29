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
    double y1, y2; // переменная для замены: y = x + 1/x

    // Расчёт квадратного уравнения 1.0
    double aSQ, bSQ, cSQ, D, x1SQ, x2SQ;
    aSQ = a;
    bSQ = b;
    cSQ = c - 2 * a;
    if (aSQ == 0) {
        cout << "Ошибка! a не может быть равен нулю\n";
    }
    else {
        D = pow(bSQ, 2) - 4 * aSQ * cSQ;
        if (D < 0) {
            cout << "Уравнение не имеет действительных корней\n";
        }
        else if (D == 0) {
            cout << "У квадратного уравнения оба корня равны\n";

        }
        else {
            x1SQ = (-b + sqrt(D)) / (2 * aSQ);
            x2SQ = (-b - sqrt(D)) / (2 * aSQ);
            y1 = x1SQ;
            y2 = x2SQ;
            
            //Расчёт квадратного уравнения 2.1 (xSQ1 = y1)
            double aSQ1, bSQ1, cSQ1, D1, x1SQ1, x2SQ1;
            aSQ1 = 1;
            bSQ1 = -y1;
            cSQ1 = 1;
            if (aSQ1 == 0) {
                cout << "Ошибка2.1! a не может быть равен нулю\n";
            }
            else {

                D1 = pow(bSQ1, 2) - 4 * aSQ1 * cSQ1;
                if (D1 < 0) {
                    cout << "Уравнение не имеет действительных корней1\n";
                }
                else if (D == 0) {

                }
                else {
                    x1SQ1 = (-bSQ1 + sqrt(D1)) / (2 * aSQ1);
                    x2SQ1 = (-bSQ1 - sqrt(D1)) / (2 * aSQ1);
                    X1 = x1SQ1;
                    X2 = x2SQ1;
                    cout << X1 << " " << X2 << endl;

                    // Расчёт квадратного уравнения 2.2 (xSQ2 = y2)
                    double aSQ2, bSQ2, cSQ2, D2, x1SQ2, x2SQ2;
                    aSQ2 = 1;
                    bSQ2 = -y2;
                    cSQ2 = 1;
                    if (aSQ2 == 0) {
                        cout << "Ошибка2.2! a не может быть равен нулю\n";
                    }
                    else {
                        D2 = pow(bSQ2, 2) - 4 * aSQ2 * cSQ2;
                        if (D2 < 0) {
                            cout << "Уравнение не имеет действительных корней2\n";
                        }
                        else if (D == 0) {

                        }
                        else {
                            x1SQ2 = (-bSQ2 + sqrt(D2)) / (2 * aSQ2);
                            x2SQ2 = (-bSQ2 - sqrt(D2)) / (2 * aSQ2);
                            X3 = x1SQ2;
                            X4 = x2SQ2;
                            cout << X3 << " " << X4 << endl;
                        }
                    }
                }
                
            }
          
        }
    }


    /*
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
    */
    return 0;
}
