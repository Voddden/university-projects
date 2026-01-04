//Лабораторная 4, задача 8 Выполнена: Воднев Д. И.

/*
    Заменить нулями все элементы, которые находятся в ячейках
    между минимальным и максимальным элементами (не включая их).
    Изначально все элементы в массиве различные. Если после данного действия
    большая часть массива будет содержать нули, то удалить все нулевые
    элементы из массива (c сохранением порядка следования остальных
    элементов).
*/

using namespace std;
#include <iostream>
#include <ctime>

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    cout << "Массив заполняется случайными различными целыми элементами на промежутке [0;n)\n";
    cout << "---Введите количество элементов в массиве\n";
    long long n;
    cin >> n;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n;
    }
    long long buff, j, mini = -1, maxi = -1, min = n + 1, max = -1, k = 0;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        j = rand() % n;
        buff = arr[j];
        arr[j] = arr[i];
        arr[i] = buff;
    }
    cout << "\nИзначальный массив:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] > max) {
            maxi = i;
            max = arr[i];
        }
        if (arr[i] < min) {
            mini = i;
            min = arr[i];
        }
    }
    if (mini < maxi) {
        for (int i = mini + 1; i < maxi; ++i) {
            arr[i] = 0;
            ++k;
        }
    }
    else if (mini > maxi) {
        for (int i = mini - 1; i > maxi; --i) {
            arr[i] = 0;
            ++k;
        }
    }
    if (k + 1 > n / 2) {
        if (mini < maxi) {
            for (int i = mini; i < maxi; ++i) {
                arr[i] = arr[i + k + 1];
                --n;
            }
        }
        else if (mini > maxi) {
            for (int i = maxi + 1; i < mini + 1; ++i) {
                arr[i] = arr[i + k + 1];
                --n;
            }
        }
    }
    cout << "\n\nПреобразованный массив:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}