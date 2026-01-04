#define _CRT_SECURE_NO_WARNINGS
#include "defaultValues.h"

void defaultValues(Equipment* arr, int& size, int* unionType) {
	// 1
	++size;

	arr[0].id = 1;
	strcpy(arr[0].name, "gun");

	unionType[0] = 1;
	arr[0].type.s1.shootSpeed = 576;
	arr[0].type.s1.weight = 30;
	//arr[0].type.s1.SUBTYPE = arr[0].type.s1.subtype1;

	arr[0].quantity = 77;
	strcpy(arr[0].date, "25.10.2022");

	//// 2
	//++size;

	//arr[1].id = 2;
	//strcpy(arr[1].name, "laser");

	//unionType[1] = 2;
	//strcpy(arr[1].type.s2.price, "300$");
	//strcpy(arr[1].type.s2.purpose, "Zkill");

	//arr[1].quantity = 10;
	//strcpy(arr[1].date, "06.04.2023");

	// 3
	++size;

	arr[1].id = 3;
	strcpy(arr[1].name, "watergun");

	unionType[1] = 1;
	arr[1].type.s1.shootSpeed = 268;
	arr[1].type.s1.weight = 50;
	//arr[2].type.s1.subtype2;

	arr[1].quantity = 14;
	strcpy(arr[1].date, "02.11.1989");

	//// 4


	//++size;

	//arr[3].id = 4;
	//strcpy(arr[3].name, "robot");

	//unionType[3] = 2;
	//strcpy(arr[3].type.s2.price, "300$");
	//strcpy(arr[3].type.s2.purpose, "Alive");

	//arr[3].quantity = 10;
	//strcpy(arr[3].date, "06.04.2023");

	//// 5
	//++size;

	//arr[4].id = 5;
	//strcpy(arr[4].name, "Tank Abrams");

	//unionType[4] = 1;
	//arr[4].type.s1.shootSpeed = 216;
	//arr[4].type.s1.weight = 50;
	////arr[4].type.s1.subtype2;

	//arr[4].quantity = 14;
	//strcpy(arr[4].date, "02.11.1989");
}