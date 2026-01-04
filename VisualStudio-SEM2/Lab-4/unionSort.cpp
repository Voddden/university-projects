#define _CRT_SECURE_NO_WARNINGS
#include "unionSort.h"

void swapEquipment(Equipment& e1, Equipment& e2, int commonUnion) {
	int temp = e1.id;
	e1.id = e2.id;
	e2.id = temp;

	char buffer[100] = {};
	strcpy(buffer, e1.name);
	strcpy(e1.name, e2.name);
	strcpy(e2.name, buffer);

	switch (commonUnion) {
	case 1:
		temp = e1.type.s1.shootSpeed;
		e1.type.s1.shootSpeed = e2.type.s1.shootSpeed;
		e2.type.s1.shootSpeed = temp;

		temp = e1.type.s1.weight;
		e1.type.s1.weight = e2.type.s1.weight;
		e2.type.s1.weight = temp;

		temp = e1.type.s1.SUBTYPE;
		e1.type.s1.SUBTYPE = e2.type.s1.SUBTYPE;
		e2.type.s1.SUBTYPE = temp;
		break;
	case 2:
		char buffer[50] = {};
		strcpy(buffer, e1.type.s2.purpose);
		strcpy(e1.type.s2.purpose, e2.type.s2.purpose);
		strcpy(e2.type.s2.purpose, buffer);

		strcpy(buffer, e1.type.s2.price);
		strcpy(e1.type.s2.price, e2.type.s2.price);
		strcpy(e2.type.s2.price, buffer);
		break;
	}

	temp = e1.quantity;
	e1.quantity = e2.quantity;
	e2.quantity = temp;

	strcpy(buffer, e1.date);
	strcpy(e1.date, e2.date);
	strcpy(e2.date, buffer);

}

void equipCpy(Equipment* destination, Equipment* source, int commonUnion) {
	destination->id = source->id;

	strcpy(destination->name, source->name);

	switch (commonUnion) {
	case 1:
		destination->type.s1.shootSpeed = source->type.s1.shootSpeed;

		destination->type.s1.weight = source->type.s1.weight;

		destination->type.s1.SUBTYPE = source->type.s1.SUBTYPE;
		break;
	case 2:
		strcpy(destination->type.s2.purpose, source->type.s2.purpose);

		strcpy(destination->type.s2.price, source->type.s2.price);
		break;
	}

	destination->quantity = source->quantity;

	strcpy(destination->date, source->date);
}

void sortType1(Equipment* arr, const int size, int* unionType) {
	int g = 0, sizeMas;
	for (int i = 0; i < size; ++i) {
		if (unionType[i] == 1) {
			++g;
		}
	}
	sizeMas = g;
	Equipment* mas = (Equipment*)calloc(g, sizeof(int));
	int k = 0;
	for (int i = 0; i < size; ++i) {
		if (unionType[i] == 1) {
			equipCpy(&mas[k], &arr[i], unionType[i]);
			++k;
		}
	}

	// сортировка mas[] по возрастанию скорострельности
	for (int a = 0; a < sizeMas - 1; ++a)
		for (int b = 0; b < sizeMas - 1 - a; ++b)
			if (mas[b].type.s1.shootSpeed > mas[b + 1].type.s1.shootSpeed)
				swapEquipment(mas[b], mas[b + 1], 1);
	//
	int p = 0;
	for (int i = 0; i < size; ++i) {
		if (unionType[i] == 1) {
			equipCpy(&arr[i], &mas[p], unionType[i]);
			++p;
		}
	}

	//free(mas);
}

void sortType2(Equipment* arr, const int size, int* unionType) {
	int g = 0, sizeMas;
	for (int i = 0; i < size; ++i) {
		if (unionType[i] == 2) {
			++g;
		}
	}
	sizeMas = g;
	Equipment* mas = (Equipment*)calloc(g, sizeof(int));
	int k = 0;
	for (int i = 0; i < size; ++i) {
		if (unionType[i] == 2) {
			equipCpy(&mas[k], &arr[i], unionType[i]);
			++k;
		}
	}

	// сортировка mas[] по первой букве поля "назначение" (по алфавиту)
	for (int a = 0; a < sizeMas - 1; ++a)
		for (int b = 0; b < sizeMas - 1 - a; ++b)
			if (strcmp(mas[b].type.s2.purpose, mas[b + 1].type.s2.purpose)) swapEquipment(mas[b], mas[b + 1], 2);
	//

	k = 0;
	for (int i = 0; i < size; ++i) {
		if (unionType[i] == 2) {
			equipCpy(&arr[i], &mas[k], unionType[i]);
			++k;
		}
	}
	//free(mas);
}

void unionSort(Equipment* arr, const int size, int* unionType) 
{
	sortType1(arr, size, unionType);
	sortType2(arr, size, unionType);
}
