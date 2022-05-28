#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int val;
    struct listNode* next;
} ListNode;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head;
    ListNode* cur;
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    } else if (list1 == NULL) {
        head = list2;
        list2 = list2->next;
    } else if (list2 == NULL) {
        head = list1;
        list1 = list1->next;
    } else {
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
    }

    cur = head;

    while (list1 != NULL || list2 != NULL) {
        if (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
        } else if (list1 != NULL) {
            cur->next = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }

        cur = cur->next;
    }

    return head;
}

int main() {
    int x;
    ListNode* prev;
    ListNode* cur;

    printf("List1: ");
    ListNode* list1 = NULL;
    while (scanf("%d", &x) != EOF && x != -1) {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = x;
        newNode->next = NULL;

        if (list1 == NULL) {
            list1 = newNode;
        } else {
            prev->next = newNode;
        }

        prev = newNode;
    }

    printf("List2: ");
    ListNode* list2 = NULL;
    while (scanf("%d", &x) != EOF && x != -1) {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = x;
        newNode->next = NULL;

        if (list2 == NULL) {
            list2 = newNode;
        } else {
            prev->next = newNode;
        }

        prev = newNode;
    }

    ListNode* mergedList = mergeTwoLists(list1, list2);

    printf("merge: ");
    while (mergedList != NULL) {
        printf("%d ", mergedList->val);
        mergedList = mergedList->next;
    }

    return 0;
}