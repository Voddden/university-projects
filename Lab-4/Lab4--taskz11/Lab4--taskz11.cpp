//Лабораторная 4, задача 11 Выполнена: Воднев Д. И.

/*
    Дан трёхмерный динамический массив размером n^3 целых
    неотрицательных чисел. Необходимо определить диагональ с наибольшей
    суммой чисел. Для обхода диагоналей нельзя использовать вложенные
    циклы.
*/

using namespace std;
#include <iostream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "Rus");
    ios_base::sync_with_stdio(0);
    long long size;
    long double diag1 = 0, diag2 = 0, diag3 = 0, diag4 = 0, max1 = 0, max2 = 0, max = 0;
    cout << "Введите размерность массива\n";
    cin >> size;
    while (cin.fail() || cin.peek() != '\n' || size != (long long)size || size <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> size;
    }
    int*** arr = new int** [size];
    for (int i = 0; i < size; ++i) {
        arr[i] = new int* [size];
        for (int j = 0; j < size; ++j) {

            arr[i][j] = new int[size];
        }
    }
    cout << "Введите элементы масссива\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                cout << "arr[" << i << "]" << "[" << j << "]" << "[" << k << "] = ";
                cin >> arr[i][j][k];
                while (cin.fail() || cin.peek() != '\n' || arr[i][j][k] != (long long)arr[i][j][k] || arr[i][j][k] < 0) {
                    cin.clear();
                    cin.ignore(99999, '\n');
                    cout << "Введены некорректные данные, попробуйте ещё раз:\n";
                    cout << "arr[" << i << "]" << "[" << j << "]" << "[" << k << "] = ";
                    cin >> arr[i][j][k];
                }
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        diag1 += arr[i][i][i];
    }
    for (int i = 0; i < size; ++i) {
        diag2 += arr[i][long long(size) - i - 1][long long(size) - i - 1];
    }
    for (int i = 0; i < size; ++i) {
        diag3 += arr[i][long long(size) - i - 1][i];
    }
    for (int i = 0; i < size; ++i) {
        diag4 += arr[i][i][long long(size) - i - 1];
    }
    max1 = (diag1 > diag2) ? diag1 : diag2;
    max2 = (diag3 > diag4) ? diag3 : diag4;
    max = (max1 > max2) ? max1 : max2;
    cout << "Диагональ с наибольшей суммой чисел:\n";
    cout << max << endl;
    return 0;
}