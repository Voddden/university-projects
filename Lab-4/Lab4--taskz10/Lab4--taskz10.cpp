// Лабораторная 4, задача 10. Выполнена: Воднев Д. И.

/*
Построить магический квадрат любого порядка, используя любой алгоритм.
Выделение памяти через функции языка С. 
*/

using namespace std;
#include <iostream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "ru");
    int n, i, j, m = 1, t, y, x, buff;
    cout << "Программа строит магический квадрат заданного порядка\n";
    cout << "Введите порядок магического квадрата\n";
    cin >> n;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n;
    }
    int** magicSquare;
    magicSquare = (int**)calloc(n, sizeof(*magicSquare));
    for (int i = 0; i < n; ++i) {
        magicSquare[i] = (int*)calloc(n, sizeof(*magicSquare[i]));
    }
    if (n == 2) {
        cout << "Магического квадрата с такой размерностью не существует\n";
    }
    else if (n == 1) {
        cout << "\nМагический квадрат:\n\n" << setw(3) << 1 << '\n';
    }
    else if (n % 2 == 1) {
        i = 0;
        j = static_cast<int>(n / 2); // Высчитывание среднего элемента
        magicSquare[i][j] = 1; // Средний элемент верхней строки равен 1
        // Заполнение магического квадрата
        for (int k = 2; k < n * n + 1; ++k) {
            if (i - 1 >= 0 && j - 1 >= 0 && magicSquare[i - 1][j - 1] == 0) {
                magicSquare[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && magicSquare[i - 1][j - 1] != 0) {
                magicSquare[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                magicSquare[n - 1][j - 1] = k;
                i = n - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                magicSquare[i - 1][n - 1] = k;
                --i;
                j = n - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && magicSquare[n - 1][n - 1] != 0) {
                magicSquare[i + 1][j] = k;
                ++i;
            }
        }
    }
    else if (n % 4 == 0) {
        int** secondarySquare;
        secondarySquare = (int**)malloc(n * sizeof(int*));
        for (long long int i = 0; i < n; ++i) {
            secondarySquare[i] = (int*)malloc(n * sizeof(int));
        }
        // Заполнение от 0 до n^2 магического квадрата
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                magicSquare[i][j] = m;
                ++m;
            }
        }
        m = n * n;
        // Заполнение вспомогательного квадрата
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                secondarySquare[i][j] = m;
                --m;
            }
        }
        // Длина одного маленького квадрата
        m = (n / 4) * (n / 4);
        t = 1;
        i = 0;
        j = 0;
        // Перестановка элементов из вспомогательного квадрата в магический по диагоналям
        while (t < m + 1) {
            ++t;
            y = i;
            x = j;
            while (y < i + 4) {
                magicSquare[y][x] = secondarySquare[y][x];
                ++y;
                ++x;
            }
            y = i + 3;
            x = j;
            while (x < i + 4) {
                magicSquare[y][x] = secondarySquare[y][x];
                --y;
                ++x;
            }
            if (j + 4 < n) {
                j += 4;
            }
            else if (j + 4 >= n) {
                j = 0;
                i += 4;
            }
        }
        for (long long int i = 0; i < n; ++i) {
            free(secondarySquare[i]);
        }
        free(secondarySquare);
    }
    else {
        int length4 = n / 2;
        int** _arr1;
        _arr1 = (int**)calloc(length4, sizeof(*_arr1));
        int** _arr2;
        _arr2 = (int**)calloc(length4, sizeof(*_arr2));
        int** _arr3;
        _arr3 = (int**)calloc(length4, sizeof(*_arr3));
        int** _arr4;
        _arr4 = (int**)calloc(length4, sizeof(*_arr4));

        for (int i = 0; i < length4; ++i) {
            _arr1[i] = (int*)calloc(length4, sizeof(*_arr1[i]));
        }
        for (int i = 0; i < length4; ++i) {
            _arr2[i] = (int*)calloc(length4, sizeof(*_arr2[i]));
        }
        for (int i = 0; i < length4; ++i) {
            _arr3[i] = (int*)calloc(length4, sizeof(*_arr3[i]));
        }
        for (int i = 0; i < length4; ++i) {
            _arr4[i] = (int*)calloc(length4, sizeof(*_arr4[i]));
        }
        // Высчитывание максимальных значений в маленьких квадратах
        int pred1 = n * n / 4;
        int pred2 = n * n / 2;
        int pred3 = n * n / 4 * 3;
        int pred4 = n * n;
        int k = 1;
        i = 0;
        j = static_cast<int>(length4 / 2);
        _arr1[i][j] = 1;
        ++k;
        // иницализация 1-го маленького квадрата
        while (k < pred1 + 1) {
            if (i - 1 > -1 && j - 1 > -1 && _arr1[i - 1][j - 1] == 0) {
                _arr1[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 > -1 && j - 1 > -1 && _arr1[i - 1][j - 1] != 0 && i + 1 < length4) {
                _arr1[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                _arr1[length4 - 1][j - 1] = k;
                i = length4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                _arr1[i - 1][length4 - 1] = k;
                --i;
                j = length4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && _arr1[length4 - 1][length4 - 1] != 0 && i + 1 < length4) {
                _arr1[i + 1][j] = k;
                ++i;
            }
            ++k;
        }
        i = 0;
        j = static_cast<int>(length4 / 2);
        _arr4[i][j] = k;
        ++k;
        // инициализация 2-го маленького квадрата
        while (k < pred2 + 1) {
            if (i - 1 > -1 && j - 1 >= 0 && _arr4[i - 1][j - 1] == 0) {
                _arr4[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && _arr4[i - 1][j - 1] != 0 && i + 1 < length4) {
                _arr4[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                _arr4[length4 - 1][j - 1] = k;
                i = length4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                _arr4[i - 1][length4 - 1] = k;
                --i;
                j = length4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && _arr4[length4 - 1][length4 - 1] != 0 && i + 1 < length4) {
                _arr4[i + 1][j] = k;
                ++i;
            }
            ++k;
        }
        i = 0;
        j = static_cast<int>(length4 / 2);
        _arr2[i][j] = k;
        ++k;
        // инициализация 2-го маленького квадрата
        while (k < pred3 + 1) {
            if (i - 1 >= 0 && j - 1 >= 0 && _arr2[i - 1][j - 1] == 0) {
                _arr2[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && _arr2[i - 1][j - 1] != 0 && i + 1 < length4) {
                _arr2[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                _arr2[length4 - 1][j - 1] = k;
                i = length4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                _arr2[i - 1][length4 - 1] = k;
                --i;
                j = length4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && _arr2[length4 - 1][length4 - 1] != 0 && i + 1 < length4) {
                _arr2[i + 1][j] = k;
                ++i;
            }
            ++k;
        }
        i = 0;
        j = static_cast<int>(length4 / 2);
        _arr3[i][j] = k;
        ++k;
        // инициализация 3-го маленького квадрата
        while (k < pred4 + 1) {
            if (i - 1 >= 0 && j - 1 >= 0 && _arr3[i - 1][j - 1] == 0) {
                _arr3[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && _arr3[i - 1][j - 1] != 0 && i + 1 < length4) {
                _arr3[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                _arr3[length4 - 1][j - 1] = k;
                i = length4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                _arr3[i - 1][length4 - 1] = k;
                --i;
                j = length4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && _arr3[length4 - 1][length4 - 1] != 0 && i + 1 < length4) {
                _arr3[i + 1][j] = k;
                ++i;
            }
            ++k;
        }
        // Меняются местами два крайних числа слева
        buff = _arr1[0][0];
        _arr1[0][0] = _arr3[0][0];
        _arr3[0][0] = buff;
        // Отсчёт со второй строки
        y = 1;
        // Замена на втором столбике
        while (y < length4 - 1) {
            buff = _arr1[y][1];
            _arr1[y][1] = _arr3[y][1];
            _arr3[y][1] = buff;
            ++y;
        }
        // Расчёт сколько столбиков сдвинется
        k = (n - 2) / 4 - 1; 
        // Сдвигание столбиков
        if (k > 0) {
            while (k > 0) {
                for (int i = 0; i < length4; ++i) {
                    buff = _arr1[i][length4 - k];
                    _arr1[i][length4 - k] = _arr3[i][length4 - k];
                    _arr3[i][length4 - k] = buff;
                    buff = _arr2[i][k - 1];
                    _arr2[i][k - 1] = _arr4[i][k - 1];
                    _arr4[i][k - 1] = buff;
                }
                --k;
            }
        }
        // Из маленьких 4-х квадратов собирается сам магический квадрат
        for (int i = 0; i < length4; ++i) {
            for (int j = 0; j < length4; ++j) {
                magicSquare[i][j] = _arr1[i][j];
                magicSquare[i][j + length4] = _arr2[i][j];
                magicSquare[i + length4][j] = _arr3[i][j];
                magicSquare[i + length4][j + length4] = _arr4[i][j];
            }
        }
        // освобождение памяти
        for (long long int i = 0; i < n; ++i) {
            free(_arr1[i]);
        }
        free(_arr1);
        for (long long int i = 0; i < n; ++i) {
            free(_arr2[i]);
        }
        free(_arr2);
        for (long long int i = 0; i < n; ++i) {
            free(_arr3[i]);
        }
        free(_arr3);
        for (long long int i = 0; i < n; ++i) {
            free(_arr4[i]);
        }
        free(_arr4);
    }
    // Вывод квадрата
    if (n > 2) {
        cout << "\nМагический квадрат:\n\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (n < 100) {
                    cout << setw(4) << magicSquare[i][j] << " ";
                }
                else {
                    cout << setw(10) << magicSquare[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
    for (long long int i = 0; i < n; ++i) {
        free(magicSquare[i]);
    }
    free(magicSquare);
    return 0;
}