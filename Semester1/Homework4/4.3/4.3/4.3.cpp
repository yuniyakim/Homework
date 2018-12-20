#include "pch.h"
#include <stdio.h>
#include <iostream>

struct records
{
	char name[50] = "";
	char phoneNumber[20] = "";
};

records record[100];

int numberOfRecords = 0;

void printCommands()
{
	printf("0 - выйти\n1 - добавить запись (имя и телефон)\n2 - распечатать все имеющиеся записи\n3 - найти телефон по имени\n4 - найти имя по телефону\n5 - сохранить текущие данные в файл\n");
}

void commands(int input)
{
	switch (input)
	{
	case 1:
	{
		char newName[50]{ 0 };
		char newPhoneNumber[20]{ 0 };
		printf("Введите имя ");
		scanf("%s", newName);
		strcpy(record[numberOfRecords].name, newName);
		printf("Введите номер телефона ");
		scanf("%s", newPhoneNumber);
		strcpy(record[numberOfRecords].phoneNumber, newPhoneNumber);
		++numberOfRecords;
		printf("\n");
		break;
	}
	case 2:
	{
		for (int i = 0; i < numberOfRecords; ++i)
		{
			printf("%u. Имя: %s; телефон: %s\n", i + 1, record[i].name, record[i].phoneNumber);
		}
		printf("\n");
		break;
	}
	case 3:
	{
		char neededName[50] = "";
		int numberOfNeeded = 0;
		printf("Введите имя ");
		scanf("%s", neededName);
		while ((numberOfNeeded <= numberOfRecords) && (strcmp(neededName, record[numberOfNeeded].name) != 0))
		{
			++numberOfNeeded;
		}
		if (numberOfNeeded > numberOfRecords)
		{
			printf("Запись не найдена\n");
			printf("\n");
			break;
		}
		else
		{
			printf("Номер телефона: %s\n", record[numberOfNeeded].phoneNumber);
			printf("\n");
			break;
		}
	}
	case 4:
	{
		char neededPhoneNumber[20]{ 0 };
		int numberOfNeeded = 0;
		printf("Введите номер телефона ");
		scanf("%s", &neededPhoneNumber);
		while ((numberOfNeeded <= numberOfRecords) && (strcmp(neededPhoneNumber, record[numberOfNeeded].phoneNumber) != 0))
		{
			++numberOfNeeded;
		}
		if (numberOfNeeded > numberOfRecords)
		{
			printf("Запись не найдена\n");
			printf("\n");
			break;
		}
		else
		{
			printf("Имя: %s\n", record[numberOfNeeded].name);
			printf("\n");
			break;
		}
	}
	case 5:
	{
		FILE *file = fopen("4.3.txt", "w");
		for (int i = 0; i < numberOfRecords; ++i)
		{
			fprintf(file, "%s %s\n", record[i].name, record[i].phoneNumber);

		}
		fclose(file);
		printf("Данные сохранены.\n");
		printf("\n");
		break;
	}
	default:
	{
		printf("Введена неверная команда.\n");
		printf("\n");
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	FILE *file = fopen("4.3.txt", "a+");
	
	char *bufferName = new char[50];
	char *bufferPhoneNumber = new char[20];

	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	if (size != 0)
	{
		fseek(file, 0, SEEK_SET);
		for (int i = 0; (!feof(file)) && (i < 100); ++i)
		{
			fscanf(file, "%s %s", bufferName, bufferPhoneNumber);
			strcpy(record[i].name, bufferName);
			strcpy(record[i].phoneNumber, bufferPhoneNumber);
			++numberOfRecords;
		}
	}
	fclose(file);

	delete[] bufferName;
	delete[] bufferPhoneNumber;
	
	int input = 0;
	printCommands();
	scanf("%u", &input);
	while (input != 0)
	{
		commands(input);
		printCommands();
		scanf("%u", &input);
	}
	return 0;
}

//Написать программу - телефонный справочник.Она должна уметь хранить имена и номера телефонов, в интерактивном режиме осуществлять следующие операции :
//0 - выйти
//1 - добавить запись(имя и телефон)
//2 - распечатать все имеющиеся записи
//3 - найти телефон по имени
//4 - найти имя по телефону
//5 - сохранить текущие данные в файл
//При запуске программа должна читать данные из файла, если файла нет - начинать с пустой базы номеров.Размер базы ограничен сотней записей.