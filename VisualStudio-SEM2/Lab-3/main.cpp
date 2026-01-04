#define _CRT_SECURE_NO_WARNINGS
#include "addEquipment.h"
#include "scan-printEquipment.h"
#include "editEquipment.h"
#include "deleteEquipment.h"
#include "sortEquipment.h"
#include "..\ValidationLib\Validation.h"
#include "partNameCheck.h"
#include "complexSort.h"

/*
13) Пейнтбол. Содержится информация об оборудовании для игр — 
id, 
название, (name)
тип, (type)
количество на складе,
дата последней проверки. 

Проверить наличие на складе определенного
оборудования по неполному названию. Определить оборудование для проверки.

1.Реализовать все необходимые функции для использования типа данных —
добавление новой записи, (add)
вывод информации, (print)
изменение существующей записи, (edit)
удаление существующей записи, (delete)
сортировка по каждому из полей структуры (sort)

2.Добавить перечисление и одновременную сортировку по нескольким параметрам
*/

void main() 
{
	// "id", "name", "type", "quantity", "date"
	setlocale(LC_ALL, "ru");
	Equipment list[100] = {}; int size = 0;

	int choice = inputNatural("1 - ввести с клавиатуры, 2 - default значения\n");
	switch (choice) {
	case 1:
		inputGeneral(list, size);
		break;
	case 2:
		// 	printf("Список по умолчанию:\n");
		add(list, size, 1, "gunwater", "lasertype", 10, "08.03.2003");
		add(list, size, 1, "gun", "aassd", 4, "09.03.2023");
		add(list, size, 3, "shovel", "pocket edition", 3, "05.03.1995");
		add(list, size, 4, "computer", "Asus", 50, "01.03.1945");
		add(list, size, 5, "lamp", "kinda cute", 6, "07.03.2023");

		editEquipment(list, size, 2, 10, "supergun", "incredible", 15, "03.08.2015");
		break;
	default:
		puts("Invalid input");
		exit(1);
	}

	printList(list, size);

	printf("Введите тип сортировки:\n");
	int sortChoice = inputNatural("1 - no sort, 2 - IDsort, 3 - NAMEsort, 4 - TYPEsort, 5 - QUANTITYSORT, 6 - DATEsort, 7 - одновременная сортировка\n");
	int res = 0;
	switch (sortChoice) {
	case 1:
		break;
	case 2:
		sortById(list, size);
		break;
	case 3:
		sortByName(list, size);
		break;
	case 4:
		sortByType(list, size);
		break;
	case 5:
		sortByQuantity(list, size);
		break;
	case 6:
		sortByDate(list, size);
		break;
	case 7:
		res = complexSort(list, size);
		if (res != 0) {
			puts("error! Invalid input\n");
			exit(0);
		}
		break;
	default:
		puts("Error! Invalid input");
		exit(1);
	}
	printList(list, size);


	partNameCheck(list, size);
}