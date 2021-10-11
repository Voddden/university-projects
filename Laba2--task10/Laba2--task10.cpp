//Лабораторная 2, задача 10. Выполнена: Воднев Д. И.

/*
    Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x|
    при заданном х, определить и вывести на экран дисплея минимальное
    значение. Библиотеку <cmath> использовать запрещено.
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    double x, sinx, cosx, lnx;
    const double pi = 3.1415926535;
    cout << "Введите значение x\n";
    cin >> x;





    cosx = (pi * pi - 4 * x * x) / (pi * pi + x * x);
    sinx = (16 * x * (pi - x)) / (5 * pi * pi - 4 * x * (pi - x));
    if (sinx < cosx < lnx) {
        cout << "Функция sinx с этим значением x является наименьшей\n";
    }
    else if (cosx > sinx > lnx) {
        cout << "Функция cosx с этим значением x является наименьшей\n";
    }
    else if (lnx > sinx > cosx) {

    }
    //cout << (sinx * sinx + cosx * cosx) << endl;



    return 0;
}
