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
