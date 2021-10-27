//Лабораторная 3, задача 8 Выполнена: Воднев Д. И.

/*
    Числа Армстронга (названные в честь Майкла Ф. Армстронга
(Michael F. Armstrong)), их также называют самовлюбленными числами и
совершенными цифровыми инвариантами, – это числа, равные сумме своих
цифр, возведенных в степень, равную количеству цифр. Например, наименьшее
число Армстронга – 153, которое равно 1^3 + 5^3 + 3^3 . Напишите программу,
которая выводит все числа армстронга меньше 10^6.
*/

#include <iostream>
using namespace std;
#include <cmath>

int main() {
    setlocale(LC_ALL, "Rus");
    
    int n; // число цифр
    int num1, num2, num3, num4, num5, num6, num7;
    cout << "Все числа на промежутке от 1 до 10^6, равные сумме своих цифр, возведенных в степень, равную количеству цифр (числа Армстронга):\n";
    for (int i = 1; i <= 1000000; ++i) {
        n = 1;
        for (int iT = i; (iT /= 10) > 0; ++n) ;
        // n == число цифр
        switch (n) {
            case 1: // [1-9]
                //cout << i << endl;
                break; 
            case 2: // [10-99] 
                break; 
            case 3: // [100-999]
                num1 = i / 100;
                num2 = i / 10 % 10;
                num3 = i % 10;
                if (i == pow(num1, n) + pow(num2, n) + pow(num3, n)) {
                    cout << i << endl;
                }
                break;
            case 4: // [1000 - 9999]
                num1 = i / 1000;
                num2 = i / 100 % 10;
                num3 = i / 10 % 10;
                num4 = i % 10;
                if (i == pow(num1, n) + pow(num2, n) + pow(num3, n) + pow(num4, n)) {
                    cout << i << endl;
                }
                break;
            case 5: // [10 000 - 99 999]
                num1 = i / 10000;
                num2 = i / 1000 % 10;
                num3 = i / 100 % 10;
                num4 = i / 10 % 10;
                num5 = i % 10;
                if (i == pow(num1, n) + pow(num2, n) + pow(num3, n) + pow(num4, n) + pow(num5, n)) {
                    cout << i << endl;
                }
                break;
            case 6: // [100 000 - 999 999]
                num1 = i / 100000;
                num2 = i / 10000 % 10;
                num3 = i / 1000 % 10;
                num4 = i / 100 % 10;
                num5 = i / 10 % 10;
                num6 = i % 10;
                if (i == pow(num1, n) + pow(num2, n) + pow(num3, n) + pow(num4, n) + pow(num5, n) + pow(num6, n)) {
                    cout << i << endl;
                }
                break;
            case 7: // 1 000 000
                break;
        }
    }
    return 0;
}