#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale>
#include "..\ValidationLib\Validation.h"

struct Equipment {
	unsigned long long id = 0;
	char name[50] = "blank";
	char type[50] = "blank";
	unsigned quantity = 0;
	char date[50] = "blank";
};

enum class Months { 
	January = 1, 
	February = 2, 
	March = 3, 
	April = 4, 
	May = 5, 
	June = 6, 
	July = 7, 
	August = 8, 
	September = 9, 
	October = 10, 
	November = 11, 
	December = 12
};