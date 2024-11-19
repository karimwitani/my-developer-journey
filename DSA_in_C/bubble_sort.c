#include <stdio.h>
#include "utils/utils.h"

void bubble_sort(int array[], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        for (int j = 0; j < array_size - i - 1; j++)
        {
            if (array[j]>array[j+1])
            {
                swap(array, j, j + 1);
            }
        }
    }
}


int main() {
    int array[10] = {34, 7, 23, 32, 5, 62, 78, 45, 12, 89};
    int array_size = ARRAY_SIZE(array);
    
    printf("Unsorted array:\n");
    printArray(array, array_size);

    bubble_sort(array, array_size );

    printf("Sorted array:\n");
    printArray(array, array_size);



    return 0;
}
