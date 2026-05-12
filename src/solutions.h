#pragma once
#include <vector>
#include "utils/listnode.h"

// Add
int add(int, int);

// Two sum
int binary_search(std::vector<int>&, std::vector<int>&, int, int&, int);
std::vector<int> twoSum(std::vector<int>&, int);

// Add two numbers
ListNode* addTwoNumbers(ListNode*, ListNode*);