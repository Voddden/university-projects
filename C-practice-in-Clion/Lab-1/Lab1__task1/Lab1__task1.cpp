#include <stdio.h>
#include <stdlib.h>

/* В-7
 * 1. С клавиатуры заполнить файл целыми числами.*/

int hasLetters(char* str) {
    for (int i = 0; str[i] != '\0'; ++i)
        if (!('0' <= str[i] && str[i] <= '9' || str[i] == ' '))
            return 1;
    return 0;
}

int main(void)
{
    char* message = (char*)malloc(100);
    printf("Enter integer numbers:");
    gets(message);
    if (hasLetters(message)) {
        perror("Error! Letters are not allowed");
        return 1;
    }
    fflush(stdin);
    FILE * fp= fopen("D://data.txt", "w");
    if(fp)
    {
        // посимвольно записываем в файл
        for(int i=0; message[i] != '\0'; i++)
        {
            putc(message[i], fp);
        }
        fclose(fp);
        printf("File has been written\n");
    }
}