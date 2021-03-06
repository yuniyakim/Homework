#include "pch.h"
#include <stdio.h>
#include <cstdlib>

void printMass(int mass[], int low, int high)
{
	for (int i = low; i < high; ++i)
	{
		printf("mass[%u] = %u\n", i, mass[i]);
	}
	printf("\n");
}

int numberSize(int mass[], int n)
{
	for (int i = 0; (mass[i] == 0) && (n != 0); ++i)
	{
		--n;
	}
	return n;
}

int theFirstNumberOfNumber(int mass[], int n) // определяем первый значимый разряд двоичного числа
{
	if (numberSize(mass, n) < n)
	{
		return 0 + (n - numberSize(mass, n));
	}
	else
	{
		return 0;
	}
}

int theLargerNumber(int mass1[], int n, int mass2[], int k)
{
	if (numberSize(mass1, n) > numberSize(mass2, k))
	{
		return 1;
	}
	else
	{
		if (numberSize(mass1, n) < numberSize(mass2, k))
		{
			return 2;
		}
		else
		{
			int i = 0;
			while (mass1 [theFirstNumberOfNumber(mass1, n) - i] == mass2[theFirstNumberOfNumber(mass2, k) - i])
			{
				++i;
			}
			if ((i == n) && (i == k))
			{
				return 0;
			}
			else
			{
				if (mass1[i] > mass2[i])
				{
					return 1;
				}
				else
				{
					return 2;
				}
			}
		}
	}
}

void test()
{
	int massTest1[6]{ 1, 0, 1, 1, 0, 0 };
	int massTest2[6]{ 1, 0, 1, 0, 1, 1 };
	int massTest3[8]{ 0, 0, 1, 1, 0, 0, 0, 0 };
	if ((numberSize(massTest3, 8) == 6) && (theLargerNumber(massTest1, 6, massTest2, numberSize(massTest2, 6)) == 1) && (theLargerNumber(massTest1, 6, massTest3, 8) == 2))
	{
		printf("Test passed\n");
	}
	else
	{
		printf("Test failed\n");
	}
	printf("\n");
}

int main()
{
	test();

	int n = 0;
	int k = 0;

	printf("Enter the amount of numbers in the first number n = ");
	scanf("%u", &n);
	
	int *mass1 = new int[n];
	
	printf("Enter the amount of numbers in the second number k = ");
	scanf("%u", &k);

	int *mass2 = new int[k];


	for (int i = 0; i < n; ++i) // заполняем массив1 случайными числами
	{
		mass1[i] = rand() % 2;
	}

	for (int i = 0; i < k; ++i) // заполняем массив2 случайными числами
	{
		mass2[i] = rand() % 2;
	}

	printMass(mass1, 0, n);

	printMass(mass2, 0, k);

	printf("The amount of numbers in the first number is %u\nThe amount of numbers in the second number is %u \n", numberSize(mass1, n), numberSize(mass2, k));

	printf("\n");

	if (theLargerNumber(mass1, n, mass2, k) == 1)
	{
		printf("The first number is larger than the second number");
	}
	else
	{
		if (theLargerNumber(mass1, n, mass2, k) == 2)
		{
			printf("The second number is larger than the first number");
		}
		else
		{
			printf("The numbers are equal");
		}
	}

	delete[] mass1;
	delete[] mass2;
	return 0;
}