#include "consoleOutput.h"

void printType(Equipment equipment, int unionType) {
	switch (unionType)
	{
	case 1:
		printf("\nскорострельность = %d\nвес = %d\nsubtype number = %d", 
			equipment.type.s1.shootSpeed, equipment.type.s1.weight, equipment.type.s1.SUBTYPE);
		break;
	case 2:
		printf("\nназначение = %s\nстоимость = %s",
			equipment.type.s2.purpose, equipment.type.s2.price);
		break;
	default:
		puts("Error! Invalid data"); exit(1);
	}
}

void printArr(Equipment* arr, const int size, int* unionType) {
	puts("Full array printing:");
	for (int i = 0; i < size; ++i) {
		printf("=============== arr[%d]\n", i);
		printf("id = %d\nname = %s", arr[i].id, arr[i].name);
		printType(arr[i], unionType[i]);
		printf("\nquantity = %d\ndate = %s\n", arr[i].quantity, arr[i].date);
	}
	puts("===============");
}

void printEquipment(Equipment e, int i, int* unionType) {
	printf("=============== arr[%d]\n", i);
	printf("id = %d\nname = %s", e.id, e.name);
	printType(e, unionType[i]);
	printf("\nquantity = %d\ndate = %s\n", e.quantity, e.date);
	printf("===============");
}