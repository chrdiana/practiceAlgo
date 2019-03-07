/*
 * Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 * Output: Reference of the node with value = 8
 * Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). 
 * From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. 
 * There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int getListLength(struct ListNode *node) {
    if (node == NULL) {
        return 0;
    }
    int len = 0;
    while (node != NULL) {
        len++;
        node = node->next;
    }
    return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    int lenA = getListLength(headA);
    int lenB = getListLength(headB);

    int diff = abs(lenA - lenB);
    printf("difference is %d\n", diff);
    struct ListNode *start = NULL;
    struct ListNode *other = NULL;
    int i = 0;
    if (lenA > lenB) {
        //traverse ListA by diff nodes
        start = headA;
        other = headB;
    } else {
        start = headB;
        other = headA;
    }
     while (i < diff) {
        start = start->next;
        i++;
    }
    printf("start is %d, other is %d\n", start->val, other->val);
    while (start != NULL || other != NULL) {
        printf("start:0x%" PRIXPTR " other:0x%" PRIXPTR "\n", (uintptr_t)start, (uintptr_t)other);
        if (start == other) {
            //found the intersection
            printf("found start\n");
            return start;
        }
        start = start->next;
        other = other->next;
    }
    return NULL;
}

void printList(struct ListNode *list) {
    if (!list) {
        return;
    }
    while(list) {
        printf("%d --> ", list->val);
        list = list->next;
    }
    printf("\n");
}

int main() {

    //intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3

    struct ListNode *A0 = malloc (sizeof(struct ListNode));
    A0->val = 4;
    struct ListNode *A1 = malloc (sizeof(struct ListNode));
    A1->val = 1;
    struct ListNode *A2 = malloc (sizeof(struct ListNode));
    A2->val = 8;
    struct ListNode *A3 = malloc (sizeof(struct ListNode));
    A3->val = 4;
    struct ListNode *A4 = malloc (sizeof(struct ListNode));
    A4->val = 5;

    A0->next = A1;
    A1->next = A2;
    A2->next = A3;
    A3->next = A4;
    A4->next = NULL;

    struct ListNode *B0 = malloc (sizeof(struct ListNode));
    B0->val = 5;
    struct ListNode *B1 = malloc (sizeof(struct ListNode));
    B1->val = 0;
    struct ListNode *B2 = malloc (sizeof(struct ListNode));
    B2->val = 1;
    struct ListNode *B3 = A2;

    B0->next = B1;
    B1->next = B2;
    B2->next = B3;

    printList(A0);
    printList(B0);

    printf("A2:0x%" PRIXPTR " B3:0x%" PRIXPTR "\n", (uintptr_t)A2, (uintptr_t)B3);

    if (B3 == A2) {
        printf("equals works\n");
    } else {
        printf("does not work\n");
    }

    struct ListNode *intersection = getIntersectionNode(A0, B0);

    if (intersection) {
        printf("Intersection is %d\n", intersection->val);
    } else {
        printf("Intersection is NULL\n");
    }

    return 0;
}