//Лабораторная 2, задача 10. Выполнена: Воднев Д. И.

/*
	Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x|
	при заданном х, определить и вывести на экран дисплея минимальное
	значение. Библиотеку <cmath> использовать запрещено.
*/

#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	const double pi = 3.1415926535;
	cout << "Введите x\n";
	double x;
	cin >> x;
	double LNX, SINX, COSX;
	if (x == 0) {
		cout << "Ошибка, x не может быть равен нулю\n";
	}
	else if (x > 0) {

		//// ln - 1
		double count = 1, totalValue = 0, it = 1000, xLN = x, z = 1, powe = 1, y;
		if (xLN < 0) {
			xLN = -xLN;
			while (count <= it)
			{
				for (int i = 0; i < powe; i++) {
					z *= (x - 1) / (x + 1);
				}
				y = (1 / powe) * z;

				totalValue = totalValue + y;
				powe = powe + 2;
				count++;
				z = 1;

			}
			double lnx;
			lnx = 2 * totalValue;
			LNX = lnx;
		}
		else {
			while (count <= it)
			{
				for (int i = 0; i < powe; i++) {
					z *= (x - 1) / (x + 1);
				}
				y = (1 / powe) * z;
				totalValue = totalValue + y;
				powe = powe + 2;
				count++;
				z = 1;
			}
			double lnx;
			lnx = 2 * totalValue;
			LNX = lnx;
		}
		//// ln - 0

		//// sinx - 1
		double xSIN1 = x;
		while (xSIN1 > 2 * pi) {
			xSIN1 = xSIN1 - 2 * pi;
		}
		if (xSIN1 > 0 && xSIN1 < pi / 2) { // 1 четверть +
			double xSIN = x;
			if (xSIN > pi) {
				while (xSIN > pi) {
					xSIN = xSIN - pi;
				}
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = sinx;
			}
			else {
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = sinx;
			}
		}
		else if (xSIN1 >= pi / 2 && xSIN1 < pi) { // 2 четверть +
			double xSIN = x;
			if (xSIN > pi) {
				while (xSIN > pi) {
					xSIN = xSIN - pi;
				}
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = sinx;
			}
			else {
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = sinx;
			}
		}
		else if (xSIN1 >= pi && xSIN1 < 1.5 * pi) { // 3 четверть -
			double xSIN = x;
			if (xSIN > pi) {
				while (xSIN > pi) {
					xSIN = xSIN - pi;
				}
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = -sinx;
			}
			else {
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = -sinx;
			}
		}
		else if (xSIN1 >= 1.5 * pi && xSIN1 < 2 * pi) { // 4 четверть -
			double xSIN = x;
			if (xSIN > pi) {
				while (xSIN > pi) {
					xSIN = xSIN - pi;
				}
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = -sinx;
			}
			else {
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = -sinx;
			}
		}
		//// sinx - 0


		//// cosx - 1
		double xCOS1 = x;
		while (xCOS1 > 2 * pi) {
			xCOS1 = xCOS1 - 2 * pi;
		}
		if (xCOS1 > 0 && xCOS1 < pi / 2) { // 1 четверть +
			double xCOS = x;
			if (xCOS > pi) {
				while (xCOS > pi) {
					xCOS = xCOS - pi;
				}
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = cosx;
			}
			else {
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = cosx;
			}
		}
		else if (xCOS1 >= pi / 2 && xCOS1 < pi) { // 2 четверть -
			double xCOS = x;
			if (xCOS > pi) {
				while (xCOS > pi) {
					xCOS = xCOS - pi;
				}
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = -cosx;
			}
			else {
				double cosx;
				xCOS = xCOS - pi;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = -cosx;
			}
		}
		else if (xCOS1 >= pi && xCOS1 < 1.5 * pi) { // 3 четверть -
			double xCOS = x;
			if (xCOS > pi) {
				while (xCOS > pi) {
					xCOS = xCOS - pi;
				}
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = -cosx;
			}
			else {
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = -cosx;
			}
		}
		else if (xCOS1 >= 1.5 * pi && xCOS1 < 2 * pi) { // 4 четверть +
			double xCOS = x;
			if (xCOS > pi) {
				while (xCOS > pi) {
					xCOS = xCOS - 2 * pi;
				}
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = cosx;
			}
			else {
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = cosx;
			}
		}
		//// cosx - 0

		
		//cout << "lnx: " << LNX << endl << "sinx: " << SINX << endl << "cosx: " << COSX << endl << endl;
		if (LNX < SINX && LNX < COSX) {
			cout << "Функция lnx является наименьшей, и равной " << LNX << endl;
		}
		else if (SINX < LNX && SINX < COSX) {
			cout << "Функция sinx является наименьшей, и равной " << SINX << endl;
		}
		else if (COSX < LNX && COSX < SINX) {
			cout << "Функция cosx является наименьшей, и равной " << COSX << endl;
		}
	}
	else if (x < 0) {

		//// ln - 1
		double count = 1, totalValue = 0, it = 1000, xLN = -x, z = 1, powe = 1, y;
		if (xLN < 0) {
			xLN = -xLN;
			while (count <= it)
			{
				for (int i = 0; i < powe; i++) {
					z *= (-x - 1) / (-x + 1);
				}
				y = (1 / powe) * z;

				totalValue = totalValue + y;
				powe = powe + 2;
				count++;
				z = 1;
			}
			double lnx;
			lnx = 2 * totalValue;
			LNX = lnx;
		}
		else {
			while (count <= it)
			{
				for (int i = 0; i < powe; i++) {
					z *= (-x - 1) / (-x + 1);
				}
				y = (1 / powe) * z;
				totalValue = totalValue + y;
				powe = powe + 2;
				count++;
				z = 1;
			}
			double lnx;
			lnx = 2 * totalValue;
			LNX = lnx;
		}
		//// ln - 0


		//// sinx - 1
		double xSIN1 = -x;
		while (xSIN1 > 2 * pi) {
			xSIN1 = xSIN1 - 2 * pi;
		}
		if (xSIN1 > 0 && xSIN1 < pi / 2) { // 1 четверть +
			double xSIN = -x;
			if (xSIN > pi) {
				while (xSIN > pi) {
					xSIN = xSIN - pi;
				}
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = -sinx;
			}
			else {
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = -sinx;
			}
		}
		else if (xSIN1 >= pi / 2 && xSIN1 < pi) { // 2 четверть +
			double xSIN = -x;
			if (xSIN > pi) {
				while (xSIN > pi) {
					xSIN = xSIN - pi;
				}
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = -sinx;
			}
			else {
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = -sinx;
			}
		}
		else if (xSIN1 >= pi && xSIN1 < 1.5 * pi) { // 3 четверть -
			double xSIN = -x;
			if (xSIN > pi) {
				while (xSIN > pi) {
					xSIN = xSIN - pi;
				}
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = sinx;
			}
			else {
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = sinx;
			}
		}
		else if (xSIN1 >= 1.5 * pi && xSIN1 < 2 * pi) { // 4 четверть -
			double xSIN = -x;
			if (xSIN > pi) {
				while (xSIN > pi) {
					xSIN = xSIN - pi;
				}
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = sinx;
			}
			else {
				double sinx;
				sinx = (16 * xSIN * (pi - xSIN)) / (5 * pi * pi - 4 * xSIN * (pi - xSIN));
				SINX = sinx;
			}
		}
		//// sinx - 0


		//// cosx - 1
		double xCOS1 = -x;
		while (xCOS1 > 2 * pi) {
			xCOS1 = xCOS1 - 2 * pi;
		}
		if (xCOS1 > 0 && xCOS1 < pi / 2) { // 1 четверть +
			double xCOS = -x;
			if (xCOS > pi) {
				while (xCOS > pi) {
					xCOS = xCOS - pi;
				}
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = cosx;
			}
			else {
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = cosx;
			}
		}
		else if (xCOS1 >= pi / 2 && xCOS1 < pi) { // 2 четверть -
			double xCOS = -x;
			if (xCOS > pi) {
				while (xCOS > pi) {
					xCOS = xCOS - pi;
				}
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = -cosx;
			}
			else {
				double cosx;
				xCOS = xCOS - pi;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = -cosx;
			}
		}
		else if (xCOS1 >= pi && xCOS1 < 1.5 * pi) { // 3 четверть -
			double xCOS = -x;
			if (xCOS > pi) {
				while (xCOS > pi) {
					xCOS = xCOS - pi;
				}
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = -cosx;
			}
			else {
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = -cosx;
			}
		}
		else if (xCOS1 >= 1.5 * pi && xCOS1 < 2 * pi) { // 4 четверть +
			double xCOS = -x;
			if (xCOS > pi) {
				while (xCOS > pi) {
					xCOS = xCOS - 2 * pi;
				}
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = cosx;
			}
			else {
				double cosx;
				cosx = (pi * pi - 4 * xCOS * xCOS) / (pi * pi + xCOS * xCOS);
				COSX = cosx;
			}
		}
		//// cosx - 0

		
		//cout << "lnx: " << LNX << endl << "sinx: " << SINX << endl << "cosx: " << COSX << endl << endl;
		if (LNX < SINX && LNX < COSX) {
			cout << "Функция lnx является наименьшей, и равной " << LNX << endl;
		}
		else if (SINX < LNX && SINX < COSX) {
			cout << "Функция sinx является наименьшей, и равной " << SINX << endl;
		}
		else if (COSX < LNX && COSX < SINX) {
			cout << "Функция cosx является наименьшей, и равной " << COSX << endl;
		}
	}
	return 0;
}