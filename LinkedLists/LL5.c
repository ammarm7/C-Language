/* [ ] Make this a doubly ll */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int val;
	struct node* next;	//You can refrence a structure to itself recursively as long as you use the structures name and NOT th etype def. 
} node_t;


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

	new_node->val = val;	//ATM we have created an arbitrary "new_node" nodetype and we are setting its val to the param entr

	new_node->next = *head;
	*head = new_node;
}	

/* Removing the first item (popping from the list)
 * To pop a var, we will need to reverse this action:
 * 1. Take the next item that the head points to and save it. 
 * 2. Free the head item
 * 3. Set the head to be the next item that we've stored on the side.*/

int pop(node_t** head) {	//Note this is a dp because we will again be manipulating it.
	int retval = -1;

	node_t* next_node = NULL;	

	//Error handling in the case that we have an empty list. 
	if (*head == NULL) { 
		return -1;
	}

	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return retval;	//Success! 

}

int remove_last(node_t* head){
	int retval = 0;
	//We must consider that this may be the only item in the list!! 
	if (head->next == NULL) {
		retval = head->val;
		free(head);
		return retval; //In this case we have escentially deleted the list. 
	}

	//If the list contains >1 node than we must traverse to find the last node. 
	node_t* current = head;
	while (current->next->next != NULL) {	//This puts us in the second last pos from the end. 
		current = current->next;
	}

	retval = current->next->val;
	free(current->next);
	current->next = NULL;
	return retval; 	//Returning the last node. 
}

/*Removing a specific item: 
 *
 * 	To remove a specific item from the list, either from the beginning of the list or by its value, we will need to go over all the items, continously looking ahead to find out if we've reached the node before the item we wish to remove. This is becuase we need ot change the location to where the prev node points to as well. 
 *
 * 	The algoritem is as follows:
 * 	1. Iterate to the node before the node we wish to delete 
 * 	2. Save the node we wish to delete in a temp pointer 
 * 	3. Set the previous nodes next pointer to the pointer to the node after n'th node we wish to delete
 * 	4. Delete the node usign the temp pointer
 *
 * 	(Also there are edge case which will need to be taken care of)
 */


int remove_by_index(node_t** head, int n)
{ 
	int i = 0;
	int retval = 1;
	node_t* current = *head;
	node_t* temp_node = NULL;	//Arbitrary temp node for which we will make the n'th node which needs to be deleted. 

	/*This is the case where the user wants to remove the fist element */
	if (n == 0) {
		return pop(head);
	}

	//This is how we will save the n'th node	
	for (int i = 0; i<n-1; i++) {
		//covers the case that the user asked to del some node that doesn't exist
		if (current->next == NULL) {
			return -1;
		}		
		current = current->next;	//Initializing current to the node before the one the user asked to del
	}

	temp_node = current->next;	//This is the one the user want sto del
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

	return retval;

}
















