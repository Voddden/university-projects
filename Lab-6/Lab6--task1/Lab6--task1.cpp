//Лабораторная 6, задача 1 Выполнена: Воднев Д. И.

/*
В строке, состоящей из групп нулей и единиц, подсчитать
количество единиц в группах с нечетным количеством символов.
*/

using namespace std;
#include <iostream>
#include <cstring>

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введите строку:\n";
    const int max = 10;
    char str[max];
    cin.get(str, max);

    //cout << "Ваша строка:\n" << str << "\n";
    // ---- #1 кол-во групп
    int groups = 1;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == ' ') ++groups;
    }
    cout << "Кол-во групп == " << groups;
    // --

    // ---- #2 кол-во элем-ов наибольшей группы
    
    // --
    int m = groups;
    int n = max;
    int** arr = new int* [m];
    for (int i = 0; i < m; ++i) {
        arr[i] = new int[n];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 0;
        }
    }
    // массив количества элементов каждой из групп

    const int arr1_x = groups;
    int arr1[arr1_x];
    for (int i = 0; i < groups; ++i) {
        arr1[i] = 0;
    }
    //
    int j = 0;
    for (int i = 0; i < groups; ++i) {
        while (str[j] != ' ') {
            arr[i][j] = str[j] - 48;
            ++j;
        }
        ++j;
    }
    
    //
    //cout << "\nМассив arr:\n";
    //for (int i = 0; i < m; ++i) {
    //    for (int j = 0; j < n; ++j) {
    //        cout << arr[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    return 0;
}
