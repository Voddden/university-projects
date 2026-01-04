//Лабораторная 6, задача 2 Выполнена: 

/*
Вариант 5:
После каждого слова текста, оканчивающегося заданной
подстрокой, вставить указанный символ.
*/

using namespace std;
#include <iostream>
#include <string>

int main() {
    string s;
    string subs;
    char symbol;

    s = "Neque porro quisquam est qui doloram ipsum quia dolor sit amet, consectet, adipisci velituam";
    subs = "am";
    symbol = '*';

    //cout << "Enter the text:\n";
    //getline(cin, s);
    //cout << "Enter the substring: ";
    //getline(cin, subs);
    //cout << "Enter the symbol: ";
    //cin >> symbol;

    
    // --
    int q = 0; // q - кол-во повторяющихся подстрок subs в строке str
    for (int i = 0; i < s.length(); ++i) {
        if (s.find(subs, i) == s.find(subs, i - 1) || s.find(subs, i) > s.length())
            continue;
        ++q;
    }
    //cout << "Num of substrings: " << q << endl;
    int* arr = new int[q];
    // --
    int w = 0; // счётчик массива
    for (int i = 0; i < s.length(); ++i) {
        if (s.find(subs, i) == s.find(subs, i - 1) || s.find(subs, i) > s.length())
            continue;
        //cout << s.find(subs, i) << " ";
        arr[w] = s.find(subs, i);
        ++w;
    }
    
    //for (int i = 0; i < q; ++i) {
    //    cout << arr[i] << " ";
    //}
    // --
    int e = 0;
    for (int i = 0; i < q; ++i) {
        s.insert(arr[i] + subs.length() + e, 1, symbol);
        ++e;
    }
    // --
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == symbol && s[i + 1] != ' ' && s[i + 1] != '\0') {
            s.erase(i, 1);
        }
    }

    // --
    cout << endl<< s << endl;
    delete[] arr;
    return 0;
}