#include <stdio.h>
#include "..\..\ValidationLib\inputNatural.h";

/* В-1
Составить алгоритм,  определяющий  количество способов,
какими   задуманное число n>1 можно представить
в виде  суммы  n=i^3+j^3,  считая, что перестановка слагаемых
нового способа не даёт.
*/

void main() 
{
	int n = inputNatural("n = ");
	while (n <= 1) {
		printf("Wrong input\n");
		n = inputNatural("n = ");
	}

	int k = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i*i*i + j*j*j == n) 
				k++;
	printf("Number of ways = %d\n", k);
}