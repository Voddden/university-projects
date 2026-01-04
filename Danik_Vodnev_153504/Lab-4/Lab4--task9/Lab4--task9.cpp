// Лабораторная 4, задача 9. Выполнена: Скроба А.П.

/*В качестве входных данных поступают две целочисленные матрицы A и B,
которые имеют размер N и соответственно. Требуется найти произведение матриц A*B.
Выделение памяти через функции языка С.*/

using namespace std;
#include <iostream>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Программа расчитывает прроизведение двух матриц\n";

    int n;
    cout << "Введите размерность матриц:\n";
    cin >> n;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n;
    }
    int** arr = (int**)calloc(n, sizeof(int*));
    cout << "\nВведите значения элементов матрицы А" << endl;
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nМатрица А:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }

    cout << "\nВведите значения элементов матрицы В" << endl;
    int** ptr = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        ptr[i] = (int*)calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) {
            cin >> ptr[i][j];
        }
    }

    cout << "\nМатрица В:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ptr[i][j] << '\t';
        }
        cout << endl;
    }

    int** result = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        result[i] = (int*)calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int r = 0; r < n; r++)
                result[i][j] += arr[i][r] * ptr[r][j];
        }
    }

    cout << "\nПроизведение двух матриц:";
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << '\t';
        }
        cout << endl;
    }

    free(arr);
    free(ptr);
    free(result);
    return 0;
}