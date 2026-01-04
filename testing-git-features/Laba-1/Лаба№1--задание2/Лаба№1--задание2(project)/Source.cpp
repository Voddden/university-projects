/*
Вариант №4
*/

#include <iostream>;
using namespace std;
#include <cmath>

int main() {
	setlocale(LC_ALL, "Rus");
	double x, y, z, K, C, D, T;
	cout << "Введите значения переменных в таком порядке: x y z K C D\n";
	cin >> x >> y >> z >> K >> C >> D;
	T = cos(x) + pow(x - y, 2) / (K - C * D) - sqrt(z);
	if ((K - C * D) == 0) {
		cout << "Знаменатель равен нулю!!\n";
	}
	else {
		cout << T << endl;
	}
	return 0;
}

/*
--- Тесты:
1) 
3 3 3 3 3 3
Ответ: -2.72204 (верно)
2) 
3 1 5 2 4 1
Ответ: -5.22606 (верно)
3) 1 1 1 1 1 1
Ответ: знаменатель равен нулю (верно)

*/