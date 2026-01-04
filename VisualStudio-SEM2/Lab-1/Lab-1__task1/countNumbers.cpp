#include "tasks.h"

int countNumbers(FILE* fp) {
	fseek(fp, 0, SEEK_SET);
	char c;
	int res = 0;
	while ((c = getc(fp)) != EOF) {
		if (c == ' ' || c == '\n')
			++res;
	}
	fseek(fp, 0, SEEK_SET);
	return (res + 1);
}