//
// Created by stasc on 13.12.2022.
//

#include "library.h"

#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int length(const char* str)
{
    int size = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        size++;
        i++;
    }
    size--;
    return size;
}

void merge_sort(int* mas, int l, int r)
{
    if (l == r) return; // границы сомкнулись
    int mid = (l + r) / 2; // определяем середину последовательности
    // и рекурсивно вызываем функцию сортировки для каждой половины
    merge_sort(mas, l, mid);
    merge_sort(mas, mid + 1, r);
    int i = l;  // начало первого пути
    int j = mid + 1; // начало второго пути
    int* tmp = (int*)malloc(1 * sizeof(int)); // дополнительный массив
    for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
    {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        if ((j > r) || ((i <= mid) && (mas[i] > mas[j])))
        {
            tmp[step] = mas[i];
            i++;
        }
        else
        {
            tmp[step] = mas[j];
            j++;
        }
    }
    // переписываем сформированную последовательность в исходный массив
    for (int step = 0; step < r - l + 1; step++)
        mas[l + step] = tmp[step];
}

char** sorting(char** str, const int* mas, int argc)
{
    char* temp;
    for (int i = 0; i < argc - 1; i++)
        for (int j = 0; j < argc - 1; j++)
            if (mas[j] == length(str[i]))
            {
                temp = (char*)calloc(mas[j], sizeof(char));
                temp = str[j];
                str[j] = str[i];
                str[i]=temp;
            }
    return str;
}

int getSize(const char* string)
{
    int i = 0;
    while (true)
    {
        if (string[i] >= 'a' && string[i] <= 'z' || string[i] >= 'A' && string[i] <= 'Z' || string[i] == ' ')
        {
            i++;
        }
        else
            return i;
    }
}

char* copyString(const char* argv, char* string)
{
    int size = getSize(argv);
    int i = 0;
    string = (char*)calloc(size, sizeof(char));
    while (argv[i] != '\0') {
        string[i] = argv[i];
        i++;
    }
    return string;
}

void printArr(const int* arr, int argc)
{
    printf("arr =");
    for (int i = 0; i < argc - 1; i++)
        printf("%d; ", arr[i]);
    printf("\n");
}

void printStrings(int argc, char** strings)
{
    for (int i = 0; i < argc - 1; i++)
        printf("%s\n", strings[i]);
}
