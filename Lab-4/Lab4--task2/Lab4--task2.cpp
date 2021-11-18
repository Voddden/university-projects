//Лабораторная 4, задача 2 Выполнена: Воднев Д. И.

/*

*/

using namespace std;
#include <iostream>
#include <time.h>
#include <cmath>

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int n, m;
    cout << "Введите кол-во строк матрицы\n";
    cin >> n;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n;
    }
    cout << "Введите кол-во столбцов матрицы\n";
    cin >> m;
    while (cin.fail() || cin.peek() != '\n' || m != (long long)m || m <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> m;
    }
    int** arr = new int* [n];
    for (int t = 0; t < n; ++t) {
        arr[t] = new int[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % 10 + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    long long sum = 0, pro = 1;
    for (int q = 0; q < min(n, m); ++q) {
        sum += arr[q][q];
        //pro *= arr[q][(n - 1) - q]; много багов
    }
    cout << "Сумма элементов главной диагонали равна " << sum << endl;
    cout << "Произведение элементов побочной диагонали равно " << pro << endl;
    delete[] arr;

    return 0;
}