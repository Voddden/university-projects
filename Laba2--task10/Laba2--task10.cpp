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
    // ln
    double count = 1, totalValue = 0, it, x, z = 1, powe = 1, y;
    it = 1000;
    cout << "Введите x\n";
    cin >> x;
    while (count <= it)
    {
        for (int i = 0; i < powe; i++) {
            z *= (x - 1) / (x + 1);
        }
        y = (1 / powe) * z;

        totalValue = totalValue + y;
        powe = powe + 2;
        count++;
        z = 1;
    }

    //cout << "Значение логарифма:\n" << 2 * totalValue << endl;
    // ln

    
    double sinx, cosx, lnx;

    lnx = totalValue;
    const double pi = 3.1415926535;
    //cout << "Введите значение x\n";
    //cin >> x;
    cosx = (pi * pi - 4 * x * x) / (pi * pi + x * x);
    sinx = (16 * x * (pi - x)) / (5 * pi * pi - 4 * x * (pi - x));

    // сравнение значений
    if (sinx < cosx < lnx) {
        cout << "Функция sinx с этим значением x является наименьшей, и равной " << sinx << endl;
    }
    else if (cosx > sinx > lnx) {
        cout << "Функция cosx с этим значением x является наименьшей\n";
    }
    else if (lnx > sinx > cosx) {

    }
    else {
        cout << "Ошибка\n";
    }
    

    //cout << (sinx * sinx + cosx * cosx) << endl;



    return 0;
}
