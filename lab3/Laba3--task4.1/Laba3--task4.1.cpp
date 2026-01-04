//Лабораторная , задача  Выполнена: 

/*
    Вычислить сумму четных чисел на промежутке от 1 до числа,
    введенного пользователем:
    4.1 С использованием цикла;
*/

using namespace std;
#include <iostream>

int main() {
    setlocale(LC_ALL, "Rus");
    while (true) {
        // ввод численных данных
        cout << "---Программа вычислит сумму чётных чисел от 1 до вашего числа. Введите число: ";
        double a;
        cin >> a;
        if (cin.fail()) { // проверка на ввод символов
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Неправильный ввод данных\n";
            continue;
        }
        else if (a > 1e6 && a != (long long)a) {
            cout << "Неправильный ввод данных!\n";
            continue;
        }
        else {
            // начало программы 
            if (a <= 0) {
                a = -a;
                goto point;
            }
            else {
                point:
                long long sum = 0;
                for (int i = 1; i <= a; ++i) {
                    if (i % 2 == 0) {
                        sum = sum + i;
                    }
                }
                cout << "Сумма равна:\n" << sum << endl;
            }
            // конец программы
            continue;
        }
    }
    return 0;
}