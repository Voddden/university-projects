//Лабораторная 5, задача 4 Выполнена: 

/*
По заданным p и q необходимо вычислить S (p, q)
*/

using namespace std;
#include <iostream>

int F(int n);
int S(int p, int q);

int main() {
	setlocale(LC_ALL, "Rus");

	cout << "Вводите p и q\n";
	int arr[1000][2];
	int i = 0;
	for (; arr[i-1][0] != -1 || arr[i-1][1] != -1; ++i) {
		cin >> arr[i][0] >> arr[i][1];
		while (cin.fail() || cin.peek() != '\n' || arr[i][0] != (long long)arr[i][0] || arr[i][1] != (long long)arr[i][1]) {
			cin.clear();
			cin.ignore(99999, '\n');
			cout << "Введены некорректные данные, попробуйте ещё раз:\n";
			cin >> arr[i][0] >> arr[i][1];
		}
	}
	cout << "Результат:\n";
	////вывод массива входных данных
	//for (int j = 0; j < i; ++j) {
	//	cout << arr[j][0] << " " << arr[j][1] << endl;
	//}

	for (int j = 0; j < i - 1; ++j) {
		cout << S(arr[j][0], arr[j][1]) << endl;
	}

	return 0;
}

int F(int n) {
	if (n % 10 > 0) {
		return n % 10;
	}
	else if (n == 0) {
		return 0;
	}
	else {
		return F(n / 10);
	}
}

int S(int p, int q) {
	long long result = 0;
	for (int i = p; i <= q; ++i) {
		result += F(i);
	}
	return result;
}