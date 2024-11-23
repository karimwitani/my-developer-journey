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
}