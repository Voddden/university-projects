#define _CRT_SECURE_NO_WARNINGS
#include "countNumbers.h"

int countNumbers(FILE* fp, char* filename) {
	fp = fopen(filename, "r");
	char c;
	int res = 0;
	while ((c = getc(fp)) != EOF) {
		if (c == ' ' || c == '\n')
			++res;
	}
	fclose(fp);
	return (res + 1);
}