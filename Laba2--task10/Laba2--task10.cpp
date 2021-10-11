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
    const double pi = 3.1415926535;

    cout << "Введите x\n";
    double x;
    cin >> x;

    double LNX, SINX, COSX;
    
    if (x == 0) {
        cout << "Ошибка, x не может быть равен нулю\n";
    }
    else if (x > 0) {
        
        //// ln - 1
        double count = 1, totalValue = 0, it = 1000, xLN = x, z = 1, powe = 1, y;
        if (xLN < 0) {
            xLN = -xLN;
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
            double lnx;
            lnx = 2 * totalValue;
            cout << "lnx: " << lnx << endl;
            
        }
        else {
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
            double lnx;
            lnx = 2 * totalValue;
            cout << "lnx: " << lnx << endl;
            
        }
        //// ln - 0

        //// sinx - 1


        if (x > 0 && x < pi / 2) { // 1 четверть +
            double xSIN = x;
            if (xSIN > pi) {
                //xSIN = xSIN - pi;
                while (xSIN > pi) {
                    xSIN = xSIN - pi;
                }
                double sinx;
                sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
                cout << "sinx: " << sinx << endl;
            }
            else {
                double sinx;
                sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
                cout << "sinx: " << sinx << endl;
            }
        }
        else if (x >= pi / 2 && x < pi) { // 2 четверть +
            double xSIN = x;
            if (xSIN > pi) {
                //xSIN = xSIN - pi;
                while (xSIN > pi) {
                    xSIN = xSIN - pi;
                }
                double sinx;
                sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
                cout << "sinx: " << sinx << endl;
            }
            else {
                double sinx;
                sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
                cout << "sinx: " << sinx << endl;
            }
        }
        else if (x >= pi && x < 1.5 * pi) { // 3 четверть -
            double xSIN = x;
            if (xSIN > pi) {
                //xSIN = xSIN - pi;
                while (xSIN > pi) {
                    xSIN = xSIN - pi;
                }
                double sinx;
                sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
                cout << "sinx: " << -sinx << endl;
            }
            else {
                double sinx;
                sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
                cout << "sinx: " << -sinx << endl;
            }
        }
        else if (x >= 1.5 * pi && x < 2 * pi) { // 4 четверть -
            double xSIN = x;
            if (xSIN > pi) {
                //xSIN = xSIN - pi;
                while (xSIN > pi) {
                    xSIN = xSIN - pi;
                }
                double sinx;
                sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
                cout << "sinx: " << -sinx << endl;
            }
            else {
                double sinx;
                sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
                cout << "sinx: " << -sinx << endl;
            }
        }




        //// sinx - 0
        
        //// cosx - 1


        if (x > 0 && x < pi / 2) { // 1 четверть +
            double xCOS = x;
            if (xCOS > pi) {
                //xCOS = xCOS - pi;
                while (xCOS > pi) {
                    xCOS = xCOS - pi;
                }
                double cosx;
                cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
                cout << "cosx: " << cosx << endl;
            }
            else {
                double cosx;
                cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
                cout << "cosx: " << cosx << endl;
            }
        }
        else if (x >= pi / 2 && x < pi) { // 2 четверть -
            double xCOS = x;
            if (xCOS > pi) {
                //xCOS = xCOS - pi;
                while (xCOS > pi) {
                    xCOS = xCOS - pi;
                }
                double cosx;
                cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
                cout << "cosx: " << -cosx << endl;
            }
            else {
                double cosx;
                cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
                cout << "cosx: " << -cosx << endl;
            }
        }
        else if (x >= pi && x < 1.5 * pi) { // 3 четверть -
            double xCOS = x;
            if (xCOS > pi) {
                //xCOS = xCOS - pi;
                while (xCOS > pi) {
                    xCOS = xCOS - pi;
                }
                double cosx;
                cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
                cout << "cosx: " << -cosx << endl;
            }
            else {
                double cosx;
                cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
                cout << "cosx: " << -cosx << endl;
            }
        }
        else if (x >= 1.5 * pi && x < 2 * pi) { // 4 четверть +
            double xCOS = x;
            if (xCOS > pi) {
                //xCOS = xCOS - pi;
                while (xCOS > pi) {
                    xCOS = xCOS - 2*pi;
                }
                double cosx;
                cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
                cout << "cosx: " << cosx << endl;
            }
            else {
                double cosx;
                cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
                cout << "cosx: " << cosx << endl;
            }
        }

        

        //// cosx - 0

        /*
        double angX = 180 / pi * x;
        if (angX > 180) {
            angX = angX - 180;
        }
        sinx = (4 * angX * (180 - angX )) / (40500 - angX * (180 - angX));
        */
        //x > pi ? x = x - pi : cout << 101;

        
        
        //cosx = 0;
        //cout << "cosx: " << cosx << endl << "sinx: " << sinx / 2 << endl << "lnx: " << lnx << endl;

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
    else if (x < 0) {
        
    }


    


    return 0;
}
