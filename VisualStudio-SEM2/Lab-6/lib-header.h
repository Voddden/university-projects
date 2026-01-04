#pragma once
_Bool put_i(long long* x);
_Bool put_f(double* y);
_Bool putI(long long* x, long long l, long long r);
_Bool putF(double* x, double l, double r);
double binPow(double q, long long n);
void merge(void* arr, void* arrA, void* arrB, int aSize, int bSize, size_t unitSize, _Bool (*comp123)(void*, void*));
void realMergeSort(void* mainArr, void* arr, int left, int right, size_t unitSize, _Bool (*comp123)(void*, void*));
void mergeSort(void* arr, size_t unitSize, int size, _Bool (*comp123)(void*, void*));