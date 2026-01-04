//Лабораторная 4, задача 15 Выполнена: Воднев Д. И.

/*
Таблица заполняется по следующему алгоритму:
В таблицу вносятся все натуральные числа по порядку. 1 становится в левую
верхнюю ячейку, затем выбирается самая левая незаполненная ячейка в
самой первой строке таблицы и заполняется. Затем, пока у последней
заполненной ячейки сосед слева существует и заполнен, опускаемся вниз и
заполняем очередную ячейку. Когда же не окажется соседа слева, то
начинается заполнение клеток справа налево. После того как будет заполнена
ячейка в первом столбце, После этого алгоритм заполнения повторятся.
Необходимо вывести строку и столбец в котором будет находится число,
введенное с клавиатуры.
*/

using namespace std;
#include <iostream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "Rus");
    ios_base::sync_with_stdio(0);

    long double n;
    long long sum = 1, size = 1, number = 1;

    cout << "Введите число\n";
    cin >> n;

    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> n;
    }


    for (int i = 1, sum2; sum < n; i += 2) {

        sum2 = sum;
        ++sum;

        if (n > sum2 && n < sum) {
            break;
        }

        size++;
    }

    int** arr = new int* [size];

    for (int i = 0; i < size; ++i) {
        arr[i] = new int[size];
    }

    int a, b, c = 1;

    arr[0][0] = number++;

    while (c < size) {
        b = c;
        a = 0;

        while (a < b) {
            arr[a][b] = number++;
            a++;
        }

        while (a == b || b >= 0) {
            arr[a][b] = number++;
            b--;
        }

        c++;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setw(5) << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[i][j] == n) {
                cout << "Число " << n << " находится в ячейке массива (" << i << ";" << j << ")\n";
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        delete arr[i];
    }

    delete[] arr;
    return 0;
}
