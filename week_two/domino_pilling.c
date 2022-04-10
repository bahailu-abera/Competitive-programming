#include <stdio.h>


/**
 * main - place as many dominoes as possible on the board 
 * 
 * Return: number of possible dominoes
 */
 
int main(void)
{
	int n, m, num;
	
	scanf("%d%d", &n, &m);
	
	num = ((n / 2) * m) + ((n % 2) * m / 2);
	
	printf("%d", num);
	
	return (0);
}
	
