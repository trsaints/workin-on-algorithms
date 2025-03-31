#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct LinkedList
{
    struct Node *head;
};

struct Node
{
    int value;
    struct Node *next;
};

struct LinkedList *linked_list_init();
struct Node *node_init(int x);
void linked_list_insert(struct LinkedList *l, int x);
struct Node *linked_list_at(struct LinkedList *l, unsigned i);
struct Node *linked_list_search(struct LinkedList *l, int x);
void linked_list_free(struct LinkedList *list);

int main(void)
{
    srand(time(NULL));

    struct LinkedList *my_list = linked_list_init();
    my_list->head = node_init(rand());

    for (unsigned i = 0; i < 100; i++)
    {
        int r = rand();
        int x = r % 42 == 0 ? 42 : r;
        linked_list_insert(my_list, x);
    }

    struct Node *fourthy_second = linked_list_at(my_list, 42);

    printf("42th element in my_list is %d\n", fourthy_second->value);

    struct Node *found = linked_list_search(my_list, 42);

    int status = found ? 0 : -1;

    linked_list_free(my_list);

    return status;
}

struct LinkedList *linked_list_init()
{
    struct LinkedList *new = calloc(1, sizeof(struct LinkedList));
    new->head = NULL;

    return new;
}

struct Node *node_init(int x)
{
    struct Node *new = calloc(1, sizeof(struct Node));
    new->value = x;
    new->next = NULL;

    return new;
}

void linked_list_insert(struct LinkedList *l, int x)
{
    struct Node *new = node_init(x);
    new->next = l->head;
    l->head = new;
}

struct Node *linked_list_at(struct LinkedList *l, unsigned i)
{
    struct Node *current = l->head;
    unsigned c = 0;

    while (c < i)
    {
        current = current->next;
        c++;
    }

    return current;
}

struct Node *linked_list_search(struct LinkedList *l, int x)
{
    struct Node *current = l->head;
    unsigned c = 0;

    while (current && current->value != x)
    {
        struct Node *next = current->next;
        current = next;
        c++;
    }

    if (current)
    {
        printf("found %d after %d iterations\n", x, c);
    }

    return current;
}

void linked_list_free(struct LinkedList *list)
{
    struct Node *current = list->head;

    while (current)
    {
        struct Node *next = current->next;
        free(current);
        current = next;
    }

    free(list);
}