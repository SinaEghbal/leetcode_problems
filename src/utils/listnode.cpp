#include "utils/listnode.h"

ListNode* vector_to_listnode(const std::vector<int>& v) {
    if (v.empty()) return nullptr;
    ListNode* head = new ListNode(v[0]);
    ListNode* tail = head;
    for (int i = 1; i < v.size(); i++) {
        tail->next = new ListNode(v[i]);
        tail = tail->next;
    }
    return head;
}

std::vector<int> listnode_to_vector(ListNode* head) {
    std::vector<int> res;
    while (head) {
        res.push_back(head->val);
        head = head->next;
    }
    return res;
}

bool listnodes_equal(ListNode* l1, ListNode* l2) {
    while (l1 || l2) {
        if (!l1 || !l2) return false;
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
}