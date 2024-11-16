#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 5

typedef struct {
    int head;
    int tail;
    int data[MAX_SIZE];
} Queue;

void init_queue(Queue *q)
{
    q->head = 0;
    q->tail = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        q->data[i] = NULL;
    }
}

int queue_is_empty(Queue *q)
{
    if (q->head == q->tail)
    {
        return 1;
    }
    return 0;
}

int queue_is_full(Queue *q)
{
    // The queue is full in two scenarios
    // 1- the head is at the first index and tail at the last index of the data array ie: [H x x x x x x T]
    // 2- the head is sitting where the tail would be if it gets incremented ie: [x x x x x T H x] 
    if (q->tail + 1 == q->head || (q->head == 0 && q->tail == MAX_SIZE -1))
    {
        return 1;
    }
    return 0;

}

void enqueue(Queue *q, int val)
{
    if (queue_is_full(q))
    {
        printf("Queue is full, no space to enqueu value %d. %d\n", val, queue_is_empty(q));
        return;
    }

    q->data[q->tail] = val;
    if (q->tail == MAX_SIZE - 1)
    {
        q->tail = 0;
    }
    else 
    {
        q->tail++;
    }
}

int dequeue(Queue *q)
{
    if (queue_is_empty(q))
    {
        printf("Queue is empty, nothing to dequeue %d\n", queue_is_empty(q));
        return INT_MIN;
    }

    int x = q->data[q->head];
    if (q->head == MAX_SIZE -1)
    {
        q->head = 0;
    }
    else
    {
        q->head++;
    }

    return x;
}

int main()
{
    Queue q;
    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);

    int dequeued_val;

    dequeued_val = dequeue(&q);
    printf("dequeued_val %d\n", dequeued_val);

    dequeued_val = dequeue(&q);
    printf("dequeued_val %d\n", dequeued_val);


    return 0;
}