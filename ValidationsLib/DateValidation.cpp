#define _CRT_SECURE_NO_WARNINGS
#include "DateValidation.h"

int daysInMonth(int month) {
	if (month == 1)
		return 31;
	if (month == 2)
		return 28;
	if (month == 3)
		return 31;
	if (month == 4)
		return 30;
	if (month == 5)
		return 31;
	if (month == 6)
		return 30;
	if (month == 7)
		return 31;
	if (month == 8)
		return 31;
	if (month == 9)
		return 30;
	if (month == 10)
		return 31;
	if (month == 11)
		return 30;
	if (month == 12)
		return 31;
}

bool test1(const char* str) {
	char valid[] = "ÄÄ.ÌÌ.ÃÃÃÃ";

	char s[100] = {};
	strcpy(s, str);
	s[0] = 'Ä'; s[1] = 'Ä';
	s[3] = 'Ì'; s[4] = 'Ì';
	s[6] = 'Ã'; s[7] = 'Ã'; s[8] = 'Ã'; s[9] = 'Ã';
	for (int i = 0; i <= 10; ++i) {
		if (s[i] != valid[i])
			return true;
	}
	return false;
}

bool test2(const char* str) {
	for (int i = 0; i < 10; ++i) {
		if (i == 2 || i == 5)
			continue;
		if (!isdigit(str[i]))
			return true;
	}
	return false;
}

bool test3(const char* str) {
	if (str[2] != '.' || str[5] != '.')
		return true;
	else
		return false;
}

bool test4(const char* str) {
	int day = 0, month = 0, year = 0;
	day += ((int)str[0] - 48) * 10;
	day += ((int)str[1] - 48);

	month += ((int)str[3] - 48) * 10;
	month += (int)str[4] - 48;

	if (day > daysInMonth(month))
		return true;


	if (month > 12)
		return true;

	return false;
}

bool DateValidation(const char* str) { // ÄÄ.ÌÌ.ÃÃÃÃ
	if (test1(str) || test2(str) || test3(str) || test4(str))
		return true;
	else
		return false;
}