//Лабораторная 2, задача 13. Выполнена: 

/*
    Сможет ли шар радиуса R пройти в ромбообразное отверстие
    стороной P и острым углом Q?
*/

#include <iostream>
using namespace std;
#include <cmath>

int main() {
    setlocale(LC_ALL, "Rus");
    double R, P, Q, r; // r - радиус ромба
    cout << "Введите радиус шара, сторону ромба и острый угол ромба в радианах\n";
    cin >> R >> P >> Q;
    double S, Per; // площадь и периметр ромба
    Per = P * 4;
    S = sin(Q) * P * P;
    r = (2 * S) / Per;
    if (fabs(R - r) < 0.0000001 || R <= r) {
        cout << "Шар сможет пройти\n";
    }
    else {
        cout << "Шар не сможет пройти\n";
    }
    return 0;
}
