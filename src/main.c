#include "main.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct LinkedList *list = create_linked_list();
    // Appending example
    append_node(list, 1234);
    append_node(list, 4321);
    append_node(list, 5678);
    append_node(list, 8765);
    print_list_values(list);
    // Set value example
    set_list_node_data(list, 1, 1111);
    print_list_values(list);
    // Insert example
    insert_node(list, 0, 4444);
    print_list_values(list);
    // Traverse and exec arbitrary code
    traverse_and_execute_list(list, &test_func);
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

void append_node(struct LinkedList *list, int data)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    struct Node *current = list->first;

    if (current == NULL)
    {
        list->first = new;
        return;
    }

    while (current->next != NULL)
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
    if (len == 0)
    {
        printf("NULL\n");
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (get_list_node(list, i) == NULL)
        {
            printf("NULL\n");
        }
        else
        {
            printf("%d ", get_list_node(list, i)->data);
        }
    }
    printf("\n");
}

struct Node *pop_node(struct LinkedList *list)
{
    if (list->first == NULL)
    {
        // No Nodes
        return NULL;
    }
    struct Node *last;
    if (list->first->next == NULL)
    {
        // There's only one Node
        last = list->first;
        list->first = NULL;
        return last;
    }
    struct Node *current = list->first;
    while (current->next != NULL)
    {
        // If Node has Node, but Node 2's next Node is null, we are at second to last
        // We need to remove last and set second to last to link to null
        // Only thing is, it's then up to the user to free the memory.
        if (current->next->next == NULL)
        {
            last = current->next;
            current->next = NULL;
            return last;
        }
        current = current->next;
    }
    // Failsafe
    return NULL;
}

bool insert_node(struct LinkedList *list, int index, int data)
{
    // Get node at index
    //      Could use get_node, but we'd need two loops - for index node and index - 1 node
    //      Instead, we'll write our own loop so we can get node at index and index - 1 simultaneously
    struct Node *index_node = list->first;
    struct Node *prev_node = list->first;
    if (index_node == NULL && index != 0)
    {
        return false;
    }
    for (int i = 0; i < index; i++)
    {
        if (index_node->next == NULL)
        {
            return false;
        }
        // Get node at index - 1
        prev_node = index_node;
        index_node = index_node->next;
    }
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = index_node;
    if (index == 0)
    {
        list->first = new_node;
        return true;
    }
    prev_node->next = new_node;
    return true;
}

struct LinkedList *create_linked_list()
{
    struct LinkedList *new_list = malloc(sizeof(struct LinkedList));
    new_list->first = NULL;
    return new_list;
}

struct Node *remove_node(struct LinkedList *list, int index)
{
    // Traverse list
    struct Node *index_node = list->first;
    struct Node *prev_node = list->first;
    struct Node *next_node = NULL;
    if (index_node == NULL)
    {
        return NULL;
    }
    if (index == 0)
    {
        struct Node *next_node = index_node->next;
        list->first = next_node;
        return index_node;
    }
    for (int i = 0; i < index; i++)
    {
        if (index_node->next == NULL)
        {
            return NULL;
        }
        prev_node = index_node;
        index_node = index_node->next;
    }
    next_node = index_node->next;
    prev_node->next = next_node;
    return index_node;
}

void traverse_and_execute_list(struct LinkedList *list, void (*callback)(struct Node *, int))
{
    struct Node *current = list->first;

    if (current == NULL)
    {
        return;
    }

    int index = 0;
    while (current != NULL)
    {
        (*callback)(current, index);
        current = current->next;
        index++;
    }
}

void test_func(struct Node *node, int index)
{
    node->data = 10;
    printf("INDEX: %d DATA: %d\n", index, node->data);
}