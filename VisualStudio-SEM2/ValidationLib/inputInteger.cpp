#include "inputReal.h"

int inputInteger(const char* prompt) {
	double res = inputReal(prompt);
	while ((int)res != res) {
		printf("Error. Try again\n");
		res = inputReal(prompt);
	}
	return (int)res;
}