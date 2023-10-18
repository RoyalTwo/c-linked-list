#include "main.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct LinkedList list = {NULL};
    // Appending example
    append_node(&list, 1234);
    append_node(&list, 4321);
    append_node(&list, 5678);
    append_node(&list, 8765);
    print_list_values(&list);
    // Change a value example
    set_list_node_data(&list, 1, 1111);
    print_list_values(&list);
}

struct Node *get_list_node(struct LinkedList *list, int index)
{
    if (list->first == NULL)
    {
        return NULL;
    }
    struct Node *current = list->first;
    for (int i = 0; i < index; i++)
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        current = current->next;
    }
    return current;
}

// Args: (LinkedList*) list to append to, (int) data to append.
void append_node(struct LinkedList *list, int data)
{
    int len = get_list_length(list);
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    if (len == 0)
    {
        list->first = new;
        return;
    }

    struct Node *current = list->first;
    for (int i = 1; i < len; i++)
    {
        current = current->next;
    }
    current->next = new;
}

int get_list_length(struct LinkedList *list)
{
    if (list->first == NULL)
    {
        return 0;
    }
    struct Node *current = list->first;
    int i = 1;
    while (current->next != NULL)
    {
        current = current->next;
        i++;
    }
    return i;
}

void set_list_node_data(struct LinkedList *list, int index, int new_data)
{
    struct Node *node = get_list_node(list, index);
    if (node == NULL)
    {
        printf("ERROR: NULL value at %d\n", index);
        return;
    }
    node->data = new_data;
}

void print_list_values(struct LinkedList *list)
{
    int len = get_list_length(list);
    for (int i = 0; i < len; i++)
    {
        if (get_list_node(list, i) == NULL)
        {
            printf("NULL \n");
        }
        else
        {
            printf("%d ", get_list_node(list, i)->data);
        }
    }
    printf("\n");
}