#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>

int main()
{
	int A[10];
	int n = 0;
	for (int i = 0; i < 10; i++)
	{
		printf("A%d = ", i + 1);
		scanf_s("%d", &A[i]);
		if (A[i] == 0)
		{
			n++;
		}
	}
	printf("The number of 0's is %d", n);
	return 0;
}