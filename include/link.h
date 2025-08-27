#include <stdio.h>
#include <stdlib.h>

#define NODE_INIT_SIZE 5
#define NODE_INIT_VAL 125
#define WELCOME_MSG "Welcome to list\n"
#define BYE_MSG "Please Subscribe\r\n"

struct node {
    struct node* next;
	struct node* prev;
	int data;
};

struct node* init_nodes();
void print_menu();
void print_list(struct node* head);
void add_node(struct node* head);
void remove_node(struct node* head);
struct node* next_node(struct node* head);
struct node* previous_node(struct node* head);
void change_value(struct node* head, int val);
void print_node(struct node* curr);
