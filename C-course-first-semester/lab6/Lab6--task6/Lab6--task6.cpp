//Лабораторная 6, задача 6 Выполнена: 

/*
Анаграммой слова называется любая перестановка всех букв слова.
Например, из слова SOLO можно получить 12 анаграмм: SOLO, LOSO,
OSLO, OLSO, OSOL, OLOS, SLOO, LSOO, OOLS, OOSL, LOOS, SOOL.
Напишите программу, которая выводит количество различных
анаграмм, которые могут получиться из этого слова.
*/

using namespace std;
#include <iostream>
#include <string>
#include <algorithm>

int fact(int N) {
    if (N == 1)
        return 1;
    else
        return N * fact(N - 1);
}

int main() {
    cout << "Enter the string: ";
    string s;
    getline(cin, s);
    if (s.length() > 14) {
        cout << "The string cannot contain more than 14 characters\n";
        return 0;
    }
        
    sort(s.begin(), s.end());
    //int q = 0; 
    //for (int i = 0; i < s.length(); ++i) {
    //    if (s[i] == s[i + 1]) 
    //        continue;
    //    ++q;
    //}

    int x = 0, y = 0, p = 1;
    for (int i = y; s[i]; i++) {
        if (s[i] == s[i + 1]) {
            x++;
        }
        else {
            y = x;
            x++;
            p = p * fact(x);
            x = 0;
        }
    }

    // q - количество уникальных букв
    cout << "Result: " << fact(s.length()) / p << endl;
    //cout << "Sorted string: " << s;
    return 0;
}