#pragma once

// #include <stdio.h>
#include <stdbool.h>
// #include <limits.h>

#define STACK_MAX_SIZE 20

typedef struct Stack {
    int top;
    int data[STACK_MAX_SIZE];
} Stack;

typedef struct PopResult {
    bool success;
    int value;
} PopResult;

void init_stack(Stack *s);

int stack_is_empty(Stack *s);

int stack_is_full(Stack *s);

void push(Stack *s, int val);

PopResult pop(Stack *s);

int peek(Stack *s);

void print_stack(Stack *s);