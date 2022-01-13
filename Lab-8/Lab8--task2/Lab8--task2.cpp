//Лабораторная 8, задача 2 Выполнена: Воднев Д. И.

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
        cout << "---Введите номер " << i + 1 << "-го рейса: ";  
        arr[i].number = inputInt();
    }
    
    for (int i = 0; i < number_of_flights; ++i) {
        cout << "---Введите время вылета " << i + 1 << "-го рейса: ";
        cin >> arr[i].time;
    }

    for (int i = 0; i < number_of_flights; ++i) {
        cout << "---Введите пункт назначения " << i + 1 << "-го рейса: ";
        cin >> arr[i].destination;
    }

    for (int i = 0; i < number_of_flights; ++i) {
        cout << "---Введите тип самолёта " << i + 1 << "-го рейса: ";
        cin >> arr[i].planeType;
    }

    ////// вывод структуры
    cout << "\nНомера рейсов:\n";
    for (int i = 0; i < number_of_flights; ++i) {
        cout << arr[i].number << endl;
    }
    cout << "\nВремя вылета рейсов:\n";
    for (int i = 0; i < number_of_flights; ++i) {
        cout << arr[i].time << endl;
    }
    cout << "\nПункты назначения:\n";
    for (int i = 0; i < number_of_flights; ++i) {
        cout << arr[i].destination << endl;
    }
    cout << "\nТипы самолётов:\n";
    for (int i = 0; i < number_of_flights; ++i) {
        cout << arr[i].planeType << endl;
    }

    return 0;
}