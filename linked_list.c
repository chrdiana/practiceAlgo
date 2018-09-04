/*
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//[2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9]
//[5,6,4,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9,9,9,9]

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

long get_num_from_list(struct ListNode *list) {
    if (!list)
        return INT_MIN;
    long i = 1;
    long num = 0;
    
    while(list) {
        num += (list->val * i);
        list = list->next;
        i *= 10;
    }
    return num;
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

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    if (!l1 && !l2)
        return NULL;
    int carry = 0;
    int num1 = 0, num2 = 0, sum;
    struct ListNode *sum_l = NULL, *head = NULL,*prev=NULL;
    int i = 0;
    while(l1 || l2) {
        num1 = l1? l1->val : 0;
        num2 = l2? l2->val : 0;
        sum_l = (struct ListNode*) malloc (sizeof(struct ListNode));
        if (!sum_l)
            return NULL;
        sum = num1+num2+carry;
        if (sum >= 10) 
            carry = 1;
        else
            carry = 0;
        sum_l->val = sum%10;
        sum_l->next = NULL;
        if (prev)
            prev->next = sum_l;
        prev = sum_l;
        if (!i)
            head = sum_l;
        i=1;
        l1 = l1? l1->next : NULL;;
        l2 = l2? l2->next : NULL;
    }
    if (carry){
        prev->next = (struct ListNode*) malloc (sizeof(struct ListNode));
        if (!prev->next)
            return NULL;
        prev->next->val = carry;
        prev->next->next = NULL;
    }
    return head;
}
struct ListNode* addTwoNumbers2(struct ListNode *l1, struct ListNode *l2) {
    if (!l1 || !l2)
        return NULL;
    struct ListNode *sum = NULL;
    long num1 = get_num_from_list(l1);
    long num2 = get_num_from_list(l2);

    sum = create_list_from_num(num1+num2);
    return sum;
}

int main() {
    struct ListNode *l1 = create_list_from_num(9);
    print_list(l1);
    printf("l1: %ld\n", get_num_from_list(l1));
    struct ListNode *l2 = create_list_from_num(9999999991);
    print_list(l2);
    printf("l2: %ld\n", get_num_from_list(l2));
    
    struct ListNode *sum = addTwoNumbers(l1,l2);
    printf("SUM:");
    print_list(sum);
}
