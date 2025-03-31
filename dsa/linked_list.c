#include <stdio.h>
#include <stdlib.h>

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
struct Node *linked_list_search(struct LinkedList *l, int x);
void linked_list_free(struct LinkedList *list);

int main(void)
{
    struct LinkedList *my_list = linked_list_init();
    my_list->head = node_init(42);

    for (unsigned i = 0; i < 100; i++)
    {
        linked_list_insert(my_list, rand());
    }

    struct Node *found = linked_list_search(my_list, 42);

    if (found)
    {
        printf("%d found in my_list", found->value);

        return 0;
    }

    printf("value not found in my_list");

    return -1;
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

struct Node *linked_list_search(struct LinkedList *l, int x)
{
    struct Node *current = l->head;

    while (current && current->value != x)
    {
        struct Node *next = current->next;
        current = next;
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