#define CATCH_CONFIG_MAIN // 这个宏定义告诉Catch2生成main函数

#include <catch2/catch.hpp> // 包含Catch2的头文件
#include "0416.partition-equal-subset-sum.cpp"

TEST_CASE("0416_test", "[0416_test]") {
    Solution s;
    std::vector<int> nums{1, 2, 5};
    REQUIRE(s.canPartition(nums) == false);
}