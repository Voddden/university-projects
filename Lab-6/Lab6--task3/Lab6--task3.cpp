//Лабораторная 6, задача 3 Выполнена: Воднев Д. И.

/*
В массиве строк найти среднее значение длины строки. Строки,
длина которых больше среднего, – обрезать, меньше – добавить
пробелы. Полученный массив вывести на экран
*/

using namespace std;
#include <iostream>
#include <string>

int main() {
    cout << "---Enter number of strings: ";
    int x; // количество строк
    cin >> x;
    while (cin.fail() || cin.peek() != '\n' || x != (long long)x || x <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Incorrect data has been entered, please try again:\n";
        cin >> x;
    }

    cin.ignore(32767, '\n');
    string* arr = new string[x];
    cout << "---Enter the strings:\n";
    for (int i = 0; i < x; ++i) {
        cout << "string#" << i + 1 << ": ";
        getline(cin, arr[i]);
    }
    // --
    int average = 0;
    for (int i = 0; i < x; ++i) {
        average += arr[i].length();
    }
    average /= x;
    // --
    for (int i = 0; i < x; ++i) {
        arr[i].resize(average, ' ');
    }
    // --
    cout << "\nResult:\n";
    for (int i = 0; i < x; ++i) {
        cout << arr[i] << "\n";
    }

    //cout << average;
    delete[] arr;
    return 0;
}