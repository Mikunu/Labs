#include <iostream>
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <complex.h>
#define ROWS 3
#define COLS 5


double Calculate(int x, int a, int b, int c)
{
    return ((sqrt(fabs(x - a) - pow(abs(x), 1 / 3.0))) / (a + b * pow(x, 3) + c * pow(x, 2)));
}

double complex CalculateComplex(int x, int a, int b, int c)
{
    return ((csqrt(fabs(x - a) - pow(abs(x), 1 / 3.0))) / (a + b * pow(x, 3) + c * pow(x, 2)));
}

int nod(int first, int second)
{
    if (first == second)
    {
        return first;
    }
    if (first > second)
    {
        int temp = first;
        first = second;
        second = temp;
    }
    return nod(first, second - first);
}

int nodfinder(int* source)
{
    int temp1[4];
    int temp2[2];
    for (int i = 0, x = 0; i < 4; i++, x += 2)
    {
        temp1[i] = nod(source[x], source[x + 1]);
    }
    for (int i = 0, x = 0; i < 2; i++, x += 2)
    {
        temp2[i] = nod(temp1[x], temp1[x + 1]);
    }
    return nod(temp2[0], temp2[1]);
}

double geom_avg(int row[COLS]) {
    int result = 1;
    for (int i = 0; i < COLS; ++i) {
        result *= row[i];
    }
    return sqrt(result);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int a = 1;
    int b = 2;
    int c = 4;
    printf("%lf\n", Calculate(0, a, b, c));
    printf("Вычислить с x = 1 невозможно, так как под корнем получается отрицательное значение\n");
    printf("%lf\n", Calculate(1, a, b, c));
    double complex w = CalculateComplex(1, a, b, c);
    printf("%lf+i%lf\n", creal(w), cimag(w));
    printf("Подождите 5 секунд\n");
    Sleep(5000);

    int nums[8] = { 4096, 2048, 1024, 512, 256, 128, 64, 32 };
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\nНОД равен: ");
    printf("%d\n", nodfinder(nums));
    printf("Подождите 5 секунд\n");
    Sleep(5000);

    int e[ROWS][COLS] = { {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5} };
    for (int i = 0; i < ROWS; ++i) {
        printf("%f\n", geom_avg(e[i]));
    }
    return 0;
}



