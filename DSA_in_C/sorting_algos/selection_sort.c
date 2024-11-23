#include "../utils/utils.h"


/**
 * @brief Sorts an array of integers in ascending order using the selection sort algorithm.
 *
 * This function iterates through the array, finding the smallest element in the unsorted portion
 * and swapping it with the first unsorted element. This process is repeated until the entire array
 * is sorted.
 *
 * @param arr The array of integers to be sorted.
 * @param arr_size The size of the array.
 */
void selection_sort(int arr[], int arr_size)
{
    for (int i = 1; i < arr_size; i++)
    {
        int min_idx = i - 1;
        int min_value = arr[min_idx];
        for (int j = i; j < arr_size; j++)
        {
            if (arr[j] < min_value)
            {
                min_idx = j;
                min_value = arr[j];
            }
        }
        swap(arr, i - 1, min_idx);
    }
}

/**
#include <stdio.h>
#include "./utils/utils.h"
#include "./sorting_algos/selection_sort.h"

int main() {
    int array[10] = {34, 7, 23, 32, 5, 62, 78, 45, 12, 89};
    int array_size = ARRAY_SIZE(array);

    printf("Unsorted array:\n");
    printArray(array, array_size);

    selection_sort(array, array_size );

    printf("Sorted array:\n");
    printArray(array, array_size);



    return 0;
}*/