#include "EquipmentType.h"
#include "consoleInput.h"
#include "consoleOutput.h"
#include "defaultValues.h"

#include "vzyatieOstatka.h"
#include "search.h"
#include "sortDate.h"
#include "unionSort.h"

/*
Реализовать операцию взятия остатка от деления на число, передаваемое через
командную строку(отдельная функция, отдельный union). 

Реализовать функции
поиска и 
сортировки информации по одному из новых свойств.
*/

// id, название, тип, кол-во, дата
void main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	Equipment arr[100] = {}; int size = 0;
	int unionType[100] = {};
	switch (inputNatural("1 - ввод с консоли, 2 - default значения\n")) {
	case 1:
		consoleInput(arr, size, unionType);
		break;
	case 2:
		defaultValues(arr, size, unionType);
		break;
	default:
		printf("Error! Invalid data"); exit(1);
	}
	//consoleInput(arr, size, unionType);

	printArr(arr, size, unionType);

	switch (inputNatural("1 - выполнить поиск, 2 - пропустить\n")) {
	case 1:
		search(arr, size, unionType);
		break;
	case 2:
		break;
	default:
		puts("Error! Invalid data"); exit(1);
	}


	puts("\n");
	switch (inputNatural("1 - выполнить сортировку, 2 - пропустить\n")) {
	case 1:
		printf("\n\t\t--- Сортировка ---\n");
		//sortDate(arr, size, unionType);
		unionSort(arr, size, unionType);
		printf("Массив после сортировки:\n\n");
		printArr(arr, size, unionType);
		break;
	case 2:
		break;
	default:
		printf("Error! Invalid data"); exit(1);
	}

	//int num  = inputNaturalAnd0("Введите число для взятия остатка: ");
	//int argvv = atoi(argv[1]);
	//int res = vzyatieOstatka(num, argvv);
	//printf("%d\n", res);
	//printf("\n%d", vzyatieOstatka(inputNatural("Введите число для взятия остатка: "), atoi(argv[1]))); exit(0);
}