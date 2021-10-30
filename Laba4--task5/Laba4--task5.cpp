//Лабораторная 4, задача 5 Выполнена: Воднев Д. И.

/*
    
*/

using namespace std;
#include <iostream>
#include <iomanip>

double average_center(double b, double c, double d, double e);
double average_right(double c, double d, double e);
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
    for (int i = 0; i < n; ++i) {
        arr[i] = new double[m];
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

    cout << endl << "Изначальная матрица:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(3) << left << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;

    //// начало алгоритма сглаживания
    //center-start
    int n_center = n - 2;
    int m_center = m - 2;
    double** arr_center = new double* [n_center];
    for (int i = 0; i < n_center; ++i) {
        arr_center[i] = new double[m_center];
    }

    for (int i = 1; i <= n_center; ++i) {
        for (int j = 1; j <= m_center; ++j) {
            arr_center[i-1][j-1] = arr[i][j];
        }
    }
    cout << "---arr_center--- изначальный\n";
    for (int i = 0; i < n_center; ++i) {
        for (int j = 0; j < m_center; ++j) {
            cout << setw(3) << left << arr_center[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n_center; ++i) {
        for (int j = 0; j < m_center; ++j) {
            arr_center[i][j] = average_center(arr[i + 1][j + 2], arr[i][j + 1], arr[i + 1][j], arr[i + 2][j + 1]);
        }
    }

    cout << "---arr_center--- с новыми числами\n";
    for (int i = 0; i < n_center; ++i) {
        for (int j = 0; j < m_center; ++j) {
            cout << setw(3) << left << arr_center[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;

    //center-end


    //right-start
     
    int n_right = n - 2;
    double* arr_right = new double[n_right];

    for (int i = 1; i <= n_right; ++i) {
        arr_right[i - 1] = arr[i][m - 1];
    }
    cout << "---arr_right--- изначальный\n";
    for (int i = 0; i < n_right; ++i) {
        cout << setw(3) << left << arr_right[i] << " ";
    }
    cout << endl << endl;
    
    for (int i = 0; i < n_right; ++i) {
        arr_right[i] = average_right(arr[i][m - 1], arr[i + 1][m - 2], arr[i + 2][m - 1]);
    }
    cout << "---arr_right--- с новыми числами\n";
    for (int i = 0; i < n_right; ++i) {
        cout << setw(3) << left << arr_right[i] << " ";
    }
    cout << endl;
    //right-end

    /*
    for (int i = 1; i < n - 1; ++i) {
        arr[i][m-1] = average_right(arr[i][m - 1], arr[i - 1][m - 1], arr[i][m - 2], arr[i + 1][m - 1]);
    }
    */
    //// конец алгоритма сглаживания

    //cout << "Сглаженная матрица:\n";


    delete[] arr;
    return 0;
}

double average_center(double b, double c, double d, double e) {
    double result = (b + c + d + e) / 4;
    return result;
}


double average_right(double c, double d, double e) {
    double result = (c + d + e) / 3;
    return result;
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