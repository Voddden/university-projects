#include "Validation.h"

/* В двумерной матрице размером NxM удалить все строки содержащие более 2х нулей подряд. */

int** allocation(int m, int n)
{
    int** mas;
    mas = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        mas[i] = (int*)malloc(n * sizeof(int)); //*(mas + i)
    }
    return mas;
}
void inputArr(int** arr, int m, int n) {
    char iHateC[] = "arr[.][.] =";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            iHateC[4] = i + 48;
            iHateC[7] = j + 48;
            arr[i][j] = inputInteger(iHateC);
        }
    }
}
void randArr(int** arr, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = rand() % 10 - rand() % 10;
        }
    }
}
void outputArr(int** arr, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }
}

void Free(int** arr, int m) {
    for (int i = 0; i < m; ++i)
        free(arr[i]);
    free(arr);
}

// преобразование массива

bool hasNullsInARow(int* mas, int size){
    for (int i = 0; i < size - 1; ++i){
        if (mas[i] == 0 && mas[i + 1] == 0)
            return true;
    }
    return false;
}

void shiftStrings(int** arr, int& m, int n, int index){
    // сдвиг строк
    for (int i = index; i < m - 1; ++i)
        for (int j = 0; j < n; ++j)
            arr[i][j] = arr[i + 1][j];
}

void operate(int** arr, int& m, int n) {
    for (int i = 0; i < m; ++i){
        if (hasNullsInARow(arr[i], n)) {
            shiftStrings(arr, m, n, i);
            arr = (int**)realloc(arr, m - 1);
            --m;
            --i;
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Lab 5, task 3\n\n");
    printf("Matrix m x n\n");

    int m = inputNatural("m =");
    int n = inputNatural("n =");

    int** arr = allocation(m, n);

    int choice = inputNatural("---input matrix from keyboard - 1\t\trandom - 2\n");
    while (choice != 1 && choice != 2) {
        choice = inputNatural("---input matrix from keyboard - 1\t\trandom - 2\n");
    }

    switch (choice) {
        case 1:
            inputArr(arr, m, n); break;
        case 2:
            randArr(arr, m, n);
    }

    // вывод первоначального массива
    printf("\nInitial matrix:\n\n");
    outputArr(arr, m, n);

    // преобразование массива: (удаление строк, содержащих более 2-х нулей подряд)
    operate(arr, m, n);

    // вывод преобразованного массива:
    printf("\nFinal matrix:\n\n");
    outputArr(arr, m, n);

    // конец работы. Освобождение памяти
    Free(arr, m);
    return 0;
}