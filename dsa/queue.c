#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct Queue
{
    unsigned *start;
    unsigned *tail;
    unsigned *head;
    size_t length;
};

struct Queue *queue_init(size_t length);
void queue_free(struct Queue *queue);
int queue_enqueue(struct Queue *queue, int x);
int queue_dequeue(struct Queue *queue);

int main(void)
{
    struct Queue *my_queue = queue_init(50);

    for (unsigned i = 0; i < my_queue->length; i++)
    {
        int r = rand();
        printf("enqueueing %d...\n", r);
        queue_enqueue(my_queue, r);
    }

    printf("tail: %d\nhead: %d\n\n", *(my_queue->tail - 1), *(my_queue->head));

    queue_dequeue(my_queue);

    printf("tail: %d\nhead: %d\n\n", *(my_queue->tail), *(my_queue->head));

    queue_free(my_queue);
}

struct Queue *queue_init(size_t length)
{
    struct Queue *new_queue = (struct Queue *)calloc(1, sizeof(struct Queue));

    if (length < 2)
        return NULL;

    new_queue->length = length;
    new_queue->start = (unsigned *)calloc(length, sizeof(unsigned));

    if (!new_queue->start)
        return NULL;

    new_queue->head = new_queue->start;
    new_queue->tail = new_queue->start;

    return new_queue;
}

void queue_free(struct Queue *queue)
{
    free(queue->start);
    free(queue);
}

int queue_enqueue(struct Queue *queue, int x)
{
    *(queue->tail) = x;

    if ((queue->tail - queue->start) == (queue->length - 1))
    {
        queue->tail = queue->start;
    }
    else
    {
        queue->tail++;
    }

    return *(queue->tail);
}

int queue_dequeue(struct Queue *queue)
{
    unsigned curr_tail = *(queue->head);

    if ((queue->head - queue->start) == (queue->length - 1))
    {
        queue->head = queue->start;
    }
    else
    {
        queue->head++;
    }

    return curr_tail;
}