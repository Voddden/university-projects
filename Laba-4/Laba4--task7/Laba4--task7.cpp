//Лабораторная 4, задача 7 Выполнена: Воднев Д. И.

/*
    Дано натуральное число n. Требуется подсчитать количество цифр
числа и определить, какая цифра стоит в разряде с номером i (разряды
нумеруются с конца, т.е. разряд единиц имеет номер 0).
*/

using namespace std;
#include <iostream>

long long power(long long x, long long c) {
    if (c == 0) {
        return 1;
    }
    else {
        return x *= power(x, --c);
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "Введите число n:\n";
    long long n;
    cin >> n;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n;
    }

    long long k = 1; 
    while (n - n % power(10, k) != 0) ++k;
    // k == количество цифр в числе n
    long long* arr = new long long[k]; // массив цифр числа n

    for (long long i = 0; i < k; ++i) {
        arr[i] = n % 10;
        n /= 10;
    }
    cout << "Количество цифр в числе: " << k << endl;

    cout << "Введите разряд i:\n";
    long long i;
    cin >> i;
    while (cin.fail() || cin.peek() != '\n' || i != (long long)i || i < 0 || i > k - 1) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> i;
    }
    cout << "В этом разряде стоит цифра " << arr[i] << endl;
    
    delete[] arr;
    return 0;
}