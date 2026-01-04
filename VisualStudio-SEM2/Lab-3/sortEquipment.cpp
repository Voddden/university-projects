#include "sortEquipment.h"
#include "swapEquipment.h"
#include "daysInMonth.h"

void sortById(Equipment* list, const int size) {
	for (int a = 0; a < size - 1; ++a)
		for (int b = 0; b < size - 1 - a; ++b)
			if (list[b].id > list[b + 1].id)
				swapEquipment(list[b], list[b + 1]);
}

void sortByName(Equipment* list, const int size) {
	for (int a = 0; a < size - 1; ++a)
		for (int b = 0; b < size - 1 - a; ++b)
			if (strcmp(list[b].name, list[b + 1].name))
				swapEquipment(list[b], list[b + 1]);
}

void sortByType(Equipment* list, const int size) {
	for (int a = 0; a < size - 1; ++a)
		for (int b = 0; b < size - 1 - a; ++b)
			if (strcmp(list[b].type, list[b + 1].type))
				swapEquipment(list[b], list[b + 1]);
}

void sortByQuantity(Equipment* list, const int size) {
	for (int a = 0; a < size - 1; ++a)
		for (int b = 0; b < size - 1 - a; ++b)
			if (list[b].quantity > list[b + 1].quantity)
				swapEquipment(list[b], list[b + 1]);
}

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

void sortByDate(Equipment* list, const int size) {
	// идея: перевести все даты в списке на кол-во ПОЛНЫХ дней от рождения Христа

	long long* arr = (long long*)calloc(size, sizeof(long long));

	for (int i = 0; i < size; ++i) {
		int day = 0, month = 0, year = 0;
		day += ((long long)list[i].date[0] - 48) * 10;
		day += ((long long)list[i].date[1] - 48);

		month += ((long long)list[i].date[3] - 48) * 10;
		month += (long long)list[i].date[4] - 48;

		year += (long long)list[i].date[9] - 48;
		year += ((long long)list[i].date[8] - 48) * 10;
		year += ((long long)list[i].date[7] - 48) * 100;
		year += ((long long)list[i].date[6] - 48) * 1000;

		arr[i] += (long long)day - 1;
		arr[i] += calc_month(month - 1);
		arr[i] += ((long long)year - 1) * 365;
	}
	
	// sort
	for (int a = 0; a < size - 1; ++a) {
		for (int b = 0; b < size - 1 - a; ++b) {
			if (arr[b] > arr[b + 1]) {
				Swap(arr[b], arr[b + 1]);
				swapEquipment(list[b], list[b + 1]);
			}
		}
	}				
}