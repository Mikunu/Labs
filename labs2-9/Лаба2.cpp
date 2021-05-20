#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251");
	system("cls");
	printf("программа 2_1\n\n");

	float x, y;
	printf("Введите x: ");
	scanf_s("%f", &x);
	printf("Введите y: ");
	scanf_s("%f", &y);

	if (x > 0 && y > 0)
	{
		printf("I квадрант");
	}
	else if (x < 0 && y > 0)
	{
		printf("II квадрант");
	}
	else if (x < 0 && y < 0)
	{
		printf("III квадрант");
	}
	else if (x > 0 && y < 0)
	{
		printf("IV квадрант");
	}
	else if (x == 0 && y != 0)
	{
		printf("На оси y");
	}
	else
	{
		printf("На оси x");
	}
	printf("\n\n");
	printf("программа 2_2\n\n");
	int day, month;
	printf("Введите день: ");
	scanf_s("%d", &day);
	printf("Введите месяц: ");
	scanf_s("%d", &month);
	switch (day)
	{
	case 1: printf("Первое"); break;
	case 2: printf("Второе"); break;
	case 3: printf("Третье"); break;
	case 4: printf("Четвертое"); break;
	case 5: printf("Пятое"); break;
	case 6: printf("Шестое"); break;
	case 7: printf("Седьмое"); break;
	case 8: printf("Восьмое"); break;
	case 9: printf("Девятое"); break;
	case 10: printf("Десятое"); break;
	case 11: printf("Одиннадцатое"); break;
	case 12: printf("Двенадцатое"); break;
	case 13: printf("Тринадцатое"); break;
	case 14: printf("Четырнадцатое"); break;
	case 15: printf("Пятнадцатое"); break;
	case 16: printf("Шестандцатое"); break;
	case 17: printf("Семнадцатое"); break;
	case 18: printf("Восемнадцатое"); break;
	case 19: printf("Девятнадцатое"); break;
	case 20: printf("Двадцатое"); break;
	case 21: printf("Двадцать первое"); break;
	case 22: printf("Двадцать второе"); break;
	case 23: printf("Двадцать третье"); break;
	case 24: printf("Двадцать четвёртое"); break;
	case 25: printf("Двадцать пятое"); break;
	case 26: printf("Двадцать шестое"); break;
	case 27: printf("Двадцать седьмое"); break;
	case 28: printf("Двадцать восьмое"); break;
	case 29: printf("Двадцать девятое"); break;
	case 30: printf("Тридцатое"); break;
	case 31: printf("Тридцать первое"); break;
	default: printf("Какое-то число");
	}
	switch (month)
	{
	case 1: printf(" января"); break;
	case 2: printf(" февраля"); break;
	case 3: printf(" марта"); break;
	case 4: printf(" апреля"); break;
	case 5: printf(" мая"); break;
	case 6: printf(" июня"); break;
	case 7: printf(" июля"); break;
	case 8: printf(" августа"); break;
	case 9: printf(" сентября"); break;
	case 10: printf(" октяря"); break;
	case 11: printf(" ноября"); break;
	case 12: printf(" декабря"); break;
	}
	return 0;
}