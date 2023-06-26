#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
	if(!n) return 1;
	else return n*fact(n-1);
}

int main()
{
	int a;
	scanf("%d",&a);
	printf("factoriel(a) = %d",fact(a));
}
