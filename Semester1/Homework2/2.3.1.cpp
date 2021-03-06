#include "pch.h"
#include <stdio.h>
#include <cstdlib>

void countingSort(int mass[], int n)
{
	int max = 0; // ищем максимум
	for (int i = 0; i < n; ++i)
	{
		if (mass[i] > max)
		{
			max = mass[i];
		}
	}

	int min = 10000; // ищем минимум
	for (int i = 0; i < n; ++i)
	{
		if (mass[i] < min)
		{
			min = mass[i];
		}
	}

	int *help = new int[max - min + 1]; // создаем и обнуляем вспомогательный массив
	for (int i = 0; i < max - min + 1; ++i)
	{
		help[i] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		++help[mass[i] - min];
	}

	int m = 0; // вспомогательная переменная, обозначающая номер элемента в исходном массиве mass[]
	for (int k = min; k <= max; ++k)
	{
		while (help[k - min] != 0)
		{
			mass[m] = k;
			--help[k - min];
			m++;
		}
	}

	delete[] help;
}

void test(int *mass, int n)
{
	int help = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (mass[i] > mass[i + 1])
		{
			printf("Element number %u is in the wrong place\n", i);
			++help;
		}
	}
	if (help == 0)
	{
		printf("Test passed\n");
	}
}

int main()
{
	int n = 0;

	printf("Enter the number of elements in your massive ");
	scanf("%u", &n);

	int *mass = new int[n];

	for (int i = 0; i < n; ++i) // заполняем массив случайными числами
	{
		mass[i] = rand() % 11;
		printf("mass[%u] = %u\n", i, mass[i]);
	}
	printf("\n");

	countingSort(mass, n);

	test(mass, n);

	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		printf("mass[%u] = %u\n", i, mass[i]);
	}

	delete[] mass;
	return 0;
}