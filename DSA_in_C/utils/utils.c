#include <stdio.h>



void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");  
}

void swap(int array_to_sort[] , int pos1, int pos2)
{
    int temp = array_to_sort[pos1];
    array_to_sort[pos1] = array_to_sort[pos2];
    array_to_sort[pos2] = temp;
}

// void shift(int arr[], int shift_end_idx, int shift_start_idx)
// {
//     if (shift_start_idx >= shift_end_idx )
//     {
//         return;
//     }

//     int temp = arr[shift_end_idx];
//     for (int k = 0; k <= shift_end_idx - shift_start_idx - 1; k++)
//     {
//         arr[shift_end_idx - k] = arr[shift_end_idx - k - 1];
//     }
//     arr[shift_start_idx] = temp;
// }