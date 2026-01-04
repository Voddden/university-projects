#include "daysInMonth.h"

int daysInMonth(int month) {
	if (month == (int)Months::January)
		return 31;
	if (month == (int)Months::February)
		return 28;
	if (month == (int)Months::March)
		return 31;
	if (month == (int)Months::April)
		return 30;
	if (month == (int)Months::May)
		return 31;
	if (month == (int)Months::June)
		return 30;
	if (month == (int)Months::July)
		return 31;
	if (month == (int)Months::August)
		return 31;
	if (month == (int)Months::September)
		return 30;
	if (month == (int)Months::October)
		return 31;
	if (month == (int)Months::November)
		return 30;
	if (month == (int)Months::December)
		return 31;
}