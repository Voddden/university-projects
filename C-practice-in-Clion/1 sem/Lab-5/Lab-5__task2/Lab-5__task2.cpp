#include "Validation.h"

/* Двумерный массив заполнить числами.
 * Количество чисел в строке может быть различным, последнее число - 0.
 * В каждой строке удалить все максимальные элементы */

// input of teeth`ed arrays
void input(int** arr, int m, int* N){
    char iHateC[] = "arr[x][y] =";
    for (int i = 0; i < m; ++i) {
        iHateC[4] = i + 48;
        for (int j = 0; j < 30; ++j){
            iHateC[7] = j + 48;
            arr[i][j] = inputInteger(iHateC);
            if (arr[i][j] == 0){
                //arr[i] = (int*)realloc(arr[i], j + 1);
                N[i] = j + 1;
                break;
            }
        }
    }
}

void output(int** arr, int m, int* N){
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

void deleteElement(int* mas, int& length, int index) {
    for(int i = index; i < length - 1; ++i)
        mas[i] = mas[i + 1];
    //mas = (int*)realloc(mas, --length);
    --length;
}

int indexOfMax(int* mas, int length){
    int index = 0;
    int s = mas[0];
    for (int i = 1; i < length; ++i){
        if (mas[i] > s) {
            s = mas[i];
            index = i;
        }
    }
    return index;
}

// преобразование массива:
void operate(int** arr, int m, int* N) {
    for (int i = 0; i < m; ++i)
        deleteElement(arr[i], N[i], indexOfMax(arr[i], N[i]));
}

int main() {
    srand(time(NULL));
    printf("Lab 5, task 2\n\n");

    int m = inputNatural("m =");
    int* N = (int*)calloc(m, sizeof (int));
    for (int i = 0; i < m; ++i) N[i] = 30;

    int** arr = (int**)malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i)
        arr[i] = (int*)malloc(N[i] * sizeof(int));

    // ввод массива с клавиатуры
    input(arr, m, N);

    // отбрасывание не используемых элементов:
    //for (int i = 0; i < m; ++i) arr[i] = (int*)realloc(arr[i], N[i]);

    // вывод первоначального массива
    printf("\nInitial matrix:\n\n");
    output(arr, m, N);

    // преобразование массива: (удаление максимальных элементов в каждой из строк)
    operate(arr, m, N);

    // вывод преобразованного массива:
    printf("\nFinal matrix:\n\n");
    output(arr, m, N);

    // конец работы. Освобождение памяти
    Free(arr, m);
    return 0;
}
