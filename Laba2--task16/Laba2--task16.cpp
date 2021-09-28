//Лабораторная 2, задача 16. Выполнена: Воднев Д. И.

/*
    Введены два числа. Выведите их НОД и НОК.
*/

/*
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    return 0;
}
*/



#include <iostream>
using namespace std;
int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int main() {
    int n, m = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m = gcd(m, a);
    }
    cout << m;
    return 0;
}