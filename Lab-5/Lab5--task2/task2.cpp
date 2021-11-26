//Лабораторная 5, задача 2 Выполнена: Воднев Д. И.

/*
Вариант 5:
Для заданного одномерного массива A из N элементов найти значение минимального
элемента массива и его номер. Рекурсивную функцию применять каждый раз отдельно
для каждой из половин массива. Рекурсивные вызовы заканчивать, когда останется
только один элемент.
*/

using namespace std;
#include <iostream>

long long inputInt();

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введите количество элементов в массиве\n";
    int n;
    n = inputInt();

    //cin >> n;
    //while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
    //    cin.clear();
    //    cin.ignore(99999, '\n');
    //    cout << "Введены некорректные данные, попробуйте ещё раз:\n";
    //    cin >> n;
    //}

    int* A = new int[n];

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        cout << "X[" << i << "] = ";
        cin >> A[i];
        while (cin.fail() || cin.peek() != '\n' || A[i] != (long long)A[i]) {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "Введены некорректные данные, попробуйте ещё раз:\n";
            cout << "A[" << i << "] = ";
            cin >> A[i];
        }
    }
    return 0;
}

long long inputInt() {
    long double value;
    cin >> value;
    // Удаление всех пробелов (если они есть) после первого числа, если оно было в потоке
    while (cin.peek() == ' ')
        cin.ignore(1, ' ');
    // Проверка состояния потока ввода, конца строки, области допустимых значений и экспоненты
    while (cin.fail() || cin.peek() != '\n' || value <= 0 || value != (long long)value) {
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin.clear(); // Включение потока ввода
        cin.ignore(3256, '\n'); // Очищение буфера потока ввода
        cin >> value;
        while (cin.peek() == ' ')
            cin.ignore(1, ' ');
    }
    return value;
}