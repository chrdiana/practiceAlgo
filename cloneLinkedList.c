/* clone a linked list with random pointer */

/*
 * there are three methods to do this:
 * 1. iterative 
 * 2. iterative with unweaving
 * 3. recursive
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *ptr;
    struct node *next;
} Node;

typedef struct hashelem {
    struct node *oldNode;
    struct node *newNode;
} hashelem;

typedef struct hashmap {
    int len;
    int curr;
    struct hashelem *table;
} hashmap;


Node *findInHashmap(hashmap *map, Node *oldNode) {
    int i = 0;
    for (i = 0; i<map->len; i++) {
        if (map->table[i].oldNode == oldNode) {
            //found
            return map->table[i].newNode;
        }
    }
    return NULL;
}

void insertInHashmap(hashmap *map, Node *oldNode, Node *newNode) {
    map->table[map->curr].oldNode = oldNode;
    map->table[map->curr].newNode = newNode;
    map->curr++;
}

Node *getClonedNode(hashmap *map, Node *oldNode) {

    if (oldNode == NULL) {
        return NULL;
    }

    Node *newNode = findInHashmap(map, oldNode);
    if (newNode == NULL) {
        //not visited create new
        newNode = malloc(sizeof(Node));
        newNode->data = oldNode->data;

        insertInHashmap(map, oldNode, newNode);
    }
    return newNode;
}

Node *copyListIterative1(Node *head) {

    if (head == NULL) {
        return NULL;
    }

    Node *tmp = head;
    int len = 0, i = 0;
    while (tmp) {
        len++;
        tmp = tmp->next;
    }
    hashmap *map = malloc (sizeof(hashmap));
    if (map == NULL) {
        return NULL;
    }
    map->len = len;
    map->curr = 0;
    map->table = calloc (len, sizeof(hashelem));
    if (map->table == NULL) {
        return NULL;
    }

    Node *clonedHead = malloc (sizeof(Node));
    clonedHead->data = head->data;

    insertInHashmap(map, head, clonedHead);

    tmp = head;
    Node *newNode = clonedHead;
    while (tmp != NULL) {
        newNode->next = getClonedNode(map, tmp->next);
        newNode->ptr = getClonedNode(map, tmp->ptr);

        tmp = tmp->next;
        newNode = newNode->next;
    }

    return clonedHead;
}

Node *copyListIterative2(Node *head) {
    
    return head;
}

Node *recursivecopy(Node *node, hashmap *map) {

    if (node == NULL) {
        return NULL;
    }
    Node *visitedNode = findInHashmap(map, node);
    if (visitedNode != NULL) {
        return visitedNode;
    }
    visitedNode = malloc (sizeof(Node));
    if (!visitedNode) {
        return NULL;
    }
    visitedNode->data = node->data;
    insertInHashmap(map, node, visitedNode);

    visitedNode->next = recursivecopy(node->next, map);
    visitedNode->ptr = recursivecopy(node->ptr, map);

    return visitedNode;
}

// easy, like a graph, depth first search, with a hashmap storing visited nodes
Node *copyListRecursive(Node *head) {

    Node *tmp = head;
    int len = 0, i = 0;
    while (tmp) {
        len++;
        tmp = tmp->next;
    }
    hashmap *map = malloc (sizeof(hashmap));
    if (map == NULL) {
        return NULL;
    }
    map->len = len;
    map->curr = 0;
    map->table = calloc (len, sizeof(hashelem));
    if (map->table == NULL) {
        return NULL;
    }
    
    head = recursivecopy(head, map);

    return head;
}

void printList (Node *node) {
	if (!node) {
		printf("Wow, such empty\n");
		return;
	}
	while(node){
		printf("%d (R:%d) -> ", node->data, node->ptr?node->ptr->data:INT_MAX);
		node = node->next;
	}
	printf("\n");
}

int main () {

    Node *head = malloc (sizeof(Node));
    head->data = 4;
    head->next = malloc (sizeof(Node));
    head->next->data = 7;
    head->next->next = malloc (sizeof(Node));
    head->next->next->data = 2;
    head->next->next->next = NULL;
    head->next->next->ptr = NULL;

    head->ptr = head->next->next;

    head->next->ptr = head;

    printList(head);

    //Node *clonedHead = copyListRecursive(head);
    Node *clonedHead = copyListIterative1(head);
    printList(clonedHead);

    return 0;
}