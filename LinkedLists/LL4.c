#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int val;
	struct node* next;	//You can can recursively use the same struct as long as you ref the struct name NOT the typedef as it has not yet been read by the compiler
} node_t;

void printList(node_t*);
void pushToEnd(node_t*, int);
void pushToFront(node_t**, int);

int main()
{ 
	node_t* head = NULL;
	head = malloc(sizeof(node_t));

	/* [ ] When the rest of the fns have been completed return here  */


	/*Testing.......*/
	printf("Testing....\n");
	head->val = 100;
	head->next = NULL;
	printList(head);
	pushToFront(&head, 5);
	printList(head);


	return 0;
}


void printList(node_t* head)
{
	node_t* current = head;

	while (current != NULL){
		printf("%d\n", current->val);
		current = current->next;
	}
}

void pushToEnd(node_t* head, int val)
{
	node_t* current = head;
	while(current->next != NULL){
		current = current->next;
	}

	/* Now that we have traversed to the end of the list we can create a new var */
	current->next = malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
}

/* This is a fn which pushes a node to the front of a ll, since we are modifying the head it needs to be passed using a double p  */

void pushToFront(node_t** head, int val)
{
	node_t* newNode;
	newNode = malloc(sizeof(node_t));

	newNode->val = val;
	newNode->next = *head;
	*head = newNode;
}





	
	


















