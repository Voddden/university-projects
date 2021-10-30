//Лабораторная 4, задача 5 Выполнена: Воднев Д. И.

/*
    
*/

using namespace std;
#include <iostream>

double average_center(double a, double b, double c, double d, double e);
double average_right(double a, double c, double d, double e);
//int isLocalMinimum_top(int a, int b, int d, int e);
//int isLocalMinimum_left(int a, int b, int c, int e);
//int isLocalMinimum_bottom(int a, int b, int c, int d);

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

    double** arr = new double* [n];
    for (int t = 0; t < n; ++t) {
        arr[t] = new double[m];
    }

    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % 10 + 1;
        }
    }
    */

    cout << "Введите значения элементов массива\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "arr[" << i << "]" << "[" << j << "] = ";
            cin >> arr[i][j];
            while (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(99999, '\n');
                cout << "Введены некорректные данные, попробуйте ещё раз:\n";
                cout << "arr[" << i << "]" << "[" << j << "] = ";
                cin >> arr[i][j];
            }
        }
    }

    cout << "Изначальная матрица:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;

    // начало алгоритма сглаживания
    
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            arr[i][j] = average_center(arr[i][j], arr[i][j + 1], arr[i - 1][j], arr[i][j - 1], arr[i + 1][j]);
        }
    }

    for (int i = 1; i < n - 1; ++i) {
        arr[i][m-1] = average_right(arr[i][m - 1], arr[i - 1][m - 1], arr[i][m - 2], arr[i + 1][m - 1]);
    }

    // конец алгоритма сглаживания

    cout << "Сглаженная матрица:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    delete[] arr;
    return 0;
}

double average_center(double a, double b, double c, double d, double e) {
    return (b + c + d + e) / 4;
}


double average_right(double a, double c, double d, double e) {
    return (c + d + e) / 3;
}
/*
int isLocalMinimum_top(int a, int b, int d, int e) {
    if (a < b && a < d && a < e) {
        return 1;
    }
    else {
        return 0;
    }
}

int isLocalMinimum_left(int a, int b, int c, int e) {
    if (a < b && a < c && a < e) {
        return 1;
    }
    else {
        return 0;
    }
}

int isLocalMinimum_bottom(int a, int b, int c, int d) {
    if (a < b && a < c && a < d) {
        return 1;
    }
    else {
        return 0;
    }
}
*/