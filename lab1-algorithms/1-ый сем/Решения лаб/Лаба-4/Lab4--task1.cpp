//Лабораторная 4, задача 1 Выполнена: Воднев Д. И.

/*
	Ввести 1-мерный статический массив
	Вариант 5: вывести все неповторяющиеся элементы массива
*/

using namespace std;
#include <iostream>
#include <time.h>

int main() {
	setlocale(LC_ALL, "Rus");
	//cout << "Введите размерность массива\n";
	const int k = 6;
	/*cin >> k;*/
	//while (cin.fail() || cin.peek() != '\n' || k != (long long)k || k <= 0) {
	//	cin.clear();
	//	cin.ignore(99999, '\n');
	//	cout << "Введены некорректные данные, попробуйте ещё раз:\n";
	//	cin >> k;
	//}
	//int* arr = new int[k];
	int arr[k];
	cout << "Введите элементы массива:\n";
	for (int i = 0; i < k; ++i) {
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
		while (cin.fail() || cin.peek() != '\n' || arr[i] != (long long)arr[i]) {
			cin.clear();
			cin.ignore(99999, '\n');
			cout << "Введены некорректные данные, попробуйте ещё раз:\n" << "arr[" << i << "] = ";
			cin >> arr[i];
		}
	}
	/*
	//простой вывод массива
	cout << "Массив на " << k << " элементов:\n";
	for (int i = 0; i < k; ++i) {
		cout << arr[i] << " ";
	}
	*/
	// вывод всез неповторяющихся элементов
	cout << "Вывод всех неповторяющихся элементов:\n";
	for (int i = 0; i < k; ++i) {

		int currentValue = arr[i];
		bool hasEquals = false;

		for (int r = 0; r < k; ++r) {
			if (i == r) continue;
			if (currentValue == arr[r] && i != r) hasEquals = true;
		}
		if (!hasEquals) {
			cout << currentValue << " ";
		}
	}
	//delete[] arr;

	return 0;
}

