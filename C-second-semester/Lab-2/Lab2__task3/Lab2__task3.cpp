#include <stdio.h>
#include <locale.h>
#include "..\..\ValidationLib\inputNatural.h";

/* В-1
Проверить являются ли числа P и Q взаимнопростыми
*/

int nod(int m, int n)
{
	while (m != n) {
		if (m > n) {
			m = m - n;
		}
		else {
			n = n - m;
		}
	}
	return m;
}

void main()
{
	setlocale(LC_ALL, "ru");
	int P = inputNatural("P = ");
	int Q = inputNatural("Q = ");

	int NOD = nod(P, Q);

	if (NOD == 1)
		printf("%d и %d взаимнопросты\n", P, Q);
	else
		printf("%d и %d НЕвзаимнопросты\n", P, Q);
}