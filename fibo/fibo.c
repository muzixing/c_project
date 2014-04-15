#include "fibo.h"
#include <stdlib.h>
#include <stdio.h>

int fibo_recur (int n)
{
	if (0<=n&& n<=2)
	{
		return 1;
	}
	else
	{
		return fibo_recur(n-1)+fibo_recur(n-2);
	}
}

int fibo(int n)
{	
	int a[n];
	a[0]=a[1]=1;
	int i;
	for (i = 2; i < n; ++i)
	{	
		//printf("%d\n", i);
		a[i] = a[i-1]+a[i-2];
	}
	return a[n-1];
}