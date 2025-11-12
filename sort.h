//демонстраційний коментрар
#ifndef SORT_H
#define SORT_H
#define _CRT_SECURE_NO_WARNINGS 
#include "stringProcessor.h"
#include <string.h> 

void swap(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char** arr, int low, int high)
{
    char* pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (strcmp(arr[j], pivot) <= 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort_recursive(char** arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

void quick_sort(char** arr, size_t length)
{
    if (arr == NULL || length == 0) {
        return;
    }
    quick_sort_recursive(arr, 0, length - 1);
}

#endif 