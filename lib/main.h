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

struct Node *get_list_node(struct LinkedList *, int);
void set_list_node_data(struct LinkedList *, int, int);
void append_node(struct LinkedList *, int);
struct Node *pop_node(struct LinkedList *);
int get_list_length(struct LinkedList *);
void print_list_values(struct LinkedList *);
bool insert_node(struct LinkedList *, int, int);