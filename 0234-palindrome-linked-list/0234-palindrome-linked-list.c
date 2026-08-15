#include <stdbool.h>

bool isPalindrome(struct ListNode* head) {

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    // Find middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode* prev = NULL;
    struct ListNode* curr = slow;

    while (curr != NULL) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare first and second half
    struct ListNode* left = head;
    struct ListNode* right = prev;

    while (right != NULL) {
        if (left->val != right->val) {
            return false;
        }

        left = left->next;
        right = right->next;
    }

    return true;
}