//Лабораторная , задача . Выполнена: Воднев Д. И.

/*
    Вычислить сумму четных чисел на промежутке от 1 до числа,
введенного пользователем:

4.2 Без использования цикла.
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введите число\n";
    double a;
    cin >> a;
    
start:
    int i = 1;
    if (i % 2 == 0) {
        cout << "Все чётные числа, в промежутке от 1 до " << a << ":\n";
    }
    i++;
    if (i == a) {
        goto end;
    }
    goto start;
end:
    return 0;
}
