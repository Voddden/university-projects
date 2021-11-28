//Лабораторная 5, задача 6 Выполнена: Воднев Д. И.

/*
Пусть f(n) - наибольший нечетный делитель натурального числа n. По заданному
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).
*/

using namespace std;
#include <iostream>

int f(int n);
long long inputInt();

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "Введите число n\n";
    int n = inputInt();

    long long sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += f(i);
    }
    cout << "Сумма равна:\n" << sum << endl;

    return 0;
}

int f(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return n / i;
        }
    }
    return 1;
}

long long inputInt() {
    long double value;
    cin >> value;
    while (cin.peek() == ' ') cin.ignore(1, ' ');
    while (cin.fail() || cin.peek() != '\n' || value <= 0 || value != (long long)value) {
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin.clear();
        cin.ignore(3256, '\n');
        cin >> value;
        while (cin.peek() == ' ') cin.ignore(1, ' ');
    }
    return value;
}
