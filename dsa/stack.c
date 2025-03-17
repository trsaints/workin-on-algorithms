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
void stack_print(struct stack *stack);

int main(int argc, int **argv)
{
 1   struct stack my_stack = {
        .top = 0,
    };

    for (int i = 0; i < 100; i++)
    {
        stack_push(&my_stack, i);
    }

    stack_print(&my_stack);
}

unsigned stack_empty(struct stack *stack)
{
    return stack->top == 0;
}

unsigned stack_push(struct stack *stack, int x)
{
    if ((stack->top + 1) > STACK_SIZE)
        return 0;

    stack->top++;
    stack->items[stack->top - 1] = x;

    return stack->top;
}

void stack_print(struct stack *stack)
{
    char out_buffer[sizeof(int) * STACK_SIZE];
    char *out_position = out_buffer,
         *out_end = out_buffer + sizeof(out_buffer);

    for (int i = 0; i < 100; i++)
    {
        out_position += snprintf(out_position, out_end - out_position, "%d ", stack->items[stack->top - 1]);
    }

    printf("[%s]\n", out_buffer);
}
