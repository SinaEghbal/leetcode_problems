cmake_minimum_required(VERSION 4.3)

project(LeetCodePractice)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)

file(GLOB SOLUTIONS_SRCS src/solutions/*.cpp src/utils/*.cpp)
message("Included sources: ${SOLUTIONS_SRCS}")
add_library(solutions ${SOLUTIONS_SRCS})

target_include_directories(solutions PUBLIC src)

file(GLOB TESTS_SRCS tests/*.cpp)
add_executable(unit_tests ${TESTS_SRCS})
target_link_libraries(unit_tests PRIVATE solutions GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)