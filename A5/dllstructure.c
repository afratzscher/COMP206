#include<stdio.h>
#include<stdlib.h>

/* create node of doubly linked list */
typedef struct Node { 
	int data; // to hold data in each element
	struct Node* next; // pointer to next node in DLL
	struct Node* previous; // pointer to previous node in DLL
} Node;

int added = 0; // counts number of nodes added
struct Node* create_dll_from_array(int arr[], int x);
void print_dll(Node* head);
void insert_after(Node* head, int valueToInsertAfter, int valueToBeInserted);
void delete_element(Node* head, int valueToBeDeleted);
void sort_dll(Node* head);
void clean(Node* head);

int main()
{
	int array[5] = {11, 2, 7, 22, 4};
	Node* head;

	/* Question 1 */
	head = create_dll_from_array(array, 5); // size of array is 5

	/* Question 2 */
	print_dll(head);

	/* Question 3 */
	// to insert 13 after first occurence of 7
	insert_after(head, 7, 13);
	// to insert 29 after first occurence of 21
	insert_after(head, 21, 29);
	print_dll(head);

	/* Question 4 */
	delete_element(head, 22);
	print_dll(head);
	delete_element(head, 11);
	print_dll(head);

	/* Question 5 */
	sort_dll(head);
	print_dll(head);

	/* Question 6 */
	//use to prevent memory leaks
	clean(head);

	return 0;
}

struct Node* create_dll_from_array(int arr[], int x){
	Node* head = (Node*) malloc(sizeof(Node));
	head->data = arr[0];
	added++; // increase added

	Node* temp = head;
	for (int i = 1; i < x; i++){
		Node* newNode = (Node*) malloc(sizeof(Node));
		temp->next = newNode;
		newNode->data = arr[i];
		newNode->previous = temp;
		temp=newNode;
		added++; // increase added
	}
	return head;
}

void print_dll(Node* head){
	Node* temp = head;
	if (head == NULL){
		printf("The list is empty.");
		return;
	}
	while (temp != NULL){
		printf("%d	", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void insert_after(Node* head, int valueToInsertAfter, int valueToBeInserted){
	Node* temp = head;
	Node* newNode = (Node*) malloc(sizeof(Node));
	int check = 0;
	newNode->data = valueToBeInserted;
 
	while(temp->next != NULL){
		if (temp->data == valueToInsertAfter){ // if valueToInsertAfter is data value for node
			newNode->next = temp->next; // next of newNode is next of temp
			temp->next = newNode; // next of temp is newNode
			newNode->previous = temp; // previous of newNode is temp
			newNode->next->previous = newNode; // previous of the next of newNode is newNode
			check = 1;
		}
		temp = temp->next;
	}

	if (check == 0){ // if not inserted
		temp->next = newNode;
		newNode->previous = temp;
		newNode->next = NULL;
	}
	added++; // increase number of nodes added
}

void delete_element(Node* head, int valueToBeDeleted){
	Node* temp = head;
	// if delete head
	if (temp->data == valueToBeDeleted && temp->previous == NULL){
		Node* toDelete = temp->next; // store head in toDelete
		temp->data = toDelete->data; // data of temp is data of toDelete
	       	temp->next = toDelete->next; // next of temp is next of toDelete
		free(toDelete); // free head
		added--; // decrease number of nodes
		return; 
	}
	
	// check all internal nodes that arent head or tail 
	while (temp->next != NULL){ // while NOT last node
		if (temp->data == valueToBeDeleted){
			temp->previous->next = temp->next; // next of previous node is next of temp
			temp->next->previous = temp->previous; // previous of next node is previous of temp
			free(temp); // free temp
			added--; // decrease number of nodes
			return;
		}
		temp = temp->next; // go to next node
	}
	
	// if want to delete last node	
	if (temp->next == NULL && temp->data == valueToBeDeleted){
		temp->previous->next = NULL; // next of previous node is NULL
		free(temp); // free temp
		added--; // decrease number of nodes
		return; 
	}
}

void sort_dll(Node* head){
	Node* currentNode = head;
	Node* nextNode = head->next;
	int counter = 0; // use to count number of swaps
	if (currentNode == NULL){ // if empty list
		return;
	}

	while (currentNode->next != NULL){ // while next of current node NOT null
		if (currentNode->data > nextNode->data){ // if nextNode smaller
			int currentVal = currentNode->data; // store data value of currentNode in currentVal int
			currentNode->data = nextNode->data; // replace currentNode data with value of nextNode data
			nextNode->data = currentVal; // replace nextNode data with currentVal (stored)
			counter++; // increase number of swaps
		}
			currentNode = nextNode; // go to next nodes
			nextNode = currentNode->next;
	}

	if (counter == 0){ // if no swaps, end
		return;
	}
	else{ // if had swaps, repeat again
		sort_dll(head);
	}
}

// frees each node to prevent memory leaks
void clean(Node* head){
	Node* current = head;
	int freeded = 0; //number of nodes freed initially 0
	while (current != NULL){ // while current NOT null
		Node* next = current->next;
		free(current);
		current = next;
		freeded++; // increment number of freed
	}
	if (freeded != added){
		printf("Memory leak.");
		printf("\n");
	}
	else{
		printf("Nodes successfully freed.");
		printf("\n");
	}
}

