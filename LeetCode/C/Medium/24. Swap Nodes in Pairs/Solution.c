#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    // Base cases: if list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Dummy node to handle head swap cleanly
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (prev->next != NULL && prev->next->next != NULL) {
        // Pointers to the two nodes to be swapped
        struct ListNode* first = prev->next;
        struct ListNode* second = prev->next->next;

        // Swapping pointers
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // Move prev forward two nodes for the next pair
        prev = first;
    }

    return dummy.next;
}