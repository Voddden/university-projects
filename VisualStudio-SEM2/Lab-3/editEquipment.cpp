#define _CRT_SECURE_NO_WARNINGS
#include "editEquipment.h"

void editEquipment(Equipment* stack, int& size, int indexToEdit, 
	int _id, const char* _name, const  char* _type, unsigned _quantity, const char* _date) 
{
	stack[indexToEdit].id = _id;
	strcpy(stack[indexToEdit].name, _name);
	strcpy(stack[indexToEdit].type, _type);
	stack[indexToEdit].quantity = _quantity;
	strcpy(stack[indexToEdit].date, _date);
}