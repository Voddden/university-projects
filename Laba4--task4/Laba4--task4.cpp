//Лабораторная 4, задача 4 Выполнена: Воднев Д. И.

/*

*/

using namespace std;
#include <iostream>

//int isLocalMinimum(int a = arr[i][j], int b = arr[i][j + 1], int c = arr[i - 1][j], int d = arr[i][j - 1], int e = arr[i + 1][j])
int isLocalMinimum(int a, int b = 0, int c = 0, int d = 0, int e = 0) {
    if (a < b && a < c && a < d && a < c) {
        return 1;
    }
    else {
        return 0;
    }
}

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

    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;

    // начало алгоритма
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // перебор элементов для нахождения минимума
            if (i > 0 && i < n) {
                sum += isLocalMinimum(arr[i][j], arr[i][j + 1], arr[i - 1][j], arr[i][j - 1], arr[i + 1][j]);
            }
            else {
                cout << 1;
            }
            
        }
    }
    cout << "Сумма равна:\n" << sum;
    delete[] arr;
    return 0;
}