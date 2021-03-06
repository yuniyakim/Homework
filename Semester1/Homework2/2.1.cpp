#include "pch.h"
#include <stdio.h> 

int recursiveFibonachi(int n)
{
	if ((n == 1) || (n == 2))
	{
		return 1;
	}
	else
	{
		return (recursiveFibonachi(n - 2) + recursiveFibonachi(n - 1));
	}
}

int iterativeFibonachi(int n)
{ 
	if ((n == 1) || (n == 2))
	{
		return 1;
	}
	else
	{
		int n1 = 1;
		int n2 = 1;
		for (int i = 3; i <= n; ++i)
		{
			n2 = n1 + n2;
			n1 = n2 - n1;
		}
		return n2;
	}
}

void test()
{
	if ((recursiveFibonachi(1) == 1) && (recursiveFibonachi(5) == 5) && (iterativeFibonachi(2) == 1) && (iterativeFibonachi(7) == 13))
	{
		printf("Test passed\n");
	}
	else
	{
		printf("Test failed\n");
	}
}

int main()
{
	test();
	int n = 0;
	printf("Enter n > 0 ");
	scanf("%u", &n);
	printf("%u", recursiveFibonachi(n));
	printf("\n");
	printf("%u", iterativeFibonachi(n));
	return 0;
}