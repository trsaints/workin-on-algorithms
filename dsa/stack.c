#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_SIZE 100

struct stack
{
    unsigned top;
    int items[STACK_SIZE];
};
unsigned stack_empty(struct stack *stack);
unsigned stack_push(struct stack *stack, int x);
unsigned stack_pop(struct stack *stack);
void stack_print(struct stack *stack);

int main(int argc, int **argv)
{
    struct stack my_stack = {
        .top = 0,
    };

    for (int i = 0; i < 100; i++)
    {
        stack_push(&my_stack, rand());
    }

    stack_print(&my_stack);
    stack_pop(&my_stack);
    stack_print(&my_stack);
}

unsigned stack_empty(struct stack *stack)
{
    return stack->top == 0;
}

unsigned stack_push(struct stack *stack, int x)
{
    if (stack->top >= STACK_SIZE)
        return 0;

    stack->top++;
    stack->items[stack->top - 1] = x;

    return stack->top;
}

unsigned stack_pop(struct stack *stack)
{
    if (stack_empty(stack))
        return 0;

    int popped = stack->items[stack->top - 1];

    stack->items[stack->top - 1] = 0;
    stack->top--;

    return popped;
}

void stack_print(struct stack *stack)
{
    printf("stack:\ntop: %d\n", stack->top);
    printf("[");

    for (int i = 0; i < stack->top; i++)
    {
        printf("%d ", stack->items[i]);
    }

    printf("]\n\n");
}
