/*
Определить время падения камня на поверхность земли с высоты h.
*/

#include <iostream>
using namespace std;
#include <cmath>

int main() {
	setlocale(LC_ALL, "Rus");
	double h, t;
	cout << "Введите высоту (в метрах) \n";
	cin >> h;
	t = sqrt(h / 5);
	if (h > 0) {
		cout << "Время падения камня равно " << t << " (в секундах)" << endl;
	} 
	else {
		cout << "Вас не понял, прошу повторить\n"; 
	}
	return 0;
}

/*
Тест:
1) h = 10
Ответ: 1.41421 (верно)

*/