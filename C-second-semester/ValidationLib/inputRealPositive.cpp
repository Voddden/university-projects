#include "inputReal.h"

double inputRealPositive(const char* prompt) {
	double res = inputReal(prompt);
	while (res <= 0) {
		//system("cls");
		printf("Error. Try again\n");
		res = inputReal(prompt);
	}
	return res;
}