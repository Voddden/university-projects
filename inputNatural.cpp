#include "inputReal.h"

int inputNatural(const char* prompt) {
	double res = inputReal(prompt);
	while (res <= 0 || (int)res != res) {
		//system("cls");
		printf("Error. Try again\n");
		res = inputReal(prompt);
	}
	return (int)res;
}