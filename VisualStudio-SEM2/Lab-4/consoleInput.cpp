#include "EquipmentType.h"

void inputType(Equipment& e, int i, int* unionType) {
	printf("Введите номер union\n");
	switch (inputNatural("1 - скорострельность, вес, подтип. 2 - назначение, стоимость\n"))
	{
	case 1:
		unionType[i] = 1;
		e.type.s1.shootSpeed = inputRealPositive("скорострельность = ");
		e.type.s1.weight = inputRealPositive("вес = ");
		//e.type.s1.SUBTYPE = e.type.s1.subtype1;
		e.type.s1.SUBTYPE = 3;
		break;
	case 2:
		unionType[i] = 2;
		printf("назначение = ");
		gets_s(e.type.s2.purpose, 50);
		printf("цена = ");
		gets_s(e.type.s2.price, 50);
		break;
	default:
		puts("Invalid Data!"); exit(1);
		break;
	}
}

void scanEquipment(Equipment& e, int i, int* unionType) {
	printf("list[%d].id = ", i); e.id = inputInteger("");

	printf("list[%d].name = ", i); gets_s(e.name, 100);
	
	inputType(e, i, unionType);
	
	printf("list[%d].quantity = ", i); e.quantity = inputNaturalAnd0("");

	printf("формат: ДД.ММ.ГГГГ\nlist[%d].date = ", i);
	gets_s(e.date, 100);
	while (DateValidation(e.date)) {
		printf("Error. Try again\nlist[%d].date = ", i);
		gets_s(e.date, 100);
	}

	fflush(stdin);
	rewind(stdin);
}

void consoleInput(Equipment* arr, int& size, int* arr_temp) {
	printf("Введите массив структур:\n");
	int g = 0;
	for (int i = 0; i < 100; ++i) {
		scanEquipment(arr[i], i, arr_temp); 
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