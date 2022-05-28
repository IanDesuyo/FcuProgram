#include <stdlib.h>

typedef struct listNode {
    int val;
    struct listNode* next;
} ListNode;

ListNode* mergeNodes(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL;

    while (curr != NULL) {
        if (curr->val == 0) {
            curr = curr->next;

            if (prev != NULL) {
                prev->next = curr;
                prev = curr;
            } else {
                prev = curr;
                head = prev;
            }
        } else {
            prev->val += curr->val;
        }

        if (curr != NULL) {
            curr = curr->next;
        }
    }

    return head;
}