//Лабораторная 8, задача 1 Выполнена: Воднев Д. И.

using namespace std;
#include <iostream>
#include <string>

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

//void BubbleSort(int size, call arr[]) {
//    int temp;
//    for (int i = 0; i < size - 1; i++) {
//        for (int j = 0; j < size - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}

struct call {
    string date;
    string city;
    string time;
    int code;
    int tarif;
    int phoneNumber;
};

int main() {
    setlocale(LC_ALL, "ru");
    int number_of_calls;

    cout << "---Введите кол-во звонков: ";
    number_of_calls = inputInt();
    call* arr = new call[number_of_calls];
    
    //cout << "Введите дату разговора";
    for (int i = 0; i < number_of_calls; ++i) {
        cout << "---Введите дату разговора " << i + 1 << "-го звонка: ";
        cin >> arr[i].date;
    }

    for (int i = 0; i < number_of_calls; ++i) {
        cout << "---Введите город " << i + 1 << "-го звонка: ";
        cin >> arr[i].city;
    }

    for (int i = 0; i < number_of_calls; ++i) {
        cout << "---Введите время " << i + 1 << "-го звонка: ";
        cin >> arr[i].time;
    }

    for (int i = 0; i < number_of_calls; ++i) {
        cout << "---Введите код " << i + 1 << "-го звонка: ";
        arr[i].code = inputInt();
    }

    for (int i = 0; i < number_of_calls; ++i) {
        cout << "---Введите тариф " << i + 1 << "-го звонка: ";
        arr[i].tarif = inputInt();
    }

    for (int i = 0; i < number_of_calls; ++i) {
        cout << "---Введите номер " << i + 1 << "-го звонка: ";
        arr[i].phoneNumber = inputInt();
    }

    //// вывод структуры
    //cout << "Изначальные данные:\n";
    cout << "\nДаты звонков:\n";
    for (int i = 0; i < number_of_calls; ++i) {
        cout << arr[i].date << endl;
    }
    cout << "\nГорода звонков:\n";
    for (int i = 0; i < number_of_calls; ++i) {
        cout << arr[i].city << endl;
    }
    cout << "\nВремя звонков:\n";
    for (int i = 0; i < number_of_calls; ++i) {
        cout << arr[i].time << endl;
    }
    cout << "\nКоды звонков:\n";
    for (int i = 0; i < number_of_calls; ++i) {
        cout << arr[i].code << endl;
    }
    cout << "\nТарифы звонков:\n";
    for (int i = 0; i < number_of_calls; ++i) {
        cout << arr[i].tarif << endl;
    }
    cout << "\nНомера телефонов:\n";
    for (int i = 0; i < number_of_calls; ++i) {
        cout << arr[i].phoneNumber << endl;
    }
    
    //cout << "Введите город (существующий в структуре) у к-го хотите узнать общее время разговоров";

    return 0;
}