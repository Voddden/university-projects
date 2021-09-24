//Лабораторная 2, задача 7. Выполнена: Воднев Д. И.

/*
    Составить программу для решения уравнений трёх видов:
    7.1 ax^4 + bx^2 + c = 0;
    7.2 ax^4 + bx^3 + cx^2 + bx + a = 0
    7.3 x^3 + px + q = 0    
*/

#include <iostream>
using namespace std;
#include <cmath>

int main() {
    setlocale(LC_ALL, "Rus");

/*
    // 7.1 ax^4 + bx^2 + c = 0;
    cout << "7.1 ax^4 + bx^2 + c = 0\n\n";

    double a, b, c;
    cout << "Введите переменные a, b, c\n";
    cin >> a >> b >> c;
    double D; // дискриминант
    D = b * b - 4 * a * c;
    if (a == 0) {
        cout << "Ошибка! a не может быть равен нулю\n";
    }
    else if (D > 0) {
        double z1, z2;
        z1 = (-b + sqrt(D)) / (2 * a);
        z2 = (-b - sqrt(D)) / (2 * a);
        double x1, x2;
        x1 = sqrt(z1);
        x2 = sqrt(z2);
        cout << "Дискриминант больше нуля. Корни уравнения: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (D == 0) {
        double z1 = (-b) / (2 * a);
        double x1 = sqrt(z1);
        cout << "Дискриминант равен нулю. Корень уравнения: x1 = " << x1 << endl;
    }
    else if (D < 0) {
        cout << "Уравнение не имеет корней\n";
    }
    else {
        cout << "Возникла ошибка\n";
    }
*/

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
