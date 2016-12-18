#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int val;
	struct node* next;	//You can refrence a structure to itself recursively as long as you use the structures name and NOT th etype def. 
} ndoe_t;


/*Fn prototypes*/

void pushToFront(node_t**, int);
void print_list(node_t*);
void pushToEnd(node_t*, int);



int main()
{
	node_t* head = NULL;
	head = malloc(sizeof(node_t));
	if (head == NULL) {	//Simple error handling
		return 1;
	} 

	head->val = 1;
	head->next = malloc(sizeof(node_t));
	head->next->val = 2;
	head->next->next = NULL;
	
	//Obviously it does not make sense to keep going like this, so we will begin to creat LL fns	

	return 0;
}



void print_list(node_t* head) {
	node_t* current = head;

	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

void pushToEnd(node_t* head, int val) {
	node_t* current = head;
	while (current->next != NULL) {
		current = current->next; 
	}
	
	/*Now that we have traversed to the end of the ll we can add a new var*/
	current->next = malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
}


void pushToFront(node_t** head, int val)	//We use a dp in this case because we are manipulateing rahter than simply setting. 
{
	node_t* new_node;
	new_node = malloc(sizeof(node_t));

	new_node->val = val;	//ATM we have created an arbitrary "new_node" nodetype and we are setting its val to the param entry. 

	new_node->next = *head;
	*head = new_node;
}	

/*














