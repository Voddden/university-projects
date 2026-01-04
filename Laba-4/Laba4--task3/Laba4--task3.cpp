//Лабораторная 4, задача 3 Выполнена: Воднев Д. И.

/*
Память для массива выделить динамически. 
Выполнить в соответствии с номером варианта индивидуальное задание и
вывести на экран исходные данные и полученный результат.

вариант 5. Задан массив размером NхN, состоящий из 0 и 1. 
Повернуть элементы массива на 90° по часовой стрелке.
*/

using namespace std;
#include <iostream>
#include <ctime>

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int n;

    cout << "Введите размерность массива\n";
    cin >> n;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n;
    }

    int** arr = new int* [n];
    for (int t = 0; t < n; ++t) {
        arr[t] = new int[n];
    }

    cout << "Введите значения элементов массива (0 или 1)\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "arr[" << i << "]" << "[" << j << "] = ";
            cin >> arr[i][j];
            while (cin.fail() || cin.peek() != '\n' || arr[i][j] != (long long)arr[i][j] || (arr[i][j] != 0 && arr[i][j] != 1)) {
                cin.clear();
                cin.ignore(99999, '\n');
                cout << "Введены некорректные данные, попробуйте ещё раз:\n";
                cout << "arr[" << i << "]" << "[" << j << "] = ";
                cin >> arr[i][j];
            }
        }
    }

    cout << endl << "Изначальный массив:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;   

    // поворот массива
    for (int r = 0; r < n; r++) {
        for (int c = r; c < n; c++) {
            swap(arr[r][c], arr[c][r]);
        }
    }
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n / 2; c++) {
            swap(arr[r][c], arr[r][n - c - 1]);
        }
    }
    //
    cout << "Повёрнутый на 90° по часовой стрелке массив:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    delete[] arr;
    return 0;
}