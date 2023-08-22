#include "main.h"

/**
 *print_decimal - function prints decimals
 *@buffer: variable used to store arg
 *@index: variable used as index
 *@n:number to print
 */
void print_decimal(char **buffer, int *index, int n)
{
	
	int power = 1;
	int digit;
	if (n < 0)
	{
		(*buffer)[(*index)++] = '-';
		n = -n;
	}
	if (n == 0)
	{
		(*buffer)[(*index)++] = '0';
		return;
	}
	while (power * 10 <= n)
		power *= 10;
	while (power > 0)
	{
		digit = n / power;
		(*buffer)[(*index)++] = digit + '0';
		n -= digit * power;
		power /= 10;
	}
}
