#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct StackP
{
    unsigned *base;
    unsigned *top;
    unsigned *end;
    size_t length;
};

int stackp_push(struct StackP *stackp, int x);
int stackp_pop(struct StackP *stackp);
struct StackP *stackp_init(size_t length);
void stackp_free(struct StackP *stackp);

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

    stackp_free(my_stack);
}

struct StackP *stackp_init(size_t length)
{
    struct StackP *new_stack = (struct StackP *)calloc(1, sizeof(struct StackP));

    if (!new_stack)
        return NULL;

    new_stack->base = (unsigned *)calloc(1, length * sizeof(unsigned));
    new_stack->top = new_stack->base;
    new_stack->end = new_stack->base + length;
    new_stack->length = length;

    return new_stack;
}

int stackp_push(struct StackP *stackp, int x)
{
    if (stackp->top >= stackp->end)
        return -1;

    *(stackp->top) = x;
    stackp->top++;

    return x;
}

int stackp_pop(struct StackP *stackp)
{
    if (stackp->top <= stackp->base)
        return -1;

    int popped = *(stackp->top - 1);

    stackp->top--;
    *(stackp->top) = 0;

    return popped;
}

void stackp_free(struct StackP *stackp)
{
    free(stackp->base);
    free(stackp);
}