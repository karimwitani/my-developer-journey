#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "stack.h"

#define MAX_SIZE 20

void init_stack(Stack *s)
{
    s->top = -1;
}

int stack_is_empty(Stack *s)
{
    return s->top == -1;
}

int stack_is_full(Stack *s)
{
    return s->top == MAX_SIZE;
}

void push(Stack *s, int val)
{
    if (stack_is_full(s))
    {
        printf("Stack is full!!\n");
        return;
    }
    s->top++;
    s->data[s->top] = val;
    // printf("Pushed value %d onto stack\n", val);
}

PopResult pop(Stack *s)
{
    PopResult pop_result = { .success = false, .value = 0 };
    if (stack_is_empty(s))
    {
        printf("Stack is empty!!\n");
        pop_result.success = false;
    }
    else
    {
        pop_result.value = s->data[s->top];  // Retrieve the value at the top
        s->data[s->top] = UINT_MAX;         // Clear the value by setting it to a sentinel
        s->top--;                           // Decrement the top
        pop_result.success = true;
    }
    return pop_result;
}

int peek(Stack *s)
{
    if (stack_is_empty(s))
    {
        printf("Stack is empty!!\n");
        return INT_MIN;
    }
    return s->data[s->top];
}

void print_stack(Stack *s)
{
    // pop and store elements in a temporary stack while printing them
    Stack temp_stack;
    init_stack(&temp_stack);
    PopResult res;
    while (!stack_is_empty(s))
    {
        res = pop(s);
        push(&temp_stack, res.value);
        printf("%d, ", res.value);
    }
    printf("\n");

    // place back items in original stack
    while (!stack_is_empty(&temp_stack))
    {
        res = pop(&temp_stack);
        push(s, res.value);
    }
}

/** 
int main()
{
    Stack s;
    init_stack(&s);
    printf("Stack is empty %d\n", stack_is_empty(&s));

    push(&s, 2);
    push(&s, 1);
    push(&s, 3);
    push(&s, 4);

    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);

    push(&s, 4);
    int peeked_value = peek(&s);
    printf("peeked_value %d\n", peeked_value);


    return 0;
}
*/