#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(int argc, char** argv)
{
    char** str = (char**)calloc(argc - 1, sizeof(char*));
    int* arr = (int*)calloc(argc - 1, sizeof(int));
    for (int i = 1; i < argc; i++)
        str[i - 1] = copyString(argv[i], str[i - 1]);
    for (int i = 0; i < argc - 1; i++)
        arr[i] = length(str[i]);
    merge_sort(arr, 0, argc - 1);
    printf("Result::\n");
    str = sorting(str, arr, argc);
    printStrings(argc, str);
    return 0;
}
