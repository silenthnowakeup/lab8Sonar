#include <stdlib.h>
#include "library.h"

int main(int argc, char** argv)
{
    int size = argc - 1;
    char** str = (char**)calloc(argc - 1, sizeof(char*));
    int** arr = (int**)calloc(2, sizeof(int*));
    arr[0] = (int*)calloc(argc - 1, sizeof(int));
    arr[1] = (int*)calloc(argc - 1, sizeof(int));
    for(int i = 0; i < size; i++)
        arr[0][i] = i;
    for(int i = 1; i < argc; i++)
        str[i - 1] = argv[i];
    lengthStr(arr, str, size);
    merge_sort(arr, 0, size);
    sorting(str, arr, size);
    return 0;
}
