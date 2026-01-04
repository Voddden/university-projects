#include "Validation.h"

void deleteWord(char* str, int index, int wordLength) {
    for (int i = index; str[i + wordLength] != '\0'; ++i)
        //str[i - wordLength] = str[i + 1];
        str[i] = str[i + wordLength + 1];
}

int WordLength(char* str, int wordStart) {
    int res = 0;
    for (int k = wordStart; str[k] != ' ' && str[k] != '\n'; ++k)
        ++res;
    return res;
}

void operate(char* str, int k) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ')
            continue;
        int wordlength = WordLength(str, i);
        if (wordlength > k) {
            deleteWord(str, i, wordlength);
            --i;
        }
        else {
            i += wordlength;
        }
    }
}

/* Дана строка. Удалить все слова большие k букв (вар. 9) */

int main() {
    int length = 100;
    char* str = (char*) malloc(length);
    printf("str =");
    fgets(str, length + 1, stdin);
    int k = inputNatural("k =");

    puts("---Initial string:");
    puts(str);

    operate(str, k);

    puts("---Final string: ");
    puts(str);
    return 0;
}
