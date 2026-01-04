#define _CRT_SECURE_NO_WARNINGS
#include "printFile.h"

void printFile(FILE* fp, char* filename) {
    fp = fopen(filename, "r");
    char c;
    while ((c = getc(fp)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");
    fclose(fp);
}