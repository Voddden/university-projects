//Лабjраторная работа 5. Задание 2. Выполнено: Воднев Д. И.

using namespace std;
#include <iostream>
#include <Windows.h>

int main() {
	setlocale(LC_ALL, "ru");
	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");

	typedef int(*input)();
	input Input;
	Input = (input)GetProcAddress(load, "input");

	typedef int(*multiplyOfElements)(int*, int, int);
	multiplyOfElements MultiplyOfElements;
	MultiplyOfElements = (multiplyOfElements)GetProcAddress(load, "multiplyOfElements");

	cout << "Введите размер массива " << endl;
	int size = Input();
	int* array = new int[size];

	cout << "Введите элементы массива " << endl;
	for (int i = 0; i < size; i++)
	{
		array[i] = Input();
	}

	int elementsMultiply = MultiplyOfElements(array, size - 1, size / 2) * MultiplyOfElements(array, size / 2 - 1, 0);
	cout << elementsMultiply;

	FreeLibrary(load);
}