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
    double count = 1, totalValue = 0, it, x, z = 1, powe = 1, y;
    it = 1000;
    cout << "Введите x\n";
    cin >> x;
    if (x == 0) {
        cout << "Ошибка, x не может быть равен нулю\n";
    }
    else {

        //////////// ln - начало

        
        //double x1; // x для работы на вычисление логарифма
        if (x < 0) {
            x = -x;
        }
        
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
        /////////// ln - конец
        double sinx, cosx, lnx;
        lnx = 2 * totalValue;
        x = -x;
        //////////  sin cos start

        const double pi = 3.1415926535;
        double angX = 180 / pi * x;
        if (angX > 180) {
            angX = angX - 180;
        }

        

        sinx = (4 * angX * (180 - angX )) / (40500 - angX * (180 - angX));
        

        //cosx = (pi * pi - 4 * x * x) / (pi * pi + x * x);
        //sinx = (16 * x * (pi - x)) / (5 * pi * pi - 4 * x * (pi - x));

        cosx = 0;
        cout << "cosx: " << cosx << endl << "sinx: " << sinx << endl << "lnx: " << lnx << endl;

        /*
        /////////////////////////////////////////// сравнение значений
        if (sinx < cosx < lnx) {
            cout << "Функция sinx является наименьшей, и равной " << sinx << endl;
        }
        else if (cosx > sinx > lnx) {
            cout << "Функция cosx является наименьшей, и равной " << cosx << endl;
        }
        else if (lnx > sinx > cosx) {
            cout << "Функция lnx является наименьшей, и равной " << lnx << endl;
        }
        else {
            cout << "Ошибка\n";
        }
        */
    }


    



    return 0;
}
