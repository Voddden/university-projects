#include "Validation.h"

/* Отсортировать методом вставок массив строк по количеству слов состоящим из
четного количества символов. */

char** allocation(int m, int n)
{
    char** mas;
    mas = (char**)malloc(m);
    for (int i = 0; i < m; i++)
    {
        mas[i] = (char*)malloc(n); //*(mas + i)
    }
    return mas;
}

void input(char** table, int m) {
    for(int i = 0; i < m; ++i) {
         printf("table[%d] =", i);
         gets(table[i]);
    //     int j = 0;
//         while (getchar() != '\n') {
//             table[i][j] = getchar();
//             ++j;
//         }

         //getchar();
    }
}

int strLength(char* str) {
    int res = 0;
    for(; str[res] != '\0'; ++res);
    return res;
}

void clearTable(char** table, int m) {
    for (int i = 0; i < m; ++i) {
        table[i] = (char*)realloc(table[i], strLength(table[i]) + 1);
    }
}

void output(char** table, int m) {
    for (int i = 0; i < m; ++i) {
        puts(table[i]);
    }
}

// модифицированный insertion sort:

int WordLength(char* str, int wordStart) {
    int res = 0;
    for (int k = wordStart; str[k] != ' ' && str[k] != '\0'; ++k)
        ++res;
    return res;
}

int numOfEvenWords(char* str) {
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ')
            continue;
        int wordlength = WordLength(str, i);
        if (wordlength % 2 == 0)
            ++res;
        else
            i += wordlength - 1;
    }
    return res;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void copy(char* str1, char* str2) {
    for(int i = 0; str2[i - 1] != '\0'; ++i)
        str1[i] = str2[i];
}

void Sort(char** table, int m) {
    int* numEven = (int*)calloc(m, 1);
    for (int i = 0; i < m; ++i) {
        numEven[i] = numOfEvenWords(table[i]);
    }
    // сортировка вставками:
    int i, key, j; char* keyStr = (char*)malloc(100);
    for (i = 1; i < m; i++) {
        key = numEven[i];
        //keyStr = table[i];
        copy(keyStr, table[i]);
        j = i - 1;

        while (j >= 0 && numEven[j] > key) {
            numEven[j + 1] = numEven[j];
            //table[j + 1] = table[j];
            copy(table[j+1], table[j]);
            j = j - 1;
        }
        numEven[j + 1] = key;
        //table[j + 1] = keyStr;
        copy(table[j + 1], keyStr);
    }
}

int main() {
    int m = inputNatural("m =");
    char** arr = allocation(m, 100);
    input(arr, m);
    //clearTable(arr, m);

    //puts("---Initial table:\n");
    //output(arr, m);

    Sort(arr, m);

    puts("\n---Sorted table:\n");
    output(arr, m);
    return 0;
}