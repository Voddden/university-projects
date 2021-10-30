//Лабораторная 4, задача 5 Выполнена: Воднев Д. И.

/*
    
*/

using namespace std;
#include <iostream>
#include <iomanip>

double average_center(double b, double c, double d, double e);
double average_right(double c, double d, double e);
double average_top(double b, double d, double e);
double average_left(double b, double c, double e);
double average_bottom(double b, double c, double d);

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

    for (int i = 0; i < n_center; ++i) {
        for (int j = 0; j < m_center; ++j) {
            arr_center[i][j] = average_center(arr[i + 1][j + 2], arr[i][j + 1], arr[i + 1][j], arr[i + 2][j + 1]);
        }
    }
    //center-end


    //right-start
    int n_right = n - 2;
    double* arr_right = new double[n_right];

    for (int i = 1; i <= n_right; ++i) {
        arr_right[i - 1] = arr[i][m - 1];
    }
    
    for (int i = 0; i < n_right; ++i) {
        arr_right[i] = average_right(arr[i][m - 1], arr[i + 1][m - 2], arr[i + 2][m - 1]);
    }
    //right-end


    //top-start
    int m_top = m - 2;
    double* arr_top = new double[m_top];

    for (int j = 1; j <= m_top; ++j) {
        arr_top[j - 1] = arr[0][j];
    }

    for (int j = 0; j < m_top; ++j) {
        arr_top[j] = average_top(arr[0][j + 2], arr[0][j], arr[1][j + 1]);
    }
    //top-end


    //left-start
    int n_left = n - 2;
    double* arr_left = new double[n_left];

    for (int i = 1; i <= n_left; ++i) {
        arr_left[i - 1] = arr[i][0];
    }

    for (int i = 0; i < n_left; ++i) {
        arr_left[i] = average_left(arr[i + 1][1], arr[i][0], arr[i + 2][0]);
    }
    //left-end


    //bottom-start
    int m_bottom = m - 2;
    double* arr_bottom = new double[m_bottom];

    for (int j = 1; j <= m_bottom; ++j) {
        arr_bottom[j - 1] = arr[n - 1][j];
    }

    for (int j = 0; j < m_bottom; ++j) {
        arr_bottom[j] = average_bottom(arr[n - 1][j + 2], arr[n - 2][j + 1], arr[n - 1][j]);
    }
    //bottom-end

    cout << "Сглаженная матрица:\n";

    arr[0][0] = (arr[0][1] + arr[1][0]) / 2; // точка 1
    arr[0][m - 1] = (arr[0][m - 2] + arr[1][m - 1]) / 2; // точка 2
    arr[n - 1][0] = (arr[n - 2][0] + arr[n - 1][1]) / 2; // точка 3
    arr[n - 1][m - 1] = (arr[n - 2][m - 1] + arr[n - 1][m - 2]) / 2; // точка 4

    for (int i = 1; i < m - 1; ++i) { // перенос центральных сглаженных чисел в основной массив
        for (int j = 1; j < n - 1; ++j) {
            arr[i][j] = arr_center[i - 1][j - 1];
        }
    }

    for (int i = 1; i < n - 1; ++i) { // перенос правых сглаженных чисел в осн. массив
        arr[i][m - 1] = arr_right[i - 1];
    }

    for (int j = 1; j < m - 1; ++j) { // перенос верхних сглаженных чисел в осн. массив
        arr[0][j] = arr_top[j - 1];
    }

    for (int i = 1; i < n - 1; ++i) { // перенос левых сглаженных чисел в осн. массив
        arr[i][0] = arr_left[i - 1];
    }

    for (int j = 1; j < m - 1; ++j) { // перенос нижних сглаженных чисел в осн. массив
        arr[n - 1][j] = arr_bottom[j - 1];
    }


    for (int i = 0; i < n; ++i) { // вывод основного массива на экран
        for (int j = 0; j < m; ++j) {
            cout << setw(3) << left << setprecision(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
    //// конец алгоритма сглаживания

    delete[] arr_center;
    delete[] arr_right;
    delete[] arr_top;
    delete[] arr_left;
    delete[] arr_bottom;
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

double average_top(double b, double d, double e) {
    double result = (b + d + e) / 3;
    return result;
}

double average_left(double b, double c, double e) {
    double result = (b + c + e) / 3;
    return result;
}

double average_bottom(double b, double c, double d) {
    double result = (b + c + d) / 3;
    return result;
}