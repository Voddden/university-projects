#define _CRT_SECURE_NO_WARNINGS
#include "EquipmentType.h"
#include "..\ValidationLib\Validation.h"
#include "daysInMonth.h"

bool test1(const char* str) {
	char valid[] = "ДД.ММ.ГГГГ";

	char s[100] = {};
	strcpy(s, str);
	s[0] = 'Д'; s[1] = 'Д';
	s[3] = 'М'; s[4] = 'М';
	s[6] = 'Г'; s[7] = 'Г'; s[8] = 'Г'; s[9] = 'Г';
	for (int i = 0; i <= 10; ++i) {
		if (s[i] != valid[i])
			return true;
	}
	return false;
}

bool test2(const char* str) {
	for (int i = 0; i < 10; ++i) {
		if (i == 2 || i == 5)
			continue;
		if (!isdigit(str[i]))
			return true;
	}
	return false;
}

bool test3(const char* str) {
	if (str[2] != '.' || str[5] != '.')
		return true;
	else
		return false;
}

bool test4(const char* str) {
	int day = 0, month = 0, year = 0;
	day += ((int)str[0] - 48) * 10;
	day += ((int)str[1] - 48);

	month += ((int)str[3] - 48) * 10;
	month += (int)str[4] - 48;

	//year += (int)str[6] - 48; year += ((int)str[7] - 48) * 10; year += ((int)str[8] - 48) * 100; year += ((int)str[9] - 48) * 1000;
	//if (month == 2 && day > 29) return true;
	//else if (month % 2 == 0 && day > 30) return true;
	//if (month % 2 == 1 && day > 31) return true;


	if (day > daysInMonth(month))
		return true;


	if (month > 12)
		return true;

	return false;
}

bool invalidDate(const char* str) { // ДД.ММ.ГГГГ
	if (test1(str) || test2(str) || test3(str) || test4(str))
		return true;
	else
		return false;
}

void scanEquipment(Equipment& e, int i) {
	printf("list[%d].id = ", i); e.id = inputInteger(""); 
	printf("list[%d].name = ", i); gets_s(e.name, 100);
	printf("list[%d].type = ", i); gets_s(e.type, 100);
	printf("list[%d].quantity = ", i); e.quantity = inputNaturalAnd0("");

	printf("формат: ДД.ММ.ГГГГ\nlist[%d].date = ", i);
	gets_s(e.date, 100);
	while (invalidDate(e.date)) {
		printf("Error. Try again\n");

		printf("формат: ДД.ММ.ГГГ\nlist[%d].date = ", i);
		gets_s(e.date, 100);
	}
	fflush(stdin);
	rewind(stdin);
}

void inputGeneral(Equipment* list, int& size) {
	printf("Введите массив структур:\n");
	int g = 0;
	for (int i = 0; i < 100; ++i) {
		scanEquipment(list[i], i); 
		++size;
		g = inputNatural("1 - продолжить, 2 - завершить ввод\n");
		while (g != 1 && g != 2) {
			printf("Error! Try again\n");
			g = inputNatural("1 - продолжить, 2 - завершить ввод\n");
		}
		if (g == 2)
			break;
	}
}

void printEquipment(Equipment equipment) {
	puts("===============");
	printf("id = %ld\nname = %s\ntype = %s\nquantity = %d\ndate = %s\n",
		equipment.id, equipment.name, equipment.type, equipment.quantity, equipment.date);
	puts("===============");
}

void printList(Equipment* list, const int size) {
	puts("Full list printing:");
	for (int i = 0; i < size; ++i) {
		printf("=============== list[%d]\n", i);
		printf("id = %ld\nname = %s\ntype = %s\nquantity = %d\ndate = %s\n",
			list[i].id, list[i].name, list[i].type, list[i].quantity, list[i].date);
		//puts("===============");
	}
	puts("===============");
}