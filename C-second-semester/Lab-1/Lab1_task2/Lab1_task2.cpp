//Лабораторная 1, задача 2 Выполнил: Воднев Д.И.

/*
Даны два числа a и b. Определите, равны или не равны эти числа.
*/

#include <stdio.h>
#include <locale.h>
#include "..\..\ValidationLib\inputReal.h"

void main()
{
	setlocale(LC_ALL, "ru");

	double a = inputReal("a = ");
	double b = inputReal("b = ");

	if (a == b)
		printf("a и b равны\n");
	else
		printf("a и b неравны\n");
}