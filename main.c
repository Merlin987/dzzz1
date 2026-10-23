/*
Студент : Сорокин Максим Олегович
Группа : ПИ 1-1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void inputArray(int array[], int size);
void printArray(const int array[], int size);
int findMin(const int array[], int size);
int findMax(const int array[], int size);
long long calculateSum(const int array[], int size);
double calculateAverage(const int array[], int size);
int countPositive(const int array[], int size);
int countNegative(const int array[], int size);
int countZero(const int array[], int size);
int countEven(const int array[], int size);
int countOdd(const int array[], int size);
void printInRange(const int array[], int size, int lower, int upper);
void performIndividualTask(const int array[], int size);

int main(void)
{
    int array[MAX_SIZE];
    int size;
    int lower, upper;

    printf("Введите размер массива от 1 до %d: ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE)
    {
        printf("Ошибка: недопустимый размер массива.\n");
        return 1;
    }

    inputArray(array, size);

    printf("Массив: ");
    printArray(array, size);

    int minIndex = findMin(array, size);
    int maxIndex = findMax(array, size);
    printf("Минимум = %d, индекс = %d\n", array[minIndex], minIndex);
    printf("Максимум = %d, индекс = %d\n", array[maxIndex], maxIndex);

    printf("Сумма = %lld\n", calculateSum(array, size));
    printf("Среднее = %.2f\n", calculateAverage(array, size));

    printf("Положительных: %d\n", countPositive(array, size));
    printf("Отрицательных: %d\n", countNegative(array, size));
    printf("Нулевых: %d\n", countZero(array, size));
    printf("Чётных: %d\n", countEven(array, size));
    printf("Нечётных: %d\n", countOdd(array, size));

    printf("Введите границы диапазона a и b: ");
    if (scanf("%d %d", &lower, &upper) != 2)
    {
        printf("Ошибка: границы должны быть целыми числами.\n");
        return 1;
    }
    printInRange(array, size, lower, upper);

    performIndividualTask(array, size);

    return 0;
}


void inputArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("array[%d]: ", i);
        if (scanf("%d", &array[i]) != 1)
        {
            printf("Ошибка: нужно ввести целое число.\n");
            exit(1);
        }
    }
}


void printArray(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int findMin(const int array[], int size)
{
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (array[i] < array[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}


int findMax(const int array[], int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (array[i] > array[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

long long calculateSum(const int array[], int size)
{
    long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}


double calculateAverage(const int array[], int size)
{
    return (double)calculateSum(array, size) / size;
}

int countPositive(const int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0)
        {
            count++;
        }
    }
    return count;
}

int countNegative(const int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < 0)
        {
            count++;
        }
    }
    return count;
}

int countZero(const int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == 0)
        {
            count++;
        }
    }
    return count;
}

int countEven(const int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}


int countOdd(const int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 != 0)
        {
            count++;
        }
    }
    return count;
}


void printInRange(const int array[], int size, int lower, int upper)
{
    if (lower > upper)
    {
        printf("Ошибка: левая граница больше правой.\n");
        return;
    }
    printf("Элементы из диапазона [%d, %d]:", lower, upper);
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] >= lower && array[i] <= upper)
        {
            printf(" %d", array[i]);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf(" таких элементов нет");
    }
    printf("\n");
}



void performIndividualTask(const int array[], int size)
{
    int found = 0;

    printf("Локальные максимумы:\n");
    for (int i = 1; i < size - 1; i++)
    {
        if (array[i] > array[i - 1] && array[i] > array[i + 1])
        {
            printf("array[%d] = %d\n", i, array[i]);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("Локальных максимумов нет.\n");
    }
}
