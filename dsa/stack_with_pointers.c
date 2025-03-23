#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct StackP
{
    unsigned *top;
    size_t length;
};

unsigned stackp_push(struct StackP *stackp, int x);
unsigned stackp_pop(struct StackP *stackp);
struct StackP *stackp_init(size_t length);

int main(void)
{
    struct StackP *my_stack = stackp_init(50);

    for (unsigned i = 0; i < my_stack->length; i++)
    {
        int r = rand();

        printf("push %d to stack...\n", r);

        stackp_push(my_stack, r);
    }

    printf("stack->top: %d\n", *(my_stack->top - 1));

    int popped = stackp_pop(my_stack);

    printf("popped %d from stack.\n", popped);
    printf("stack->top: %d\n", *(my_stack->top - 1));
}

struct StackP *stackp_init(size_t length)
{
    struct StackP *new_stack = (struct StackP *)calloc(1, sizeof(struct StackP));

    if (!new_stack)
        return NULL;

    new_stack->top = (unsigned *)calloc(1, length * sizeof(unsigned));
    new_stack->length = length;

    return new_stack;
}

unsigned stackp_push(struct StackP *stackp, int x)
{
    *(stackp->top) = x;
    stackp->top++;

    return x;
}

unsigned stackp_pop(struct StackP *stackp)
{
    int popped = *(stackp->top - 1);

    *(stackp->top) = 0;
    stackp->top--;

    return popped;
}