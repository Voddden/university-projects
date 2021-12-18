//Лабораторная 6, задача 3 Выполнена: Воднев Д. И.

/*
В массиве строк найти среднее значение длины строки. Строки,
длина которых больше среднего, – обрезать, меньше – добавить
пробелы. Полученный массив вывести на экран
*/

using namespace std;
#include <iostream>
#include <string>

int main() {
    int x = 3;
    string s1 = "supr";
    string s2 = "supr";
    string s3 = "sup";
    
    
    
    //string** arr = new string* [x];
    //for (int i = 0; i < x; ++i) {
    //    arr[i] = new string[y];
    //}
    
    string* arr = new string[x];
    //for (int i = 0; i < x; ++i) {
    //    arr[i] = 
    //}
    arr[0] = s1;
    arr[1] = s2;
    arr[2] = s3;
    int average = (s1.length() + s2.length() + s3.length()) / x;


    for (int i = 0; i < x; ++i) {
        cout << arr[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < s3.length(); ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    delete[] arr;
    return 0;
}