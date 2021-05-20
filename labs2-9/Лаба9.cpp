#include <iostream>
#include <math.h>
#include <windows.h>
#include <stdio.h>
#define ROWS 5
#define COLS 6

int UseMatrix(int(&matrix)[6][8], bool rd)
{
    int matrixspec[2];
    int* min = new int[6];
    int* max = new int[8];
    int k;

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
    k = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (min[i] == max[j])
            {
                matrixspec[0] = i;
                matrixspec[1] = j;
                k++;
            }
        }
    }
    if (!(k))
    {
        matrixspec[0] = -1;
        matrixspec[1] = -1;
    }


    if (rd == 0) { return matrixspec[0]; }
    else { return matrixspec[1]; }
}

int compare_int_abs(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return abs(ai) - abs(bi);
}

void sort_row(int row[COLS]) {
    qsort(row, COLS, sizeof(int), compare_int_abs);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int matrix[6][8] = { {7, 6, 9, 1, 2, 0, 5, 1}, {1, 9, 1, 5, 6, 0, 1, 9},
        {6, 3, 9, 3, 6, 8, 6, 8}, {3, 3, 9, 2, 1, 7, 3, 1}, {8, 3, 6, 6, 1, 1, 7, 7}, {3, 6, 7, 4, 5, 1, 9, 8} };
    
    for (int i = 0; i < 6; i++)
    {
        for (int k = 0; k < 8; k++)
        {
            printf("%d ", matrix[i][k]);
        }
        printf("\n");
    }

    int x, y;
    x = UseMatrix(matrix, 0);
    y = UseMatrix(matrix, 1);
    if (x > 0)
    {
        printf("Индексы седловых точек: ");
        printf("%d%d", x, y);
    }
    else
    {
        printf("Седловых точек нет!");
    }

    printf("Подождите 5 секунд для вывода следующей части");
    Sleep(5000);
    system("cls");

    int h[ROWS][COLS] = { {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6} };
    int positive = 0;
    int negative = 0;
    for (int i = 0; i < ROWS; ++i) {
        sort_row(h[i]);
        for (int j = 0; j < COLS; ++j) {
            if (h[i][j] > 0) positive++;
            else if (h[i][j] < 0) negative++;
            printf("%d, ", h[i][j]);
        }
        printf("\n");
    }
    printf("Positive: %d, negative: %d", positive, negative);
    return 0;
}



