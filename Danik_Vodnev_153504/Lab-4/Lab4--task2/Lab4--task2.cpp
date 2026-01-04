//Лабораторная 4, задача 2 Выполнена: Воднев Д. И.

/*
Инициализировать при объявлении статический двумерный массив целых чисел размером NхM.
Выполнить в соответствии с номером варианта индивидуальное
задание и вывести на экран исходные данные и полученный результат.

5 вариант: Определить сумму элементов, расположенных на главной диагонали матрицы,
и произведение элементов, расположенных на побочной диагонали матрицы.
*/

using namespace std;
#include <iostream>
#include <time.h>
#include <cmath>

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    const int n = 3, m = 3;

    //cout << "Введите кол-во строк матрицы\n";
    //cin >> n;
    //while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
    //    cin.clear();
    //    cin.ignore(99999, '\n');
    //    cout << "Введены некорректные данные, попробуйте ещё раз:\n";
    //    cin >> n;
    //}

    //cout << "Введите кол-во столбцов матрицы\n";
    //cin >> m;
    //while (cin.fail() || cin.peek() != '\n' || m != (long long)m || m <= 0) {
    //    cin.clear();
    //    cin.ignore(99999, '\n');
    //    cout << "Введены некорректные данные, попробуйте ещё раз:\n";
    //    cin >> m;
    //}

    if (n == 1 || m == 1) {
        cout << "У вектора нет диагоналей\n";
    }
    else {
        //int** arr = new int* [n];
        //for (int t = 0; t < n; ++t) {
        //    arr[t] = new int[m];
        //}
        int arr[n][m]{};

        cout << "Введите значения элементов матрицы\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << "A" << i + 1 << j + 1 << " = ";
                cin >> arr[i][j];
                while (cin.fail() || cin.peek() != '\n' || arr[i][j] != (long long)arr[i][j]) {
                    cin.clear();
                    cin.ignore(99999, '\n');
                    cout << "Введены некорректные данные, попробуйте ещё раз:\n";
                    cout << "A" << i + 1 << j + 1 << " = ";
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

        long long sum = 0, pro = 1;
        for (int q = 0; q < min(n, m); ++q) {
            sum += arr[q][q];
        }

        for (int i = 0, j = m - 1; i >= 0 && j >= 0; ++i, --j) {
            pro *= arr[i][j];
        }

        cout << "Сумма элементов главной диагонали равна " << sum << endl;
        cout << "Произведение элементов побочной диагонали равно " << pro << endl;

        //delete[] arr;
    }

    return 0;
}