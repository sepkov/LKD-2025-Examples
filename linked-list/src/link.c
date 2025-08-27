#include "include/link.h"
#include <stdio.h>

int main() {
	struct node *curr = NULL;
	int val = 0;
	char buff = 0;

	curr = init_nodes();

	printf(WELCOME_MSG);
	while('q' != buff) {
    	print_menu();
        print_node(curr);
    	scanf(" %c", &buff);
        switch (buff) {
            case '1':
       	        print_list(curr);
                break;
            case '2':
            add_node(curr);
                break;
            case '3':
            remove_node(curr);
                break;
            case '4':
            next_node(curr);
                break;
            case '5':
            previous_node(curr);
                break;
            case '6':
            scanf("%d", &val);
            change_value(curr, val);
                break;
            default:
                printf("Unrecognized key, please try again...");
        }
	}

	printf(BYE_MSG);
}
