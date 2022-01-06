// Лабораторная 7, задача 1(вариант 5). Выполнена: Воднев Д. И.

/*
    перевод из 13-чной системы счисления в 3-чную
*/

using namespace std;
#include <iostream>
#include <string>

int num13_to_num10(string num13) {
    int* arr = new int[num13.length()]; // массив цифр числа num13

    for (int i = 0; i < num13.length(); ++i) {
        if (num13[i] == 'a') {
            arr[i] = 10;
        }
        else if (num13[i] == 'b') {
            arr[i] = 11;
        }
        else if (num13[i] == 'c') {
            arr[i] = 12;
        }
        else {
            arr[i] = num13[i] - 48;
        }
    }

    int num10 = 0;
    int razryad = 0;
    for (int i = num13.length() - 1; i >= 0; --i) { // преобразование к 10-чной СС
        num10 = num10 + arr[i] * pow(13, razryad);
        ++razryad;
    }

    return num10;
}

int num10_to_num3(int num10) {
    int number_of_digits_in_num3 = 1;
    int num10_1 = num10;
    while (num10_1 / 3 > 0) {
        ++number_of_digits_in_num3;
        num10_1 = num10_1 / 3;
    }

    int* arr = new int[number_of_digits_in_num3]; // массив цифр num3 (задом наперед)
    for (int i = 0; i < number_of_digits_in_num3; ++i) {
        arr[i] = num10 % 3;
        num10 /= 3;
    }

    int c;
    for (int i = 0; i < (number_of_digits_in_num3 / 2); i++) { // переворачивание массива цифр num3
        c = arr[i];
        arr[i] = arr[number_of_digits_in_num3 - 1 - i];
        arr[number_of_digits_in_num3 - 1 - i] = c;
    }

    int num3 = 0;
    int razryad = number_of_digits_in_num3 - 1;
    for (int i = 0; i < number_of_digits_in_num3; ++i) { // перевод числа num3 из массивного представления в числовое
        num3 = num3 + arr[i] * pow(10, razryad);
        --razryad;
    }
    return num3;
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << "---Введите число в 13-чной системе счисления: ";
    string num13;
    getline(cin, num13);

    int num10 = num13_to_num10(num13);
    //cout << "Число в 10-чной СС: " << num10 << endl;
    int num3 = num10_to_num3(num10);
    cout << "Число в 3-чной системе счисления: " << num3 << endl;
    return 0;
}