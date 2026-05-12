#pragma once
#include <vector>

// Add
int add(int, int);

// Two sum
int binary_search(std::vector<int>& nums, std::vector<int>& indices, int left, int& right, int target);
std::vector<int> twoSum(std::vector<int>& nums, int target);