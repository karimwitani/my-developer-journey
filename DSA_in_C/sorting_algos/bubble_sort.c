#include <stdio.h>
// #include "bubble_sort.h"
#include "../utils/utils.h"
#include "../data_structures/stack.h"

void array_bubble_sort(int array[], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        for (int j = 0; j < array_size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array, j, j + 1);
            }
        }
    }
}

/**
int main() {
    int array[10] = {34, 7, 23, 32, 5, 62, 78, 45, 12, 89};
    int array_size = ARRAY_SIZE(array);

    printf("Unsorted array:\n");
    printArray(array, array_size);

    array_bubble_sort(array, array_size );

    printf("Sorted array:\n");
    printArray(array, array_size);



    return 0;
}
*/

void swap_stack_heads(Stack *s1, Stack *s2)
{
    int temp = s1->top;
    s1->top = s2->top;
    s2->top = temp;
}

void stack_bubble_sort(Stack *s)
{
    int swapped = 1;
    // PopResult pop_res;
    Stack temp_stack;

    init_stack(&temp_stack);

    while (swapped == 1)
    {
        swapped = 0;

        while (!stack_is_empty(s))
        {
            PopResult current = pop(s);

            if (!stack_is_empty(s))
            {
                PopResult next = pop(s);

                if (current.value > next.value)
                {
                    push(&temp_stack, next.value);
                    push(s, current.value);
                    swapped = 1;
                    printf("Swapping %d into stack and %d into temp_stack\n", current.value, next.value);
                }
                else
                {
                    printf("Pushing %d into stack and %d into temp_stack\n", next.value, current.value);
                    push(s, next.value);
                    push(&temp_stack, current.value);
                }
            }
            else
            {

                push(&temp_stack, current.value);
                printf("Pushing %d into stack\n",current.value);
            }
        }

        while (!stack_is_empty(&temp_stack))
        {
            
            PopResult res = pop(&temp_stack);
            printf("Placing back %d into stack\n", res.value);
            push(s, res.value); 
        }
    }
}