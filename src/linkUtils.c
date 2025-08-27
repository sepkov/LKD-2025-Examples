#include "include/link.h"

// Bunu birisi yazdı ama segfault veriyor.
// Bakacak zamanım olmadı...
void print_list(struct node* head) {
    struct node* curr;
    while(NULL != curr->next) {
  		printf("Curr node: %p, next: %p, data: %d\n", curr, curr->next, curr->data);
        curr = curr->next;
    }
    return;
}

// Belli değil mi?
void print_menu() {
    printf("What do you want to do?\n");
	printf("1 -> Print Nodes\n");
	printf("2 -> Add Node\n");
	printf("3 -> Remove Node\n");
	printf("4 -> Next Node\n");
	printf("5 -> Previous Node\n");
	printf("6 -> Change Value\n");
}

// Program başında listeyi oluşturur
struct node* init_nodes() {
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    struct node *curr;
	head->data = NODE_INIT_VAL;
	curr = head;

	for(int i = 0;i < NODE_INIT_SIZE; i++) {
		curr->next = (struct node*)malloc(sizeof(struct node));
		if(0 == i) {
		    curr->prev = NULL;
		} else {
		    curr->next->prev = curr;
		}
		curr->data = i;
		curr = curr->next;
	}
	return head;
}

// Yeni düğüm ekler
void add_node(struct node* head) {
    // Get last item
    while(NULL != head->next) {
        head = head->next;
    }
    head->next = malloc(sizeof(struct node));
    head->next->prev = head;
    head->next->data = 0;
}

// Mevcut düğümü çıkartır
void remove_node(struct node* curr) {
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
}

// Bir sonraki düğümü döndürür
struct node* next_node(struct node* curr){
    return curr->next;
}

// Bir önceki düğümü döndürür
struct node* previous_node(struct node* curr){
    return curr->prev;
}

// Verilen düğümün verisini değiştirir
void change_value(struct node* curr, int val){
    curr->data = val;
}

// Belli değil mi...
void print_node(struct node* curr) {
  		printf("Curr Node: %p, next: %p, prev: %p, data: %d\n", curr, curr->next, curr->prev, curr->data);
}
