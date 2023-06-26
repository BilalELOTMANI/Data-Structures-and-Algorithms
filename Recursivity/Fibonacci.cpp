#include <stdio.h>
#include <stdlib.h>

int Fibon(int n)
{
	if(n==0 || n==1) return n;
	else return Fibon(n-1)+Fibon(n-2);
}

int main()
{
	int a;
	printf("Fibon (.) : ");
	scanf("%d",&a);
	printf("Fibonacci de U%d est : %d",a,Fibon(a));
}
