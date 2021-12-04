#include<iostream>
#include<cmath>
extern "C" __declspec(dllexport) int account(int* arr, int i, double n) {
	if (i == n) return i;
	if (cos(arr[i] * arr[i]) > 0 && arr[i] < 0) std::cout << arr[i] << " ";
	account(arr, ++i, n);
}