#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <Windows.h>



double CalculateX(int number = 0, double a = 2, double b = 4, double n = 16)
{
	double x = a;
	double delta = 0;

	int k = 0;

	do
	{
		x += delta;
		delta = (b - a) / (n - 1);
		k++;
	} while (k <= number);

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

bool check(int o, int k, int t)
{
	if (o == k) { return true; }
	else if (t >= 10) { return check(o, t % 10, t / 10); }
	else { return o == t; }
}

int main()
{
	system("chcp 1251");
	system("cls");
	printf("программа 5_1\n\n");

	int value, x;
	printf("Введите число: ");
	scanf_s("%d", &value);
	do
	{
		x = check(value % 10, (value / 10) % 10, value / 10);
		value /= 10;
		if (x == true) { printf("%s", "Одинаковые цифры есть\n"); break; }
	} while (value > 10);
	if (x == false) { printf("%s", "Одинаковых цифр нет\n"); }

	printf("Подождите 5 секунд для вывода следующей части");
	Sleep(5000);
	system("cls");
	FirstPart();

	printf("Подождите 5 секунд для вывода следующей части");
	Sleep(5000);
	system("cls");
	printf("программа 4_1\n\n");

	double xx, a, Y, dxx;
	a = 1.0;
	do
	{
		if (a == 1.0)
		{
			printf("При a = 1.0\n");
			printf(" xx          Y\n");
		}
		else
		{

			printf("При a = 1.5\n");
			printf(" xx          Y\n");
		}

		dxx = a / 5;
		xx = 0.1;

		do
		{
			Y = 1 / xx;
			printf("%lf", xx);
			printf(" ");
			printf("%lf\n", Y);
			xx += dxx;

		} while (xx >= 0.1 && xx <= 0.4);
		do
		{
			Y = log(pow(xx, 2) + a * xx);
			printf("%lf", xx);
			printf(" ");
			printf("%lf\n", Y);
			xx += dxx;
		} while (xx > 0.4 && xx <= 1.2);
		do
		{
			Y = log(pow(xx, 2) + a * xx);
			printf("%lf", xx);
			printf(" ");
			printf("%lf\n", Y);
			xx += dxx;
		} while (xx > 1.2 && xx < 1.6);
		printf("\n\n");
		a += 0.5;
		xx = 0.1;

	} while (a <= 1.5);
	printf("Подождите 5 секунд для вывода следующей части");
	Sleep(5000);

	return 0;

}