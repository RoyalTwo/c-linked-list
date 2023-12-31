#include <stdio.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *next;
};

struct LinkedList
{
    struct Node *first;
};

struct LinkedList *create_linked_list();
struct Node *get_list_node(struct LinkedList *, int);
void set_list_node_data(struct LinkedList *, int, int);
void append_node(struct LinkedList *, int);
struct Node *pop_node(struct LinkedList *);
int get_list_length(struct LinkedList *);
void print_list_values(struct LinkedList *);
bool insert_node(struct LinkedList *, int, int);
struct Node *remove_node(struct LinkedList *, int);
void traverse_and_execute_list(struct LinkedList *, void (*)(struct Node *, int));
void test_func(struct Node *, int);