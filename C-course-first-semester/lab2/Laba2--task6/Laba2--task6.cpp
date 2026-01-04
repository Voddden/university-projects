//Лабораторная 2, задача 6. Выполнена: 

/*
    Составить программу используя переключатель switch:
*/

#include <iostream>
using namespace std;
#include <cmath>

int main() {
    setlocale(LC_ALL, "Rus");
    double a, b, c;
    int N; 
    cout << "Введите переменные в таком порядке: N, a, b, c\n";
    cin >> N >> a >> b >> c;
    switch (N) {
        case 2:
            cout << "Y равно " << b * c - a * a << endl;
            break;
        case 56: 
            cout << "Y равно " << b * c << endl;
            break;
        case 7:
        default:
            cout << "Y равно " << pow(a + b, 3) << endl;

            cout << "Y равно " << a * a + c << endl;
            break;
        case 3:
            cout << "Y равно " << a - b * c << endl;
            break;

            //break;
    }
    return 0;
}