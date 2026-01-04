#define _CRT_SECURE_NO_WARNINGS
#include "swapEquipment.h"

void swapEquipment(Equipment& e1, Equipment& e2) {
	int temp = e1.id;
	e1.id = e2.id;
	e2.id = temp;

	char buffer[100] = {};
	strcpy(buffer, e1.name);
	strcpy(e1.name, e2.name);
	strcpy(e2.name, buffer);

	strcpy(buffer, e1.type);
	strcpy(e1.type, e2.type);
	strcpy(e2.type, buffer);

	temp = e1.quantity;
	e1.quantity = e2.quantity;
	e2.quantity = temp;

	strcpy(buffer, e1.date);
	strcpy(e1.date, e2.date);
	strcpy(e2.date, buffer);
}