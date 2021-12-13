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


    cout << "\nКол-во элементов групп: (temparr_1)";
    for (int i = 0; i < groups; ++i) {
        cout << temparr_1[i] << " ";
    }
    cout << "\nКол-во нечётных групп: (q)" << q;

    // --

    // ---- создание массива из групп с нечётным кол-вом символов (arr_2)
    

    //int** arr_1 = new int* [m];
    //for (int i = 0; i < m; ++i) {
    //    arr_1[i] = new int[n];
    //}

    int** arr_2 = new int* [q];
    for (int i = 0; i < q; ++i) {
        arr_2[i] = new int[max_arr];
    }

    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < max_arr; ++j) {
            arr_2[i][j] = 3;
        }
    }

    for (int i = 0; i < groups; ++i) {
        if (temparr_1[i] % 2 == 1) 
            arr_2[i] = arr_1[i];
    }

    // ---- подсчёт кол-ва единиц в нечётных группах

    int* temparr_2 = new int[q];
    for (int i = 0; i < q; ++i) {
        temparr_2[i] = 0;
    }
    int e = 0;
    for (int i = 0; i < q; ++i) {
        //e = 0;
        //while (arr_2[i][e] != 3) {
        //    if (arr_2[i][e] == 1) ++temparr_2[i];
        //    ++e;
        //}

        for (int j = 0; arr_2[i][j] != 3; ++j) {
            if (arr_2[i][j] % 2 == 1) ++temparr_2[i];
        }
    }

    // --

    // --
    cout << "\nМассив arr_1:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(2) << arr_1[i][j] << " ";
        }
        cout << endl;
    }


    cout << "Массив нечётного кол-ва групп (arr_2):\n";
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < max_arr; ++j) {
            cout << setw(2) << arr_2[i][j] << " ";
        }
        cout << endl;
    }


    cout << "\narr3:\n";
    for (int i = 0; i < q; ++i) {
        cout << setw(2) << temparr_2[i] << " ";
    }
    return 0;
}
