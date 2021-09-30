//Лабораторная 2, задача 8. Выполнена: Воднев Д. И.

/*
    Вычислить значение y в зависимости от выбранной функции f(x),
    аргумент определяется из поставленного условия. Возможные значения
    функции f(x): 2x, x^3, x/3 (выбор осуществляется используя оператор switch).
    Предусмотреть вывод сообщений, показывающих, при каком условии и с какой
    функцией производились вычисления y.

    Мой номер в журнале 5
*/

#include <iostream>
using namespace std;
#include <cmath>

int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите 1, 2 или 3 чтобы выбрать функцию\n 1 --- 2x \n 2 --- x^3 \n 3 --- x/3\n";
    cin >> n;

    //const double exp = 2.718281828459;
    switch (n) { 
        case 1: 
            double a, b, z, x, y;
            cout << "Введите переменные a, b, z в этом же порядке\n";
            cin >> a >> b >> z;
            if (z < -1) {
                x = (-z) / 3;

                y = a * (2 * x) - log(x + 2.5) + b * (exp(x) - exp(-x));
                cout << "Значение выражения a * 2x - ln(x + 2.5) + b(e^x - e^(-x)) равно " << y << endl;
            }
            if (z >= -1) {
                x = fabs(z);

                y = a * (2 * x) - log(x + 2.5) + b * (exp(x) - exp(-x));
                cout << "Значение выражения a * 2x - ln(x + 2.5) + b(e^x - e^(-x)) равно " << y << endl;
            }
            break;
        case 2:
            double a, b, z, x, y;
            cout << "Введите переменные a, b, z в этом же порядке\n";
            cin >> a >> b >> z;
            if (z < -1) {
                x = (-z) / 3;

                y = a * (pow(x, 3)) - log(x + 2.5) + b * (exp(x) - exp(-x));
                cout << "Значение выражения a * 2x - ln(x + 2.5) + b(e^x - e^(-x)) равно " << y << endl;
            }
            if (z >= -1) {
                x = fabs(z);

                y = a * (pow(x , 3) - log(x + 2.5) + b * (exp(x) - exp(-x));
                cout << "Значение выражения a * 2x - ln(x + 2.5) + b(e^x - e^(-x)) равно " << y << endl;
            }
            break;
        case 3:
            double a, b, z, x, y;
            cout << "Введите переменные a, b, z в этом же порядке\n";
            cin >> a >> b >> z;
            if (z < -1) {
                x = (-z) / 3;

                y = a * 2 * x - log(x + 2.5) + b * (exp(x) - exp(-x));
                cout << "Значение выражения a * 2x - ln(x + 2.5) + b(e^x - e^(-x)) равно " << y << endl;
            }
            if (z >= -1) {
                x = fabs(z);

                y = a * 2 * x - log(x + 2.5) + b * (exp(x) - exp(-x));
                cout << "Значение выражения a * 2x - ln(x + 2.5) + b(e^x - e^(-x)) равно " << y << endl;
            }
            break;
    }
    return 0;
}
