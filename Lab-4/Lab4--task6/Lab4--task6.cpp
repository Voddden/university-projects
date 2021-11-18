//Лабораторная 4, задача 6 Выполнена: Воднев Д. И.

/*
    Для заданной матрицы А размерности N*M построить матрицу В такого же размера,
    элементы которой обладают следующим свойством:
    элемент B[i,j] равен максимальному из элементов матрицы А,
    расположенных левее и выше позиции (і,j), включая позицию (і,ј).
    При этом считается, что позиция(1,1) - верхняя левая позиция матрицы
*/

using namespace std;
#include <iostream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int n, m;
    cout << "Введите кол-во строк матрицы A\n";
    cin >> n;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n;
    }
    cout << "Введите кол-во столбцов матрицы A\n";
    cin >> m;
    while (cin.fail() || cin.peek() != '\n' || m != (long long)m || m <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> m;
    }
    int** arr = new int* [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }

    cout << "Введите значения элементов матрицы А\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "A" << "(" << i + 1 << ";" << j + 1 << ") = ";
            cin >> arr[i][j];
            while (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(99999, '\n');
                cout << "Введены некорректные данные, попробуйте ещё раз:\n";
                cout << "A" << "(" << i + 1 << ";" << j + 1 << ") = ";
                cin >> arr[i][j];
            }
        }
    }

    cout << "Матрица А:\n"; // изначальная матрица
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(8) << left << arr[i][j] << " ";
        }
        cout << "\n";
    }
    // начало создания матрицы В

    int** arr_temp = new int* [n];
    for (int i = 0; i < n; ++i) {
        arr_temp[i] = new int[m];
    }

    int max_number, x, y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x = i;
            y = j;
            max_number = 0;
            for (int i = 0; i <= x; ++i) {
                for (int j = 0; j <= y; ++j) {
                    if (arr[i][j] > max_number) {
                        max_number = arr[i][j];
                    }
                }
            }
            arr_temp[i][j] = max_number;
        }
    }
    // конец создания матрицы В

    cout << "Матрица В:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(8) << left << arr_temp[i][j] << " ";
        }
        cout << endl;
    }

    // освобождение памяти
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    for (int i = 0; i < n; ++i) {
        delete[] arr_temp[i];
    }
    delete[] arr_temp;

    return 0;
}