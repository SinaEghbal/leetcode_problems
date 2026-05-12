 #pragma once
 #include <memory>
 #include <vector>

 // Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() {
        if (next) delete next;
    }
 };

ListNode* vector_to_listnode(const std::vector<int>&);
std::vector<int> listnode_to_vector(ListNode*);
bool listnodes_equal(ListNode*, ListNode*);