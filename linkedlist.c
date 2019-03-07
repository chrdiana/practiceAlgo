#include "app.h"

/* sorted list
 *
 */

struct node {
	int data;
	struct node *next;
};

typedef struct node Node;

Node * insertNode (Node *head, int data) {

	Node *newNode = malloc(sizeof(Node));
	if (!newNode) {
		printf("Error: malloc failed\n");
		return NULL;
	}
	newNode->data = data;

	//insert at head
	if (!head || head->data >= data) {
		printf("Inserting %d at head\n", data);
	    newNode->next = head;
	    head = newNode;
	    return head;
	}
	//insert in between
	Node *tmp = head->next;
	Node *prev = head;
	while(tmp) {
		if (tmp->data >= data) {
			printf("Inserting %d in between\n", data);
			prev->next = newNode;
			newNode->next = tmp;
			return head;
		} else {
			prev = tmp;
			tmp = tmp->next;
		}
	}
	//insert at end
	printf("Inserting %d at tail\n", data);
	newNode->next = NULL;
	prev->next= newNode;

	return head;
}

Node * insertNode2(Node *head, int data) {
	Node *newNode = malloc(sizeof(Node));
	if (!newNode) {
		return NULL;
	}
	newNode->data = data;

	if (head == NULL || head->data >= data) {
		newNode->next = head;
		head = newNode;
	} else {
		Node *tmp = head;
		while (tmp->next != NULL && tmp->next->data < data) {
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	return head;
}

Node * deleteNode (Node *head, int data) {

	Node *tmp = head;
	Node *prev = NULL;

	if (!head) {
		printf("Error: empty list, can't delete %d\n", data);
		return NULL;
	}

	if (head->data == data) {
		printf("deleting %d at head\n", data);
		head = head->next;
		free(tmp);
	} else {
		tmp = head->next;
		prev = head;
		while (tmp != NULL && tmp->data != data) {
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp) {
			printf("Deleting %d\n", tmp->data);
			prev->next = tmp->next;
			free(tmp);
		} else {
			printf("%d is not present in list\n", data);
		}
	}
	/*tmp = head->next;
	prev = head;
	while (tmp) {
		if (tmp->data == data) {
			printf("deleting %d otherwise\n", data);
			prev->next = tmp->next;
			free(tmp);
			return head;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	printf("%d is not present in list\n", data);*/


	return head;
}

void printList (Node *node) {
	if (!node) {
		printf("Wow, such empty\n");
		return;
	}
	while(node){
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("\n");
}

int findNode (Node *head, int data) {

	Node *tmp = head;
	int idx = 0;
	if (!head) {
		printf("Error: such emptiness\n");
		return -1;
	}
	while( tmp && tmp->data != data) {
		tmp = tmp->next;
		idx++;
	}
	if (!tmp)
		return -1;
	return idx;
}


int testLinkedList () {
	Node *list = NULL;
	list = insertNode2(list, 10);
	printList(list);
	list = insertNode2(list, 100);
	printList(list);
	list = insertNode2(list, 20);
	printList(list);
	list = insertNode2(list, 5);
	printList(list);
	list = insertNode2(list, 30);
	printList(list);
	list = insertNode2(list, 110);

	printList(list);
	printf("30: idx=%d\n", findNode(list, 30));
	printf("110: idx=%d\n", findNode(list, 110));
	printf("1100: idx=%d\n", findNode(list, 1100));
	printf("5: idx=%d\n", findNode(list, 5));
	printf("20: idx=%d\n", findNode(list, 20));

	list = deleteNode(list, 110);
	printList(list);
	list = deleteNode(list, 10);
	printList(list);
	list = deleteNode(list, 5);
	printList(list);
	list = deleteNode(list, 50);
	printList(list);
	list = deleteNode(list, 100);
	printList(list);
	list = deleteNode(list, 30);
	printList(list);
	list = deleteNode(list, 20);
	printList(list);
	list = deleteNode(list, 20);

	printList(list);
	return 0;
}

