//Лабораторная 6, задача 1 Выполнена: Воднев Д. И.

/*
В строке, состоящей из групп нулей и единиц, подсчитать
количество единиц в группах с нечетным количеством символов.
*/

using namespace std;
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введите строку:\n";
    const int max_str = 10;
    char str[max_str];
    cin.getline(str, max_str);
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] != '1' && str[i] != '0' && str[i] != ' ') {
            cout << "Введены некорректные данные\n";
            return 0;
        }
    }

    const int max_arr = 30;
    // ---- #1 кол-во групп
    int groups = 1;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == ' ') ++groups;
    }
    /*cout << "Кол-во групп: " << groups;*/
    // --

    int m = groups;
    int n = max_arr;
    int** arr_1 = new int* [m];
    for (int i = 0; i < m; ++i) {
        arr_1[i] = new int[n];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr_1[i][j] = 3;
        }
    }

    // ---- заполнение массива arr_1 группами
    int o = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; str[o] != ' ' && str[o] != '\0'; ++j) {
            arr_1[i][j] = str[o] - 48;
            ++o;
        }
        ++o;
    }
    // --
    
    // ---- создание массива из количеств элементов массива arr_1

    int* temparr_1 = new int[groups];
    for (int i = 0; i < groups; ++i) {
        temparr_1[i] = 0;
    }
    int y = 0;
    for (int i = 0; i < m; ++i) {
        y = 0;
        while (arr_1[i][y] != 3) {
            ++temparr_1[i];
            ++y;
        }
    }

    // перебор массива temparr_1: подсчёт кол-ва нечётных элементов (групп)
    int q = 0; // счётчик кол-ва нечётных групп
    for (int i = 0; i < groups; ++i) {
        if (temparr_1[i] % 2 == 1) ++q;
    }

    if (q == 0) {
        cout << "Групп с нечётным кол-вом элементов нет\n";
    }
    else {
    // ---- создание массива из групп с нечётным кол-вом символов (arr_2)

        int** arr_2 = new int* [q];
        for (int i = 0; i < q; ++i) {
            arr_2[i] = new int[max_arr];
        }

        for (int i = 0; i < q; ++i) {
            for (int j = 0; j < max_arr; ++j) {
                arr_2[i][j] = 3;
            }
        }
        int r = 0;
        for (int i = 0; i < groups; ++i) {
            if (temparr_1[i] % 2 == 1) {
                for (int j = 0; arr_1[i][j] != 3; ++j) {
                    arr_2[r][j] = arr_1[i][j];
                }
                ++r;
            }
        }

        // ---- подсчёт кол-ва единиц в нечётных группах

        int* temparr_2 = new int[q];
        for (int i = 0; i < q; ++i) {
            temparr_2[i] = 0;
        }
        int e = 0;
        for (int i = 0; i < q; ++i) {
            for (int j = 0; arr_2[i][j] != 3; ++j) {
                if (arr_2[i][j] % 2 == 1) 
                    ++temparr_2[i];
            }
        }

        // --

        cout << "Кол-во единиц в группах в нечётным кол-вом элементов:\n";
        for (int i = 0; i < q; ++i) {
            cout << setw(2) << temparr_2[i] << " ";
        }
        cout << endl;

        //arr_1 (m, n)
        for (int i = 0; i < m; ++i) {
            delete[] arr_1[i];
        }
        delete[] arr_1;

        //temparr_1 (groups)
        delete[] temparr_1;

        //arr_2 (q, max_arr)
        for (int i = 0; i < q; ++i) {
            delete[] arr_2[i];
        }
        delete[] arr_2;

        //temparr_2 (q)
        delete[] temparr_2;
    }
    return 0;
}