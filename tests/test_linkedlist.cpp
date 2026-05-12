#include <gtest/gtest.h>
#include <random>
#include "helper/helper.h"
#include "utils/listnode.h"

TEST(Linkedlist, Linkedlist) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<> size_dist(0, 1e4);
    std::uniform_int_distribution<> num_dist(-1e5, 1e5);
    int n_test = 100;
    for (int i = 0; i < n_test; i++) {
        int sz_list = size_dist(generator);
        std::vector<int> v(sz_list);
        std::generate(v.begin(), v.end(), [&]() {
            return num_dist(generator);
        });
        
        ListNode* l1 = vector_to_listnode(v);
        ListNode* l1_ptr = l1;
        int l1_idx = 0;
        while (l1_ptr) {
            EXPECT_LE(l1_idx, sz_list);
            EXPECT_EQ(l1_ptr->val, v[l1_idx]);
            l1_ptr = l1_ptr->next;
            l1_idx++;
        }
        EXPECT_EQ(l1_idx, sz_list);
        EXPECT_EQ(l1_ptr, nullptr);

        std::vector<int> v_clone = listnode_to_vector(l1);
        EXPECT_EQ(v, v_clone);

        ListNode* l1_clone = vector_to_listnode(v_clone);
        bool equals = listnodes_equal(l1, l1_clone);
        EXPECT_TRUE(equals);
        delete l1;
        delete l1_clone;
    }
}