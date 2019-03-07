#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* create_list_from_num(long num) {

    int i = 0;
    int digit = 0;
    struct ListNode *list = NULL;
    //create the first node
    digit = num % 10;
    struct ListNode *l = (struct ListNode*) malloc (sizeof(struct ListNode));
    if (!l)
        return NULL;
    l->val = digit;
    l->next = NULL;

    list = l;

    //create subsequent nodes
    for (i = 1; num/10 > 0; i++) {
        num = num/10;
        digit = num % 10;
        l->next = (struct ListNode*) malloc (sizeof(struct ListNode));
        if (!l->next)
            return NULL;
        l->next->val = digit;
        l->next->next = NULL;
        //for next loop
        l = l->next;
    }
    return list;
}

void print_list(struct ListNode *list) {
    if (!list) {
        return;
    }
    while(list) {
        printf("%d --> ", list->val);
        list = list->next;
    }
    printf("\n");
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    //both empty
    if (!l1 && !l2)
        return NULL;
    //l2 is empty 
    if (l1 && !l2)
        return l1;
    //l1 is empty
    if (l2 && !l1)
        return l2;
    
    //l1 & l2 have atleast one entry
    struct ListNode *head = NULL, *end = NULL;
    if (l1->val <= l2->val) {
        //start with l1
        head = l1;
        end = l1;
        l1 = l1->next;
        end->next = NULL;
        //printf("init: head: %d, end: %d, l1: %d, l2: %d\n", head->val, end->val, l1->val, l2->val);
    } else {
        //start with l2
        head = l2;
        end = l2;
        l2 = l2->next;
        end->next = NULL;
        //printf("init: head: %d, end: %d, l1: %d, l2: %d\n", head->val, end->val, l1->val, l2->val);
    }
    //printf("init: head: %d, end: %d, l1: %d, l2: %d\n", head->val, end->val, l1->val, l2->val);
    //int i = 0;
    while (l1 || l2){
        if (!l1){
            end->next = l2; //append l2
            break;
        } else if (!l2) {
            end->next = l1; //append l1
            break;
        } else if (l1->val <= l2->val){
            end->next = l1;
            end = end->next;
            //printf("%d1: init: head: %d, end: %d, l1: %d, l2: %d\n", i, head->val, end->val, l1->val, l2->val);
            l1 = l1->next;
            end->next = NULL;
        } else {
            end->next = l2;
            end = end->next;
            //printf("%d2: head: %d, end: %d, l1: %d, l2: %d\n", i, head->val, end->val, l1->val, l2->val);
            l2 = l2->next;
            end->next = NULL;
        }
        //printf("%d: head: %d, end: %d, l1: %d, l2: %d\n",i, head->val, end->val, l1->val, l2->val);
        i++;
    }
    return head;
}

int main() {
    struct ListNode *l1 = create_list_from_num(531);
    struct ListNode *l2 = create_list_from_num(642);

    printf("l1: ");
    print_list(l1);
    printf("l2: ");
    print_list(l2);

    struct ListNode *merged = mergeTwoLists(l1,l2);
    printf("l1+l2: ");
    print_list(merged);
}
