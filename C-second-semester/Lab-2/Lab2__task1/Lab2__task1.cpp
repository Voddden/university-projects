#include <stdio.h>
#include <locale.h>

/* В-1
Сколько слагаемых должно быть  в  сумме  1+1/2+1/3+1/4+...+1/n,
чтобы эта сумма оказалась больше 5 ?
*/

void main() 
{
	setlocale(LC_ALL, "ru");
	float sum = 0;
	int i = 1;
	for (; sum <= 5; ++i) {
		sum += 1.0 / (float)i;
	}

	printf("Нужно %d слагаемых\n", i);
}