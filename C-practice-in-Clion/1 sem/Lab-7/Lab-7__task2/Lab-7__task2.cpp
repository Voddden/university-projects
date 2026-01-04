#include "Validation.h"

/* Дан символ C и строка S. Удалить каждое второе вхождение символа C в строку S */

void deleteC(char* str, int index) {
    for  (int i = index; str[i] != '\0'; ++i)
        str[i] = str[i+1];
}

void operate(char* str, char C) {
    int entry = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == C) {
            ++entry;
            if (entry % 2 == 0) {
                deleteC(str, i);
                --i;
            }
        }
    }
}

int main() {
    int length = 100;
    char* str = (char*) malloc(length);
    printf("str =");
    fgets(str, length + 1, stdin);
    printf("C =");
    char C;
    scanf("%c", &C);

    puts("---Initial string:");
    puts(str);
    printf("Symbol == %c\n", C);

    operate(str, C);

    puts("---Final string: ");
    puts(str);
    return 0;
}
