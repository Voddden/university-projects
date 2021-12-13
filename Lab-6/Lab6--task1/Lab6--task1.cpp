//Лабораторная 6, задача 1 Выполнена: Воднев Д. И.

/*
В строке, состоящей из групп нулей и единиц, подсчитать
количество единиц в группах с нечетным количеством символов.
*/

using namespace std;
#include <iostream>
#include <iomanip>
#include <cstring>

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введите строку:\n";
    const int max_str = 81;
    const int max_arr = 30;
    char str[max_str];
    cin.get(str, max_str);

    //cout << "Ваша строка:\n" << str << "\n";
    // ---- #1 кол-во групп
    int groups = 1;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == ' ') ++groups;
    }
    cout << "Кол-во групп: " << groups;
    // --


    int m = groups;
    int n = max_arr;
    int** arr = new int* [m];
    for (int i = 0; i < m; ++i) {
        arr[i] = new int[n];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 3;
        }
    }

    // ---- заполнение массива arr группами
    int o = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; str[o] != ' ' && str[o] != '\0'; ++j) {
            arr[i][j] = str[o] - 48;
            ++o;
        }
        ++o;
    }
    // --
    
    // ---- создание массива из количеств элементов массива arr

    int* arr1 = new int[groups];
    for (int i = 0; i < groups; ++i) {
        arr1[i] = 0;
    }
    int y = 0;
    for (int i = 0; i < m; ++i) {
        y = 0;
        while (arr[i][y] != 3) {
            ++arr1[i];
            ++y;
        }
    }

    // перебор массива arr1: подсчёт кол-ва нечётных элементов (групп)
    int q = 0; // счётчик кол-ва нечётных групп
    for (int i = 0; i < groups; ++i) {
        if (arr1[i] % 2 == 1) ++q;
    }


    cout << "\nКол-во элементов групп: (arr1)";
    for (int i = 0; i < groups; ++i) {
        cout << arr1[i] << " ";
    }
    cout << "\nКол-во нечётных групп: (q)" << q;

    // --

    // ---- создание массива из групп с нечётным кол-вом символов (arr2)
    

    //int** arr = new int* [m];
    //for (int i = 0; i < m; ++i) {
    //    arr[i] = new int[n];
    //}

    int** arr2 = new int* [q];
    for (int i = 0; i < q; ++i) {
        arr2[i] = new int[max_arr];
    }

    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < max_arr; ++j) {
            arr2[i][j] = 3;
        }
    }

    for (int i = 0; i < groups; ++i) {
        if (arr1[i] % 2 == 1) 
            arr2[i] = arr[i];
    }

    // ---- подсчёт кол-ва единиц в нечётных группах

    int* arr3 = new int[q];
    for (int i = 0; i < q; ++i) {
        arr3[i] = 0;
    }
    int e = 0;
    for (int i = 0; i < q; ++i) {
        //e = 0;
        //while (arr2[i][e] != 3) {
        //    if (arr2[i][e] == 1) ++arr3[i];
        //    ++e;
        //}

        for (int j = 0; arr2[i][j] != 3; ++j) {
            if (arr2[i][j] % 2 == 1) ++arr3[i];
        }
    }

    // --

    // --
    cout << "\nМассив arr:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(2) << arr[i][j] << " ";
        }
        cout << endl;
    }


    cout << "Массив нечётного кол-ва групп (arr2):\n";
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < max_arr; ++j) {
            cout << setw(2) << arr2[i][j] << " ";
        }
        cout << endl;
    }


    cout << "\narr3:\n";
    for (int i = 0; i < q; ++i) {
        cout << setw(2) << arr3[i] << " ";
    }
    return 0;
}
