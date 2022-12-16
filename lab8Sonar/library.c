//
// Created by stasc on 09.12.2022.
//

#include "library.h"
#include <stdio.h>
#include <stdlib.h>


void merge_sort(int** mas, int l, int r)
{
    if (l == r) return; // границы сомкнулись
    int mid = (l + r) / 2; // определяем середину последовательности
    // и рекурсивно вызываем функцию сортировки для каждой половины
    merge_sort(mas, l, mid);
    merge_sort(mas, mid + 1, r);
    int i = l;  // начало первого пути
    int j = mid + 1; // начало второго пути
    int** tmp = (int**)malloc(2 * sizeof(int*));// дополнительный массив
    tmp[0] = (int*)malloc(r * sizeof(int));
    tmp[1] = (int*)malloc (r*sizeof(int));
    for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
    {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        if ((j > r) || ((i <= mid) && (mas[1][i] > mas[1][j])))
        {
            tmp[0][step] = mas[0][i];
            tmp[1][step] = mas[1][i];
            i++;
        }
        else
        {
            tmp[0][step] = mas[0][j];
            tmp[1][step] = mas[1][j];
            j++;
        }
    }
    // переписываем сформированную последовательность в исходный массив
    for (int step = 0; step < r - l+1; step++)
    {
        mas[0][l + step] = tmp[0][step];
        mas[1][l+step] = tmp[1][step];
    }
}

void sorting(char** str, int** arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%s\n", str[arr[0][i]]);
}

void lengthStr (int** arr, char** str, int size)
{
    int j;
    for(int i = 0; i < size; i++)
    {
        j = 0;
        while(str[i][j] != '\0')
        {
            j++;
        }
        arr[1][i] = j;
    }
}
