#include <stdio.h>

// #define ARRAY_SIZE 10
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))


void swap(int array_to_sort[] , int pos1, int pos2)
{
    int temp = array_to_sort[pos1];
    array_to_sort[pos1] = array_to_sort[pos2];
    array_to_sort[pos2] = temp;
}

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
    printf("The array to sort is of size %d\n", ARRAY_SIZE(array));
    
    printf("Unsorted array:\n");
    for (int i = 0; i < ARRAY_SIZE(array); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");


    bubble_sort(array, ARRAY_SIZE(array) );

    printf("Sorted array:\n");
    for (int i = 0; i < ARRAY_SIZE(array); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
