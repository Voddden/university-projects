//Лабораторная 3, задача 4.2 Выполнена: 

/*
    Вычислить сумму четных чисел на промежутке от 1 до числа,
введенного пользователем:

4.2 Без использования цикла.
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Эта программа вычисляет сумму чётных чисел на промежутке от 1 до заданного вами числа\n";
    cout << "---Введите число ";
    double a, sum = 0;
    cin >> a;

    while (cin.fail() || cin.get() != '\n') {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "---Вы ввели некорректное значение, попробуйте ещё раз: ";
        cin >> a;
    }

    if (a < 0) a = -a;
    int i = 1;

start:
    if (i > a) goto end;
    
    if (i % 2 == 0) {
        sum = sum + i;
    }
    i++;
    goto start;
end:
    cout << "Сумма равна " << sum << endl;
    return 0;
}