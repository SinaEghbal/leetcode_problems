#include "solutions.h"
#include "utils/listnode.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = l1;
    ListNode* l2_ptr = l2; // Keep a copy for cleaning
    // Add l2 to l1 and return it!
    bool carry = false;
    ListNode* l1_prev = nullptr;
    ListNode* l2_prev = nullptr;
    while (l1 || l2) {
        if (!l1) {
            l1_prev->next = l2;
            l1 = l2;
            if (l2_prev) l2_prev->next = nullptr;
            break;
        } else if (!l2) {
            break;
        } else {
            l1->val += l2->val;
            if (carry) l1->val++;
            if (l1->val >= 10) {
                l1->val -= 10;
                carry = true;
            } else carry = false;
        }

        l2_prev = l2;
        l1_prev = l1;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (carry) {
        if (!l1 && carry) {
            l1_prev->next = new ListNode(1);
            break;
        }
        l1->val++;
        if (l1->val >= 10) {
            l1->val -= 10;
            carry = true;
        } else carry = false;
        l1_prev = l1;
        l1 = l1->next;
    }

    if (l2_ptr) delete l2_ptr;
    return res;
}