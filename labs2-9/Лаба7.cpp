#include <iostream>
#include <math.h>
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

void PifagorTable()
{
	int table[9][9];
	for (int i = 1; i < 10; i++)
	{
		for (int  x = 1; x < 10; x++)
		{
			table[i-1][x-1] = i*x;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (table[i][x] < 10) { printf(" %d ", table[i][x]); }
			else { printf("%d ", table[i][x]); }
		}
		printf("\n");
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int matrix[6][8] = { {7, 6, 9, 1, 2, 0, 5, 1}, {1, 9, 1, 5, 6, 0, 1, 9},
		{6, 3, 9, 3, 6, 8, 6, 8}, {3, 3, 9, 2, 1, 7, 3, 1}, {8, 3, 6, 6, 1, 1, 7, 7}, {3, 6, 7, 4, 5, 1, 9, 8} };
	int* min = new int[6];
	int* max = new int[8];
	int k;

	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			printf("%d ", matrix[i][k]);
		}
		printf("\n");
	}

	for (int i = 0; i < 6; i++)
	{
		min[i] = INT_MAX;
		for (int j = 0; j < 8; j++)
		{
			if (matrix[i][j] < min[i])
			{
				min[i] = matrix[i][j];
			}
		}
	}
	for (int j = 0; j < 8; j++)
	{
		max[j] = INT_MIN;
		for (int i = 0; i < 6; i++)
		{
			if (matrix[i][j] > max[j])
			{
				max[j] = matrix[i][j];
			}
		}
	}
	printf("\nИндексы седловых точек: ");
	k = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (min[i] == max[j])
			{
				printf("%d%d\n", i, j);
				k++;
			}
		}
	}
	if (!(k))
	{
		printf("Седловых точек нет!\n");
	}

	printf("Подождите 5 секунд для вывода следующей части");
	Sleep(5000);
	system("cls");
	PifagorTable();
	
	printf("Подождите 5 секунд для вывода следующей части");
	Sleep(5000);
	system("cls");

	FirstPart();
	return 0;
}



