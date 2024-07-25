#define CATCH_CONFIG_MAIN // 这个宏定义告诉Catch2生成main函数

#include <catch2/catch.hpp> // 包含Catch2的头文件
#include "quick_sort.h"

TEST_CASE("QuickSort function tests1", "[quick_sort]") {
    std::vector<int> nums = {3, 2, 1, 5, 4};
    QuickSort::sort(nums);
    REQUIRE(nums[0] == 1);
    REQUIRE(nums[1] == 2);
    REQUIRE(nums[2] == 3);
    REQUIRE(nums[3] == 4);
    REQUIRE(nums[4] == 5);
}

TEST_CASE("QuickSort function tests for empty vector", "[quick_sort]") {
    std::vector<int> nums = {};
    QuickSort::sort(nums);
    REQUIRE(nums.size() == 0);
}

TEST_CASE("QuickSort function tests for single element", "[quick_sort]") {
    std::vector<int> nums = {1};
    QuickSort::sort(nums);
    REQUIRE(nums[0] == 1);
}

TEST_CASE("QuickSort function tests for sorted array", "[quick_sort]") {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    QuickSort::sort(nums);
    for(int i = 0; i < nums.size(); i++) {
        REQUIRE(nums[i] == i+1);
    }
}

TEST_CASE("QuickSort function tests for reverse sorted array", "[quick_sort]") {
    std::vector<int> nums = {5, 4, 3, 2, 1};
    QuickSort::sort(nums);
    for(int i = 0; i < nums.size(); i++) {
        REQUIRE(nums[i] == i+1);
    }
}

TEST_CASE("QuickSort function tests for same elements", "[quick_sort]") {
    std::vector<int> nums = {2, 2, 2, 2, 2};
    QuickSort::sort(nums);
    for(int i = 0; i < nums.size(); i++) {
        REQUIRE(nums[i] == 2);
    }
}