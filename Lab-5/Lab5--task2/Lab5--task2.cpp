// Лабораторная 5, задача 2 Выполнена: Воднев Д. И.

using namespace std;
#include<iostream>
#include<cmath>
#include<ctime>
#include<Windows.h>

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    HINSTANCE load;
    load = LoadLibrary(L"D:/С++/Laba5/StaticLib/Debug/DynamicLib.dll"); // помещение модуля библиотеки в память процессора
    typedef int (*Account) (int*, int, double); //тип указателя на функцию
    Account account;
    account = (Account)GetProcAddress(load, "account"); //получение адресов функций

    int size, i = 0;
    double one_third, two_third;

    cout << "Введите размер массива:\n";
    cin >> size;
    while (cin.fail() || cin.peek() != '\n' || size != (long long)size || size <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> size;
    }

    int* arr = new int[size];
    //cout << "Введите целочисленные элементы массива: \n";
    cout << "Массив заполняется случайными элементами:\n";
    for (int i = 0; i < size; i++) {
        //cout << "[" << i + 1 << "]" << " ";
        //arr[i] = input();
        //cin >> arr[i];
        arr[i] = rand() % 50 - 30;
    }

    cout << "\nНаш массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    one_third = (double)size / 3.;
    //if (one_third > (int)one_third + 0.5) one_third += 1;
    two_third = 2. * (double)size / 3.;
    //if (two_third > (int)two_third + 0.5) two_third += 1;

    cout << "\nЭлементы удовлетворяющие условию:\n";
    i = account(arr, i, one_third);
    account(arr, i, two_third);
    cout << endl;

    FreeLibrary(load);
    delete[] arr;
    return 0;
}