//Лабораторная 1, задача 3 Выполнена: Воднев Д. И.

/*
Если среди чисел a, b и c есть пара взаимно противоположных,
вывести третье (оставшееся) число,
в противоположном случае вывести сообщение "нет"
*/

#include <stdio.h>
#include <locale.h>
#include "..\..\ValidationLib\inputReal.h"

void main()
{
	setlocale(LC_ALL, "ru");

	double a = inputReal("a = ");
	double b = inputReal("b = ");
	double c = inputReal("c = ");

	if (a == -b || b == -a)
		printf("%.2lf \n", c);
	else if (a == -c || c == -a)
		printf("%.2lf \n", b);
	else if (c == -b || b == -c)
		printf("%.2lf \n", a);
	else
		printf("нет\n");
}