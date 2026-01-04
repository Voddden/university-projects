#include "Validation.h"

void inputArr(int* arr, int size) {
    char iHateC[] = "\narr[x] =";
    for (int i = 0; i < size; ++i) {
        iHateC[5] = i + 48;
        arr[i] = inputInteger(iHateC);
    }
}
void randArr(int* arr, int size){
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 10 - rand() % 10;
}
void outputArr(int* arr, int size){
    for (int i = 0; i < size; ++i)
        printf("%5d ", arr[i]);
}

/* В одномерном массиве выполнить сортировку нечетных элементов до последнего положительного методом Шелла */

int indexOfLastPositive(int* arr, int size){
    int index = 0;
    for (int i = 0; i < size; ++i){
        if (arr[i] > 0)
            index = i;
    }
    return index;
}

void shellSort(int array[], int n) {
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

void Sort(int* arr, int size) {
    int numSortable = 0;
    for (int i = 0; i < size; ++i){
        if ((i + 1) % 2 == 1 && i <= indexOfLastPositive(arr, size)) {
            ++numSortable;
        }
    }

    int* sortableArr = (int*)malloc(numSortable * sizeof(int));
    int* helpArr = (int*)malloc(numSortable * sizeof(int));

    // sortableArr and helpArr init
    int g = 0;
    for (int i = 0; i < size; ++i){
        if ((i + 1) % 2 == 1 && i <= indexOfLastPositive(arr, size)) {
            sortableArr[g] = arr[i];
            helpArr[g] = i;
            ++g;
        }
    }

    shellSort(sortableArr, numSortable);

    for (int i = 0; i < numSortable; ++i)
        arr[helpArr[i]] = sortableArr[i];

}

int main() {
    srand(time(NULL));

    int size = inputNatural("size =");
    int* arr = (int*)malloc(size * sizeof (int));

    int choice = inputInteger("---input array from keyboard - 1\t\trandom - 2\n");
    while (choice != 1 && choice != 2) {
        choice = inputInteger("Error. Try again\n---input array from keyboard - 1\t\trandom - 2\n");
    }

    switch (choice) {
        case 1:
            inputArr(arr, size); break;
        case 2:
            randArr(arr, size);
    }

    // вывод изначального массива:
    printf("\nInitial array:\n");
    outputArr(arr, size); //puts("\n");

    // сортировка элементов:
    Sort(arr, size);
    // вывод конечного массива:
    printf("\nSorted array:\n");
    outputArr(arr, size); puts("\n");
    // конец работы. Освобождение памяти
    free(arr);
    return 0;
}
