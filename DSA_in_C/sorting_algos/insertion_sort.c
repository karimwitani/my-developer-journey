#include <stdio.h>
#include "../utils/utils.h"


void insertion_sort(int array[], int array_size)
{
    for (int i = 1; i < array_size; i++)
    {
        // printf("i: %d\n",i);

        int j = i;
        // printf("j: %d\n",j);
        while (array[j-1] >= array[i] && j - 1 >= 0)
        {
            j--;
            // printf("j: %d\n",j);
        }
        shift(array, i, j );
        // printArray(array, array_size);        
    }
}


// int main() {
//     int array[10] = {34, 7, 23, 32, 5, 62, 78, 45, 12, 89};
//     int array_size = ARRAY_SIZE(array);
    
//     printf("Unsorted array:\n");
//     printArray(array, array_size);

//     insertion_sort(array, array_size );

//     printf("Sorted array:\n");
//     printArray(array, array_size);



//     return 0;
// }
