#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 2

typedef struct {
    int top;
    int data[MAX_SIZE];
} Stack;

typedef struct {
    bool success;
    int value;
} PopResult;

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
    printf("Pushed value %d onto stack\n", val);
}

PopResult pop(Stack *s)
{
    PopResult pop_result = { .success = false, .value = 0 };
    if (stack_is_empty(s))
    {
        printf("Stack is empty!!\n");
        pop_result.success = false;
    }
    else {
        pop_result.value = s->data[s->top];
        s->data[s->top] = NULL;
        s->top-- ;
        // printf("Popped value %d from stack\n", pop_result.value);
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