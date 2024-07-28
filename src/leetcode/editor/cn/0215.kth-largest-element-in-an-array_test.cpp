#define CATCH_CONFIG_MAIN // 这个宏定义告诉Catch2生成main函数

#include <catch2/catch.hpp> // 包含Catch2的头文件
#include "0215.kth-largest-element-in-an-array.cpp"

TEST_CASE("0215_test", "[0215_test]") {
    Solution s;
    std::vector<int> nums{3,2,1,5,6,4};
    REQUIRE(s.findKthLargest(nums,1) == 6);
    REQUIRE(s.findKthLargest(nums,2) == 5);
    REQUIRE(s.findKthLargest(nums,3) == 4);
    REQUIRE(s.findKthLargest(nums,4) == 3);
    REQUIRE(s.findKthLargest(nums,5) == 2);
    REQUIRE(s.findKthLargest(nums,6) == 1);
}