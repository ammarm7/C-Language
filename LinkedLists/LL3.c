//Tutorial taken from: http://www.learn-c.org/en/Linked_lists

/* [ ] Implement a remove_by_value  */
/* [ ] Put it all together */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	int val;
	struct node* next; 	//You can refrence a structure to itself recursively as long as you use the structs name and NOT the type definintion. 
} node_t;


/* Fn Prototypes */
void print_list(node_t*);
void pushToEnd(node_t*, int);
void pushToFront(node_t**, int);
int remove_last(node_t*);
int remove_by_index(node_t**, int);



int main()
{
	node_t* head = NULL;
	head = malloc(sizeof(node_t));
	if (head == NULL) {
		return 1;
	} 

	head->val = 1;
	head->next = malloc(sizeof(node_t));
	head->next->val = 2;
	head->next->next = NULL;

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

	/* Now that we have traversed to the end of the ll we can add a new var */
	current->next = malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
}

/* This is a fn to push a node to the head of the list.
   Since we will be modifying the head here, we will need to accept it as a double pointer*/

void pushToFront(node_t** head, int val)
{
	node_t* new_node;
	new_node = malloc(sizeof(node_t));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}


/* Removing the first item (popping from the list) */
/* To pop a variable, we will need to reverse this action:  */
/* 1. Take the next item that the head points to and save it */
/* 2. Free the head item  */
/* 3. Set the head to be the next item that we've stored on the side */

int pop(node_t** head) {
	int retval = -1;	//This will store the value of the next node. I am initializing here to -1 first in the case that the fn did not finish.. 
	node_t* next_node = NULL;

	//Checking that the list is not empty
	if (*head == NULL) { 
		return -1;
	}

	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return retval;	//Returning the value of the head node that we jsut popped in the case that the fn was successful. 

}


/* Removing the last item rom a list is very similar to adding it to the end of the list, but with one big exception - since we have to change one item before the last item, we actually have to look two items ahead and see if the next item is the last one in the list:  */

int remove_last(node_t* head){
	int retval = 0;
	/* If there is only one item in the list, remove it */
	if (head->next == NULL) { 
		retval = head->val;
		free(head);
		return retval;	//If this situation was succesful then return the value of the only node in the ll
	}

	/* Traverse the list to find the last node	 */
	node_t* current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	/* Now current points to the last item of the list, so let's remove current->next	 */
	retval = current->next->val;
	free(current->next);
	current->next = NULL;
	return retval;	//Returning the last node 
}

/*Removing a specific item:
 *
 * To remove a specific item from the list, either by its inde from the beginnning of the list or by its value, we will need to go over all the items, continuously looking ahead to find out if we've reached the node before the item we wish to remove. This is because we need to change the location to where the previous node points to as well. 
 *
 * The algorithem is as follows: 
 * 1. Iterate to the node before the node we wish to delete
 * 2. Save the node we wish to delete in a temp pointer 
 * 3. Set the previous node's next pointeer ot the pointer to the node after nth enode we wish to delete
 * 4. Delete the node using the temp pointer. 
 *
 * There are a few edge cases we need to take care of...
 *
 */

int remove_by_index(node_t** head, int n) {
	int i = 0;
	int retval = 1;
	node_t* current = *head;
	node_t* temp_node = NULL;

	/* This is the case where the user wants to remove the first element	 */
	if (n == 0) {
		return pop(head);
	}
	//Remember we want to save the node before the one we wisht to delete. Thus the: n-1
	for (int i = 0; i < n-1; i++) {
		//This is the case where there is only one node in the ll and the user has asked to remove some other node that doesn't even exit. 	
		if (current->next == NULL) {
			return -1;
		}
		current = current->next; 	//This will initialize current to the node the user wants to delete. 
	}
	
	temp_node = current->next;
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

	return retval;
}









