//Лабораторная 4, задача 9 Выполнена: Воднев Д. И.

/*
    В качестве входных данных поступают две целочисленные
    матрицы A и B, которые имеют размер N и соответственно. Требуется найти
    произведение матриц A*B. Выделение памяти через функции языка С.
*/

using namespace std;
#include <iostream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Программа расчитывает произведение матриц A и B, которые имеют размерности m x n и n x k соответственно\n\n";
    int m, n, k;
    // матрицы целочисленные
    cout << "---Введите m\n";
    cin >> m;
    while (cin.fail() || cin.peek() != '\n' || m != (long long)m || m <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> m;
    }

    cout << "---Введите n\n";
    cin >> n;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n;
    }

    cout << "Введите k\n";
    cin >> k;
    while (cin.fail() || cin.peek() != '\n' || k != (long long)k || k <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> k;
    }


    // начало работы с массивами
    int** arrA; // матрица А
    int** arrB; // матрица В
    int** arrAB; // матрица А*В
    arrA = (int**)malloc(m * sizeof(int*));
    arrB = (int**)malloc(n * sizeof(int*));
    arrAB = (int**)malloc(m * sizeof(int*));
    for (long long int i = 0; i < m; ++i) {
        arrB[i] = (int*)malloc(n * sizeof(int));
    }
    for (long long int i = 0; i < n; ++i) {
        arrB[i] = (int*)malloc(k * sizeof(int));
    }
    for (long long int i = 0; i < m; ++i) {
        arrAB[i] = (int*)malloc(k * sizeof(int));
    }

    /*
    cout << "Введите элементы первого массива (" << m << " x " << n << "):\n";
    for (long long int i = 0; i < m; ++i) {
        for (long long int j = 0; j < n; ++j) {
            //arr1[i][j] = inputArrInt(i, j);
            cin >> arr1[i][j];
            while (cin.fail() || cin.peek() != '\n' || arr1[i][j] != (long long)arr1[i][j]) {
                cin.clear();
                cin.ignore(99999, '\n');
                cout << "Введены некорректные данные, попробуйте ещё раз:\n";
                cin >> arr1[i][j];
            }
        }
    }
    */

    cout << "---Введите значения элементов матрицы А\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "A(" << i + 1 << ";" << j + 1 << ") = ";
            cin >> arrA[i][j];
            while (cin.fail() || cin.peek() != '\n' || arrA[i][j] != (long long)arrA[i][j]) {
                cin.clear();
                cin.ignore(99999, '\n');
                cout << "Введены некорректные данные, попробуйте ещё раз:\n";
                cout << "A(" << i + 1 << ";" << j + 1 << ") = ";
                cin >> arrA[i][j];
            }
        }
    }

    cout << "---Введите значения элементов матрицы B\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << "B(" << i + 1 << ";" << j + 1 << ") = ";
            cin >> arrB[i][j];
            while (cin.fail() || cin.peek() != '\n' || arrB[i][j] != (long long)arrB[i][j]) {
                cin.clear();
                cin.ignore(99999, '\n');
                cout << "Введены некорректные данные, попробуйте ещё раз:\n";
                cout << "B(" << i + 1 << ";" << j + 1 << ") = ";
                cin >> arrB[i][j];
            }
        }
    }

    // перемножение матриц
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int r = 0; r < n; ++r) {
                arrAB[i][j] = 0;
                arrAB[i][j] += arrA[i][r] * arrB[r][j];
            }
        }
    }

    cout << "\nПеремножение матриц A и B равно:\n\n";

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << setw(8) << left << arrAB[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; ++i) {
        free(arrA[i]);
    }
    free(arrA);

    for (int i = 0; i < n; ++i) {
        free(arrB[i]);
    }
    free(arrB);

    for (int i = 0; i < m; ++i) {
        free(arrAB[i]);
    }
    free(arrAB);

    return 0;
}