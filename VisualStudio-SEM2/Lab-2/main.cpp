#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

void checkF(FILE* fp) {
    if (fp == NULL) {
        printf("Null pointer error\n");
        exit(1);
    }
}

void main(int argc, char* argv[]) {
    char filename[100];
    strcpy(filename, argv[1]);
    setlocale(LC_ALL, "ru");
    // создание файла
    FILE* fp = fopen("D:/1. Repository folder/VisualStudio-SEM2/Lab-2/x64/Debug/file228.txt", "w");
    checkF(fp);
    
    //fputs("1 0 -3 59 71963 0 -2 59 2 2", fp); // значения по умолчанию
    
    char str[100];
    gets_s(str);
    fputs(str, fp);

    fclose(fp);

    //// вывод изначального файла в консоль
    printf("Файл по умолчанию: ");
    //printFile(fp, filename);
    puts(str);

    //// работа с файлом:

    // задача1: С клавиатуры заполнить файл числами. Вывести содержимое файла на экран
    //task1(fp, argv[1]); printf("\n");
    // задача2: Определить максимальное число, записанное в файле (если таких чисел несколько, вывести все).
    //task2(fp, argv[1]); printf("\n");
    // задача3: Перевернуть в файле число, номер которого задан с клавиатуры.
    //task3(fp, argv[1]);
    ////

    puts("\n");
}