#include <stdio.h>
#include "./utils/utils.h"
#include "./sorting_algos/bubble_sort.h"

int main()
{
    int array[4] = {2, 3, 1, 4};
    int array_size = ARRAY_SIZE(array);

    // Initialise a stack with content of unsorted array
    Stack stack;
    init_stack(&stack);
    for (int i = array_size - 1; i >= 0; i--)
    {
        push(&stack, array[i]);
    }
    print_stack(&stack);

    stack_bubble_sort(&stack);
    print_stack(&stack);
    
    return 0;
}