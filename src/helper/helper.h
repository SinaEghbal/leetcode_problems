#pragma once

#include <gtest/gtest.h>
#include <sstream>
#include <vector>

// Template functions
template<typename T>
void PrintTo(const std::vector<T>& v, std::ostream* os) {
    if (v.empty()) {
        *os << "{}";
        return;;
    }
    int sz_v = v.size();
    *os << "{";
    for (int i = 0; i < sz_v - 1; i++) {
        *os << v[i] << ", ";
    }
    *os << v[sz_v - 1] << "}";
}

template<typename FnT, typename OutputT, typename... ArgsT>
void test_function(FnT fn, std::vector<OutputT> expected, ArgsT... args) {
    auto result = fn(args...);
    EXPECT_TRUE(std::any_of(expected.begin(), expected.end(), [&](const auto& sol) {
        return sol == result;
    }))
        << [&]() {
            std::stringstream ss;
            ss << "Test failed!\narguments: ";
            ((ss << testing::PrintToString(args) << ", "), ...);
            ss << "\nExpected: " << testing::PrintToString(expected)
                << "\nGot: " << testing::PrintToString(result);
            return ss.str();
        }();
}

template<typename FnT, typename OutputT, typename... ArgsT>
void test_function_any_order(FnT fn, std::vector<OutputT> expected, ArgsT... args) {
    std::vector<OutputT> result = fn(args...);
    std::vector<OutputT> result_sorted(result);
    sort(result_sorted.begin(), result_sorted.end());
    std::vector<OutputT> expected_sorted(expected);
    sort(expected_sorted.begin(), expected_sorted.end());

    EXPECT_EQ(result_sorted, expected_sorted)
        << [&]() {
            std::stringstream ss;
            ss << "Test failed!\narguments: ";
            ((ss << testing::PrintToString(args) << ", "), ...);
            ss << "\nExpected: " << testing::PrintToString(expected)
                << "\nGot: " << testing::PrintToString(result);
            return ss.str();
        }();
}
