#include <gtest/gtest.h>
#include <random>
#include "solutions.h"
#include "helper/helper.h"
#include "utils/listnode.h"

TEST(AddTwoNumbers, AddTwoNumbers) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<> size_dist(0, 1e4);
    std::uniform_int_distribution<> digit_dist(0, 9);
    int n_test = 100;
    for (int i = 0; i < n_test; i++) {
        int n_digits1 = size_dist(generator);
        int n_digits2 = size_dist(generator);
        std::vector<int> v1(n_digits1);
        std::vector<int> v2(n_digits2);
        std::generate(v1.begin(), v1.end(), [&]() {
            return digit_dist(generator);
        });
        std::generate(v2.begin(), v2.end(), [&]() {
            return digit_dist(generator);
        });

        ListNode* l1 = vector_to_listnode(v1);
        ListNode* l2 = vector_to_listnode(v2);

        ListNode* l_sum = addTwoNumbers(l1, l2);
        std::vector<int> output = listnode_to_vector(l_sum);
        if (l_sum) delete l_sum;

        std::vector<int> expected_result;
        int p1 = 0;
        int p2 = 0;
        int digit_sum = 0;
        while (p1 < n_digits1 || p2 < n_digits2) {
            if (p1 < n_digits1) digit_sum += v1[p1];
            if (p2 < n_digits2) digit_sum += v2[p2];
            expected_result.push_back(digit_sum % 10);
            digit_sum /= 10;
            p1++;
            p2++;
        }

        if (digit_sum > 0) expected_result.push_back(digit_sum);

        test_function([&]() {
            return output;
        }, std::vector<std::vector<int>>({expected_result}));

    }
}