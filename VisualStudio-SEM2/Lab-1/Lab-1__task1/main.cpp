#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "tasks.h"

char filename[100];

void checkF(FILE* fp) {
    if (fp == NULL) {
        printf("Null pointer error\n");
        exit(1);
    }
}

void printFile(FILE* fp) {
    fp = freopen(filename, "rb", fp);
    char c;
    while ((c = getc(fp)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");
    fseek(fp, 0, SEEK_SET);
}

int main(int argc, char* argv[])
{
    strcpy(filename, argv[1]);
    setlocale(LC_ALL, "ru");
    // создание файла
    FILE* fp = fopen(argv[1], "w");
    checkF(fp);
    fputs("1 -14 0 3 -59 7 0", fp); // значения по умолчанию
    fclose(fp);
    //// вывод изначального файла в консоль
    printf("Файл по умолчанию: ");
    printFile(fp);

    

    //// работа с файлом:
    // задача1: С клавиатуры заполнить файл целыми числами
    fflush(stdin);
    task1(fp, argv[1]);
    // задача2: Подсчитать сумму чётных чисел
    task2(fp, argv[1]);
    printf("\n");
    // задача3: Удалить все чётные числа
    task3(fp, argv[1]);
    // задача4: Отсортировать только числа большие заданного (по убыванию)
    task4(fp, argv[1]);
    ////
    
    puts("\n");
}