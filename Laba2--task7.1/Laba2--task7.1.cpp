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
    return 0;
}
