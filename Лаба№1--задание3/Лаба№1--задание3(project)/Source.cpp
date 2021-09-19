/*
На вход даны 6 чисел x1, y1; x2, y2; x3, y3 - координаты вершин А, В, С
соответственно. Необходимо вычислить:
1. Длину всех сторон треугольника.
2. Длину всех высот треугольника.
3. Длину всех медиан треугольника.
4. Длину всех биссектрис треугольника.
5. Градусную и радианную меру углов треугольника.
6. Радиусы вписанной и описанной окружностей треугольника.
7. Найти площадь и длину этих окружностей.
8. Площадь и периметр треугольника.
Примечание. Гарантируется существование треугольника с данными
координатами. При выводе чисел необходимо обозначать, какие именно
параметры вы выводите. Площадь треугольника считать минимум 3
способами.
*/
#include <iostream>
using namespace std;
#include <cmath>

int main() {
	setlocale(LC_ALL, "Rus");
	double Ax, Ay, Bx, By, Cx, Cy; // A, B, C - вершины треугольника
	cout << "Введите координаты вершин треугольника\n";
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
	double AB, BC, AC; // AB, BC, AC - стороны треугольника
	AB = sqrt(pow(Bx - Ax, 2) + pow(By - Ay, 2));
	BC = sqrt(pow(Cx - Bx, 2) + pow(Cy - By, 2));
	AC = sqrt(pow(Cx - Ax, 2) + pow(Cy - Ay, 2));
	cout << "Пусть A - первая точка, B - вторая точка, C - третья точка.\n" << "1) Тогда AB = " << AB << ", BC = " << BC << ", AC = " << AC << endl;
	double p, S; // p - полупериметр, S - площадь
	p = (AB + BC + AC) / 2;
	S = sqrt(p * (p - AB) * (p - BC) * (p - AC)); // 1-ый способ нахождения площади
	double hAB, hBC, hAC; // hAB - высота к AB, hBC - высота к BC, hAC - высота к AC
	hAB = 2 * S / AB;
	hBC = 2 * S / BC;
	hAC = 2 * AC / AC;
	cout << "2) Высота к AB равна " << hAB << ", высота к BC равна " << hBC << ", высота к AC равна " << hAC << endl;
	double mAB, mBC, mAC; // mAB - медиана к AB, mBC - медиана к BC, mAC - медиана к AC
	mAB = 0.5 * sqrt(2 * pow(AC, 2) + 2 * pow(BC, 2) - AB);
	mBC = 0.5 * sqrt(2 * pow(AC, 2) + 2 * pow(AB, 2) - BC);
	mAC = 0.5 * sqrt(2 * pow(BC, 2) + 2 * pow(AB, 2) - AC);
	cout << "3) Медиана к AB равна " << mAB << ", медиана к BC равна " << mBC << ", медиана к AC равна " << mAC << endl;
	double bAB, bBC, bAC; // bAB - биссектриса к AB, bBC - биссектриса к BC, bAC - биссектриса к AC
	bAB = (2 * sqrt(AC * BC * p * (p - AB))) / (AC + BC);
	bBC = (2 * sqrt(AB * AC * p * (p - BC))) / (AB + AC);
	bAC = (2 * sqrt(AB * BC * p * (p - AC))) / (AB + BC);
	cout << "4) Биссектриса к AB равна " << bAB << ", биссектриса к BC равна " << bBC << ", биссектриса к AC равна " << bAC << endl;
	double cosAB, cosBC, cosAC; // cosAB - косинус угла, лежащего напротив AB; cosBC - косинус угла, лежащего напротив BC; cosAC - косинус угла, лежащего напротив AC
	cosAB = (pow(BC, 2) + pow(AC, 2) - pow(AB, 2)) / (2 * BC * AC);
	cosBC = (pow(AB, 2) + pow(AC, 2) - pow(BC, 2)) / (2 * AB * AC);
	cosAC = (pow(AB, 2) + pow(BC, 2) - pow(AC, 2)) / (2 * AB * BC);
	double radAB, radBC, radAC; // radAB - угол напротив AB, radBC - угол напротив BC, radAC - угол напротив AC. В радианах
	radAB = acos(cosAB);// 
	radBC = acos(cosBC);//  радианная мера
	radAC = acos(cosAC);// 
	double angAB, angBC, angAC; // angAB - угол напротив AB, angBC - угол напротив BC, angAC - угол напротив AC. В обычных углах
	angAB = radAB * 57.2958; // 
	angBC = radBC * 57.2958; // перевод из радиан в углы
	angAC = radAC * 57.2958; //
	cout << "5) Значения углов\n" << "--- В обычных углах:\n";
	cout << "угол ABC = " << angAC << endl << "угол BCA = " << angAB << endl << "угол BAC = " << angBC << endl;
	cout << "--- В радианах:\n";
	cout << "угол ABC = " << radAC << endl << "угол BCA = " << radAB << endl << "угол BAC = " << radBC << endl;
	double R, r; // r - радиус вписанной окружности, R - радиус описанной 
	r = S / p;
	R = (AB * BC * AC) / (4 * S);
	cout << "6) Радиус вписанной окружности равен " << r << ", радиус описанной равен " << R << endl;
	double Scir_in, Scir_around, Lcir_in, Lcir_around; // площади и длины окружностей
	Scir_in = 3.1415926535 * r * r;
	Scir_around = 3.1415926535 * R * R;
	Lcir_in = 2 * 3.1415926535 * r;
	Lcir_around = 2 * 3.1415926535 * R;
	cout << "Площадь вписанной окружности равна " << Scir_in << ", её длина " << Lcir_in << endl;
	cout << "Площадь описанной окружности равна " << Scir_around << ", её длина " << Lcir_around << endl;
	cout << "8) Площадь треугольника равна " << S << ", периметр равен " << 2 * p << endl;
	cout << "9) Три способа нахождения площади треугольника (результаты вычислений)\n";
	S = 0.5 * AB * hAB;
	cout << S << endl;
	S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
	cout << S << endl;
	S = 0.5 * AB * AC * sin(radBC);
	cout << S << endl;
	return 0;
}
/*
Тесты:
3 2 4 7 6 3 (произвольный)
1 7 1 1 5 1 (прямоугольный)
4 5 1 1 7 1 (равнобедренный)
*/
 
