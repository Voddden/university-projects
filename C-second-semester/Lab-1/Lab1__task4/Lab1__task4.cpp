//Лабораторная 1, задача 4 выполнил: Воднев Д. И.

/*
По номеру месяца напечатать его название
*/

#include <stdio.h>
#include <locale.h>
#include "..\..\ValidationLib\inputNatural.h"

void main()
{
	setlocale(LC_ALL, "ru");
	
	int num = inputNatural("---Введите номер месяца: ");		

	switch (num) {
		case 1: printf("Январь\n"); break;
		case 2: printf("Февраль\n"); break;
		case 3: printf("Март\n"); break;
		case 4: printf("Апрель\n"); break;
		case 5: printf("Май\n"); break;
		case 6: printf("Июнь\n"); break;
		case 7: printf("Июль\n"); break;
		case 8: printf("Август\n"); break;
		case 9: printf("Сентябрь\n"); break;
		case 10: printf("Октябрь\n"); break;
		case 11: printf("Ноябрь\n"); break;
		case 12: printf("Декабрь\n"); break;
		default: printf("Месяца с таким номером не существует\n");
	}
}