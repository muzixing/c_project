#include <stdlib.h>
#include <stdio.h>
#include "fibo.h"

int main()
{
	int num = fibo(5);
	printf("%d\n", num);
	int num_1 = fibo_recur(5);
	printf("%d\n", num_1);
	return 0;
}