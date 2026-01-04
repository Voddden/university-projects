#include "Validation.h"

/* Заполнить массив с клавиатуры. Удалить все элементы, кратные 11.*/

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
            arr[i][j] = rand() % 100;
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
void outputModified(int** arr, int m, int* N){
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < N[i]; ++j) {
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

// operate
void deleteElement(int* mas, int& length, int index) {
    for(int i = index; i < length - 1; ++i)
        mas[i] = mas[i + 1];
    //mas = (int*)realloc(mas, --length);
    --length;
}

void operate(int** arr, int m, int* N) {
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < N[i]; ++j){
            if (arr[i][j] % 11 == 0 && arr[i][j] != 0) {
                deleteElement(arr[i], N[i], j);
                --j;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Lab 5, task 1\n\n");
    printf("Matrix m x n\n");

    int m = inputNatural("m =");
    int n = inputNatural("n =");

    int* N = (int*)calloc(m, sizeof (int));
    for (int i = 0; i < m; ++i) N[i] = n;

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

    // преобразование массива: (удаление элементов, кратных 11)
    operate(arr, m, N);

    // вывод преобразованного массива:
    printf("\nFinal matrix:\n\n");
    outputModified(arr, m, N);

    // конец работы. Освобождение памяти
    Free(arr, m);
    return 0;
}
