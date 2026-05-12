#include <gtest/gtest.h>
#include <random>
#include "solutions.h"
#include "helper/helper.h"

using std::vector;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

TEST(MathTest, Addition) {
    const int n_test = 1000;
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> num_dist(INT_MIN, INT_MAX);

    for (int i = 0; i < n_test; i++) {
        const int a = num_dist(generator);
        const int b = num_dist(generator);
        test_function(add, vector<int>({a + b}), a, b);
    }
}
