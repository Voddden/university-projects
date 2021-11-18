// Лабораторная 4, задача 14. Выполнена: Воднев Д. И.

/* 
На вход подаётся поле для игры в "сапёр" размером n*m символов, где символ "." означает
пустое место, а символ "*" - бомбу. Требуется дополнить это поле числами , как в оригинальной игре.
Выделение памяти через функции языка С. 
*/

using namespace std;
#include <iostream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "ru");
    long long n, m;
    short k;
    cout << "Программа создаёт двумерный массив n x m для игры в сапёра\n";

    cout << "---Введите n\n";
    cin >> n;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n;
    }

    cout << "---Введите m\n";
    cin >> m;
    while (cin.fail() || cin.peek() != '\n' || m != (long long)m || m <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> m;
    }
    // объявление массива
    char** arr = (char**)malloc(n * sizeof(char*));
    for (long long int i = 0; i < n; ++i) {
        arr[i] = (char*)malloc(m * sizeof(char));
    }

    cout << "---Введите игровое поле для игры в сапёра ('*' - бомба, '.' - пустая клетка)\n";
    for (long long int i = 0; i < n; ++i) {
        for (long long int j = 0; j < m; ++j) {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
            while (cin.fail() || cin.peek() != '\n' || arr[i][j] != '.' && arr[i][j] != '*') {
                cin.clear();
                cin.ignore(99999, '\n');
                cout << "Введены некорректные данные, попробуйте ещё раз:\n";
                cout << "arr[" << i << "][" << j << "] = ";
                cin >> arr[i][j];
            }
        }
    }

    cout << "\nИсходное игровое поле:\n";
    for (long long int i = 0; i < n; ++i) {
        for (long long int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // Замена точек на числа (кол-во бомб вокруг клетки)
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            k = 0;
            if (arr[i][j] == '.') {
                if (i - 1 > -1 && arr[i - 1][j] == '*') ++k;
                if (i + 1 < n && arr[i + 1][j] == '*') ++k;
                if (j - 1 > -1 && arr[i][j - 1] == '*') ++k;
                if (j + 1 < m && arr[i][j + 1] == '*') ++k;
                if (i - 1 > -1 && j - 1 > -1 && arr[i - 1][j - 1] == '*') ++k;
                if (i + 1 < n && j - 1 > -1 && arr[i + 1][j - 1] == '*') ++k;
                if (i - 1 > -1 && j + 1 < m && arr[i - 1][j + 1] == '*') ++k;
                if (i + 1 < n && j + 1 < m && arr[i + 1][j + 1] == '*') ++k;
                arr[i][j] = k + '0';
            }
        }
    }

    cout << "\nДополненное игровое поле:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }

        cout << '\n';
    }
    // освобождение памяти
    for (long long int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}