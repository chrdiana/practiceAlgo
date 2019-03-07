/* detect a loop in linked list */

/* first method is to create a hashtable to addresses and look for match */
/* second method, is to use two pointers, one slow and one fast pointer, and catch up */

#include <stdio.h>

 struct ListNode {
    int val;
    struct ListNode *next;
 };

bool hasCycle(struct ListNode *head) {

    if (head == NULL || head->next == NULL) {
        return false;
    }

    strcut ListNode *slow = head, *fast = head->next;

    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}