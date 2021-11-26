//Лабораторная 5, задача 3 Выполнена: Воднев Д. И.

/*
Дан двумерный динамический массив целых чисел А размерностью n x k .
Размерность массива (n = 5, k = 6) ввести с клавиатуры. Значения элементов массива
ввести с клавиатуры. 

Создать динамический массив из элементов, расположенных на
главной диагонали матрицы и имеющих четное значение. 

Вычислить произведение
элементов динамического массива.

Созданный массив и результат произведения вывести на экран.
Использовать функции.
*/

using namespace std;
#include <iostream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "Введите размерность 2-мерного массива:\n";
    int n, k;
    cin >> n >> k;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0 || k != (long long)k || k <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n >> k;
    }
    int** A = new int* [n];
    for (int t = 0; t < n; ++t) {
        A[t] = new int[n];
    }

    cout << "Введите значения элементов массива\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << "A[" << i << "]" << "[" << j << "] = ";
            cin >> A[i][j];
            while (cin.fail() || cin.peek() != '\n' || A[i][j] != (long long)A[i][j]) {
                cin.clear();
                cin.ignore(99999, '\n');
                cout << "Введены некорректные данные, попробуйте ещё раз:\n";
                cout << "A[" << i << "]" << "[" << j << "] = ";
                cin >> A[i][j];
            }
        }
    }

    int d = 0; // d - число элементов массива arr

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i == j) {
                if (A[i][j] % 2 == 0) {
                    ++d;
                }
            }
        }
    }

    cout << "Матрица А:\n\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << setw(5) << A[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;

    //cout << d;
    int* arr = new int [d];
    int f = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i == j && A[i][j] % 2 == 0) {
                arr[f] = A[i][j];
                ++f;
            }
        }
    }

    cout << "Массив четных элементов главной диагонали матрицы:\n\n";
    for (int i = 0; i < d; ++i) {
        cout << setw(5) << arr[i] << " ";
    }
    cout << endl << endl;

    int s = 1;
    for (int i = 0; i < d; ++i) {
        s *= arr[i];
    }

    cout << "Произведение элементов этого массива:\n\n" << setw(5) << s << endl;
    
    return 0;
}