#include <gtest/gtest.h>
#include <random>
#include "solutions.h"
#include "helper/helper.h"

using std::vector;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;


TEST(TwoSum, BinarySearch) {
    int n_tests = 100;
    random_device device;
    mt19937 generator(device());
    int thresh = 1e9;
    uniform_int_distribution<> num_dist(-thresh, thresh);
    uniform_int_distribution<> size_dist(2, 1e4);
    vector<int> nums;
    vector<int> indices;
    for (int i = 0; i < n_tests; i++) {
        int n_list = size_dist(generator);
        int count = 0;
        uniform_int_distribution<> list_dist(0, n_list - 1);

        nums.resize(n_list);
        indices.resize(n_list);

        generate(nums.begin(), nums.end(), [&]() {
            return num_dist(generator);
        });
        generate(indices.begin(), indices.end(), [&count] {
            return count++;
        });

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        // 5 items that are in the list
        for (int j = 0; j < 5; j++) {
            int target_idx = list_dist(generator);
            int target = nums[indices[target_idx]];

            // Get all the valid solutions just in case binary search finds a duplicate
            vector<int> solutions;
            while (target_idx > 0 && nums[indices[target_idx - 1]] == target) target_idx--;
            while (target_idx < n_list && nums[indices[target_idx]] == target) {
                solutions.push_back(target_idx);
                target_idx++;
            }
            int right = n_list;
            test_function(binary_search, solutions, nums, indices, 0, right, target);
        }

        // 5 items that aren't in the list
        for (int j = 0; j < 5; j++) {
            int target;
            
            do {
                target = num_dist(generator);
            } while (find(nums.begin(), nums.end(), target) != nums.end());

            int right = n_list;
            test_function(binary_search, vector<int>({-1}), nums, indices, 0, right, target);
        }        
    } 
}

TEST(TwoSum, TwoSum) {
    vector<vector<int>> nums = {{2, 7, 11, 15}, {3, 2, 4}, {3, 3}};
    vector<int> targets = {9, 6, 6};
    vector<vector<int>> expected = {{0, 1}, {1, 2}, {0, 1}};

    for (int i = 0; i < 3; i++) {
        vector<int> output = twoSum(nums[i], targets[i]);
        test_function_any_order(twoSum, expected[i], nums[i], targets[i]);
    }
}
