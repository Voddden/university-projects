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

long long inputArr(int i, int Ai);

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введите количество элементов в массиве\n";
    int n;
    n = inputInt();

    int* A = new int[n];
    
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        A[i] = inputArr(i, A[i]);
    }
    // рекурсивная функция:

    //
    return 0;
}

long long inputInt() {
    long double value;
    cin >> value;
    while (cin.peek() == ' ') cin.ignore(1, ' ');
    while (cin.fail() || cin.peek() != '\n' || value <= 0 || value != (long long)value) {
        cin.clear();
        cin.ignore(3256, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> value;
        while (cin.peek() == ' ') cin.ignore(1, ' ');
    }
    return value;
}

long long inputArr(int i, int Ai) {
    cout << "X[" << i << "] = ";
    cin >> Ai;
    while (cin.fail() || cin.peek() != '\n' || Ai != (long long)Ai) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cout << "A[" << i << "] = ";
        cin >> Ai;
    }
    return Ai;
}