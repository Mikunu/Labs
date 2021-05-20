#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

double CalculateX(int number = 0, double a = 2, double b = 4, double n = 16)
{
	double x = a;
	double delta = 0;

	for (int k = 0; k <= number; k++)
	{
		x += delta;
		delta = (b - a) / (n - 1);
	}

	return x;
}

double CalculateF(int number = 0, bool first = true)
{
	double F;
	double x = CalculateX(number);

	if (first == true)
	{
		F = pow(2, x) * log10(x) - pow(3, x) * log10(x);
	}
	else
	{
		F = cos(x) / sin(x);
	}

	return F;
}

void table(double(&MasterArray)[16][3], int n = 16)
{
	system("cls");
	int columns = 4;
	int lines = n;
	printf("%s", " ");
	for (int k = 0; k < columns * 10 + 4; k++)
	{
		printf("%s", "_");
	}
	printf("%s\n", "_");
	printf("|  N  |      X    |      F1     |      F2     | \n");
	printf("|-----|-----------|-------------|-------------| \n");

	for (int l = 0; l < lines; l++)
	{
		printf("%s", "|  ");
		printf("%u", l + 1);
		if (l < 9) { printf("%s", "  "); }
		else { printf("%s", " "); }
		printf("%s", "|  ");
		printf("%f", MasterArray[l][0]);
		printf("%s", " |  ");
		printf("%f", MasterArray[l][1]);
		if (l < 8) { printf("%s", "  |  "); }
		else if (l == 9) { printf("%s", " |  "); }
		else { printf("%s", " |  "); }
		printf("%f", MasterArray[l][2]);
		if (l < 8) { printf("%s\n", "  |"); }
		else if (l == 8) { printf("%s\n", " |"); }
		else if (l == 9) { printf("%s\n", "  |"); }
		else { printf("%s\n", "   |"); }
	}

	printf("%s", "|");
	for (int k = 0; k < columns * 10 + 4; k++)
	{
		printf("%s", "_");
	}
	printf("%s\n", "_|");

}

void FirstPart()
{
	system("cls");
	const int n = 16;
	double MasterArray[16][3];
	bool first;

	for (int i = 0; i < 16; i++)
	{
		MasterArray[i][0] = CalculateX(i);
		first = true;
		MasterArray[i][1] = CalculateF(i, first);
		first = false;
		MasterArray[i][2] = CalculateF(i, first);
	}

	table(MasterArray);
}


int main() 
{
	system("chcp 1251");
	system("cls");
	printf("программа 3_1\n\n");

	double x, Z;
	int n;
	Z = 0;

	printf("Введите x: ");
	scanf_s("%lf", &x);

	while (fabs(x) > 1) 
	{
		printf("Неверное значение x, пробуйте снова\n");
		printf("Введите x: ");
		scanf_s("%lf", &x);
	}
	printf("Введите n: ");
	scanf_s("%d", &n);
	printf("\n\n");

	for (int i = 1; i <= n; i++)
	{
		Z += pow(-1, i-1)*pow(x, i) / i;
	}
	printf("Ряд Тейлора: ");
	printf("%lf\n", Z);
	Z = log(1 + x);
	printf("Обычное вычисление: ");
	printf("%lf", Z);

	Sleep(2000);


	system("cls");
	printf("программа 3_2, программа 3_3");
	Sleep(1000);
	system("cls");
	FirstPart();

	return 0;

}