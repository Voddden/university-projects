// Лабораторная 7, задача 1(вариант 5). Выполнена: Воднев Д. И.

/* 
    перевод из 13-чной системы счисления в 3-чную 
*/

using namespace std;
#include <iostream>
#include <string>

int num13_to_num10(string num13) {
    int* arr = new int[num13.length()];
    //for (int i = 0; i < num13.length(); ++i) {
    //    arr[i] = 0;
    //}
    int razryad = 0;
    for (int i = 0; i < num13.length(); ++i) {
        if (num13[i] == 'a') {
            num13[i] = 10;
        }
        else if (num13[i] == 'b') {
            num13[i] = 11;
        }
        else if (num13[i] == 'c') {
            num13[i] = 12;
        }
        else {
            arr[i] = num13[i];
        }
        
    }
    return 0;
}

int num10_to_num3(int num10) {
    return 0;
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << "---Введите число в 13-чной системе счисления: ";
    string num13;
    getline(cin, num13);
    int num10 = num13_to_num10(num13);
    cout << "Число в 10-чной СС: " << num10 << endl;
    //int num3 = num10_to_num3(num10);
    //cout << "Число в 3-чной системе счисления: " << num3 << endl;
    return 0;
}