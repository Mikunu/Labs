#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251");
	system("cls");
	printf("��������� 2_1\n\n");

	float x, y;
	printf("������� x: ");
	scanf_s("%f", &x);
	printf("������� y: ");
	scanf_s("%f", &y);

	if (x > 0 && y > 0)
	{
		printf("I ��������");
	}
	else if (x < 0 && y > 0)
	{
		printf("II ��������");
	}
	else if (x < 0 && y < 0)
	{
		printf("III ��������");
	}
	else if (x > 0 && y < 0)
	{
		printf("IV ��������");
	}
	else if (x == 0 && y != 0)
	{
		printf("�� ��� y");
	}
	else
	{
		printf("�� ��� x");
	}
	printf("\n\n");
	printf("��������� 2_2\n\n");
	int day, month;
	printf("������� ����: ");
	scanf_s("%d", &day);
	printf("������� �����: ");
	scanf_s("%d", &month);
	switch (day)
	{
	case 1: printf("������"); break;
	case 2: printf("������"); break;
	case 3: printf("������"); break;
	case 4: printf("���������"); break;
	case 5: printf("�����"); break;
	case 6: printf("������"); break;
	case 7: printf("�������"); break;
	case 8: printf("�������"); break;
	case 9: printf("�������"); break;
	case 10: printf("�������"); break;
	case 11: printf("������������"); break;
	case 12: printf("�����������"); break;
	case 13: printf("�����������"); break;
	case 14: printf("�������������"); break;
	case 15: printf("�����������"); break;
	case 16: printf("������������"); break;
	case 17: printf("�����������"); break;
	case 18: printf("�������������"); break;
	case 19: printf("�������������"); break;
	case 20: printf("���������"); break;
	case 21: printf("�������� ������"); break;
	case 22: printf("�������� ������"); break;
	case 23: printf("�������� ������"); break;
	case 24: printf("�������� ��������"); break;
	case 25: printf("�������� �����"); break;
	case 26: printf("�������� ������"); break;
	case 27: printf("�������� �������"); break;
	case 28: printf("�������� �������"); break;
	case 29: printf("�������� �������"); break;
	case 30: printf("���������"); break;
	case 31: printf("�������� ������"); break;
	default: printf("�����-�� �����");
	}
	switch (month)
	{
	case 1: printf(" ������"); break;
	case 2: printf(" �������"); break;
	case 3: printf(" �����"); break;
	case 4: printf(" ������"); break;
	case 5: printf(" ���"); break;
	case 6: printf(" ����"); break;
	case 7: printf(" ����"); break;
	case 8: printf(" �������"); break;
	case 9: printf(" ��������"); break;
	case 10: printf(" ������"); break;
	case 11: printf(" ������"); break;
	case 12: printf(" �������"); break;
	}
	return 0;
}