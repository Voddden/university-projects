#define _CRT_SECURE_NO_WARNINGS
#include "sortDate.h"

long calc_month(long month) {
	int res = 0;
	for (int i = 1; i <= month; ++i) {
		res += daysInMonth(i);
	}
	return res;
}

void Swap(long long& a, long long& b) {
	long long temp = a;
	a = b;
	b = temp;
}

void swapEquipment(Equipment& e1, Equipment& e2) {
	int temp = e1.id;
	e1.id = e2.id;
	e2.id = temp;

	char buffer[100] = {};
	strcpy(buffer, e1.name);
	strcpy(e1.name, e2.name);
	strcpy(e2.name, buffer);

	// type

	temp = e1.quantity;
	e1.quantity = e2.quantity;
	e2.quantity = temp;

	strcpy(buffer, e1.date);
	strcpy(e1.date, e2.date);
	strcpy(e2.date, buffer);
}

// сортировка
void sortDate(Equipment* arr, const int size, int* unionType) {
	// идея: перевести все даты в списке на кол-во ПОЛНЫХ дней от рождения Христа

	long long* mas = (long long*)calloc(size, sizeof(long long));

	for (int i = 0; i < size; ++i) {
		int day = 0, month = 0, year = 0;
		day += (arr[i].date[0] - 48) * 10;
		day += arr[i].date[1] - 48;

		month += (arr[i].date[3] - 48) * 10;
		month += arr[i].date[4] - 48;

		year += arr[i].date[9] - 48;
		year += (arr[i].date[8] - 48) * 10;
		year += (arr[i].date[7] - 48) * 100;
		year += (arr[i].date[6] - 48) * 1000;

		mas[i] += static_cast<long long>(day) - 1;
		mas[i] += calc_month(month - 1);
		mas[i] += (year - 1) * 365;
	}

	// sort
	for (int a = 0; a < size - 1; ++a) {
		for (int b = 0; b < size - 1 - a; ++b) {
			if (mas[b] > mas[b + 1]) {
				Swap(mas[b], mas[b + 1]);
				swapEquipment(arr[b], arr[b + 1]);
			}
		}
	}
}