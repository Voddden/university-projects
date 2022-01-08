//Лабораторная 7, задача 3 Выполнена: Воднев Д. И.

/*
* Осуществить сложение чисел. Разработать функции для
выполнения операции сложения. Предусмотреть ввод положительных и
отрицательных чисел.
5. Найдите сумму двоичных чисел, заданных в естественной
форме. Сложение выполните в дополнительном коде. Ответ
выразите в прямом коде.
*/

using namespace std;
#include <iostream>
#include <string>
#include <bitset>

bool num1_is_positive = true, num2_is_positive = true;

int inputInt() {
    int value;
    cin >> value;
    while (cin.fail() || cin.peek() != '\n' || value != (long long)value || value > 127 || value < -127) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> value;
    }
    return value;
}

string to_dopCode(string str) {

    //string str = input.to_string;
    int count = 7;
    if (str[count] == '0') { // добавление единицы 
        str[count] = '1';
    }
    else if (str[count] == '1') {
        while (str[count] != '0') {
            str[count] = '0';
            --count;
        }
        str[count] = '1';
    }
    return str;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int num1_cc10 = -127, num2_cc10 = 0;
    cout << "---Введите 1-ое число в естественной форме: ";
    num1_cc10 = inputInt();
    cout << "---Введите 2-ое число в естественной форме: ";
    num2_cc10 = inputInt();

    if (num1_cc10 < 0) {
        num1_is_positive = false;
        num1_cc10 = -num1_cc10;
    }
    if (num2_cc10 < 0) {
        num2_is_positive = false;
        num2_cc10 = -num2_cc10;
    }
    //// 1
    bitset<8> num1_priamCode(num1_cc10);
    if (num1_is_positive == false) {
        num1_priamCode.flip(7);
    }
    //cout << num1_priamCode;
    bitset<8> num1_obrCode(num1_priamCode);
    for (int i = 0; i < 7; ++i) {
        num1_obrCode.flip(i);
    }
    string num1_obrCode_string = num1_obrCode.to_string();
    string num1_dopCode_string = to_dopCode(num1_obrCode_string);
    bitset<8> num1_dopCode(num1_dopCode_string);
    //// 2
    bitset<8> num2_priamCode(num2_cc10);
    if (num2_is_positive == false) {
        num2_priamCode.flip(7);
    }
    //cout << num2_priamCode;
    bitset<8> num2_obrCode(num2_priamCode);
    for (int i = 0; i < 7; ++i) {
        num2_obrCode.flip(i);
    }
    string num2_obrCode_string = num2_obrCode.to_string();
    string num2_dopCode_string = to_dopCode(num2_obrCode_string);
    bitset<8> num2_dopCode(num2_dopCode_string);
    //cout << "Доп. код 1-го числа: " << num1_dopCode << endl;
    //cout << "Доп. код 2-го числа: " << num2_dopCode << endl;
    // сложение
    bitset<8> sum_bitset(num1_dopCode.to_ulong() + num2_dopCode.to_ulong());
    
    //cout << "Сумма:\n" << sum_bitset << endl;
    // перевод в прямой код
    sum_bitset.flip(0);
    for (int i = 0; i < 7; ++i)
        sum_bitset.flip(i);

    cout << "Ответ:\n" << sum_bitset;
    return 0;
}