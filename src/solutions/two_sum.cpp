#include "solutions.h"

using std::vector;

int binary_search(vector<int>& nums, vector<int>& indices, int left, int& right, int target) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        int mid_index = indices[mid];
        if (nums[mid_index] == target) return mid;
        if (nums[mid_index] < target) left = mid + 1;
        else right = mid;
    }
    return -1;
}

vector<int> twoSum(vector<int>& nums, int target) {
    const int n_nums = nums.size();
    int left = 0;
    int right = n_nums;
    vector<int> indices(n_nums, 0);
    for (int i = 1; i < n_nums; i++) indices[i] = i;
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return nums[a] < nums[b];
    });

    while (left < right - 1) {
        int t = target - nums[indices[left]];
        int complement_idx = binary_search(nums, indices, left + 1, right, t);
        if (complement_idx != -1) return {indices[left], indices[complement_idx]};
        left++;
        while (nums[indices[left]] == nums[indices[left - 1]]) left++;
    }

    return {0, 0};
}