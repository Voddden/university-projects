// Лабораторная 4, задача 12. Выполнена: 

/*
Написать функцию, которая будет удалять дубликаты элементов из массива.
Входные параметры: массив, длина массива. Выходные параметры: новый массив, новый размер.
*/

using namespace std;
#include <iostream>
#include <iomanip>

// функция удаления дубликатов и вывода нового массива
void deleteDuplicate(int n, double* arr) {
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j > -1; --j) {
            if (arr[i] == arr[j]) {
                for (int z = i; z < n - 1; ++z) {
                    arr[z] = arr[z + 1];
                }
                --n;
                --i;
                break;
            }
        }
    }
    cout << "\n\nПреобразованный массив:\n\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << "  ";
    }
    cout << "\n\nРазмер преобразованного массива: " << n << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Программа удаляет дубликаты элементов из заданного массива\n";
    cout << "Введите размер массива\n";
    cin >> n;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n;
    }
    double* arr = new double[n];
    cout << "Введите элементы массива\n";
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
        while (cin.fail() || cin.peek() != '\n' || arr[i] != (long long)arr[i]) {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "Введены некорректные данные, попробуйте ещё раз:\n";
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    }
    deleteDuplicate(n, arr);
    // освобождение памяти
    delete[] arr;
    return 0;
}