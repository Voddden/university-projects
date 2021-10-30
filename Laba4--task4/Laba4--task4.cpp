//Лабораторная 4, задача 4 Выполнена: Воднев Д. И.

/*
    Подсчитать количество локальных минимумов заданной матрицы
*/

using namespace std;
#include <iostream>

int isLocalMinimum_center(int a, int b, int c, int d, int e);
int isLocalMinimum_right(int a, int c, int d, int e);
int isLocalMinimum_top(int a, int b, int d, int e);
int isLocalMinimum_left(int a, int b, int c, int e);
int isLocalMinimum_bottom(int a, int b, int c, int d);

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
            while (cin.fail() || cin.peek() != '\n' || arr[i][j] != (long long)arr[i][j]) {
                cin.clear();
                cin.ignore(99999, '\n');
                cout << "Введены некорректные данные, попробуйте ещё раз:\n";
                cout << "arr[" << i << "]" << "[" << j << "] = ";
                cin >> arr[i][j];
            }
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

    int sum_center = 0;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            sum_center += isLocalMinimum_center(arr[i][j], arr[i][j + 1], arr[i - 1][j], arr[i][j - 1], arr[i + 1][j]);
        }
    }
    //cout << "CENTER--Кол-во локальных минимумов равно: " << sum_center << endl;

    int sum_right = 0;
    for (int i = 1; i < n - 1; ++i) {
        sum_right += isLocalMinimum_right(arr[i][m - 1], arr[i - 1][m - 1], arr[i][m - 2], arr[i + 1][m - 1]);
    }
    //cout << "RIGHT--Кол-во локальных минимумов равно: " << sum_right << endl;

    int sum_top = 0;
    for (int j = 1; j < m - 1; ++j) {
        sum_top += isLocalMinimum_top(arr[0][j], arr[0][j + 1], arr[0][j - 1], arr[1][j]);
    }
    //cout << "TOP--Кол-во локальных минимумов равно: " << sum_top << endl;

    int sum_left = 0;
    for (int i = 1; i < n - 1; ++i) {
        sum_left += isLocalMinimum_left(arr[i][0], arr[i][1], arr[i - 1][0], arr[i + 1][0]);
    }
    //cout << "LEFT--Кол-во локальных минимумов равно: " << sum_left << endl;

    int sum_bottom = 0;
    for (int j = 1; j < m - 1; ++j) {
        sum_bottom += isLocalMinimum_bottom(arr[n - 1][j], arr[n - 1][j + 1], arr[n - 2][j], arr[n - 1][j - 1]);
    }
    //cout << "BOTTOM--Кол-во локальных минимумов равно: " << sum_bottom << endl;

    int sum_1 = 0;
    if (arr[0][0] < arr[0][1] && arr[0][0] < arr[1][0]) {
        ++sum_1;
    }
    //cout << "SUM1--Кол-во локальных минимумов равно: " << sum_1 << endl;

    int sum_2 = 0;
    if (arr[0][m - 1] < arr[0][m - 2] && arr[0][m - 1] < arr[1][m - 1]) {
        ++sum_2;
    }
    //cout << "SUM2--Кол-во локальных минимумов равно: " << sum_2 << endl;

    int sum_3 = 0;
    if (arr[n-1][0] < arr[n-1][1] && arr[n-1][0] < arr[n-2][0]) {
        ++sum_3;
    }
    //cout << "SUM3--Кол-во локальных минимумов равно: " << sum_3 << endl;

    int sum_4 = 0;
    if (arr[n-1][m-1] < arr[n-2][m-1] && arr[n-1][m-1] < arr[n-1][m-2]) {
        ++sum_4;
    }
    //cout << "SUM4--Кол-во локальных минимумов равно: " << sum_4 << endl;
    
    sum = sum_center + sum_right + sum_top + sum_left + sum_bottom + sum_1 + sum_2 + sum_3 + sum_4;
    cout << "Кол-во локальных минимумов равно: " << sum << endl;
    // конец алгоритма

    delete[] arr;
    return 0;
}

int isLocalMinimum_center(int a, int b, int c, int d, int e) {
    if (a < b && a < c && a < d && a < e) {
        return 1;
    }
    else {
        return 0;
    }
}

int isLocalMinimum_right(int a, int c, int d, int e) {
    if (a < c && a < d && a < e) {
        return 1;
    }
    else {
        return 0;
    }
}

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