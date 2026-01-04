#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "..\..\ValidationsLib\Validation.h"

struct Equipment {
	int id;
	char name[50] = {};
	union {
		struct {
			int shootSpeed;
			int weight;
			//enum subType { subtype1, subtype2, subtype3 };
			int SUBTYPE;

		} s1;
		struct {
			char purpose[50] = {};
			char price[50] = {};
		} s2;
	} type;
	int quantity;
	char date[50] = {};
};