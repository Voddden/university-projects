//Лабораторная 8, задача 2 Выполнена: Воднев Д. И.

/*
5. В справочной аэропорта хранится расписание вылета самолетов
на следующие сутки. Для каждого рейса указаны: номер рейса, тип
самолета, пункт назначения, время вылета. Вывести все номера рейсов, типы
самолетов и времена вылета для заданного пункта назначения в порядке
возрастания времени вылета.
*/

using namespace std;
#include <iostream>

int inputInt() {
    int value;
    cin >> value;
    while (cin.fail() || cin.peek() != '\n' || value != (long long)value || value <= 0) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Введены некорректные данные, попробуйте ещё раз:\n";
        cin >> value;
    }
    return value;
}

struct flight {
    int number;
    string time;
    string destination;
    string planeType;
};

int main() {
    setlocale(LC_ALL, "ru");
    cout << "---Введите кол-во полётов: ";
    int number_of_flights = inputInt();
    flight* arr = new flight[number_of_flights];
    for (int i = 0; i < number_of_flights; ++i) {

    }

    return 0;
}