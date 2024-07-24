#define CATCH_CONFIG_MAIN // 这个宏定义告诉Catch2生成main函数

#include <catch2/catch.hpp> // 包含Catch2的头文件

// Catch2 项目文档: https://github.com/catchorg/Catch2/blob/v2.13.10/docs/tutorial.md#top

int Factorial(int number) {
    return number <= 1 ? 1 : Factorial(number - 1) * number;
}

TEST_CASE("Factorial function tests", "[factorial]") {
    REQUIRE(Factorial(0) == 1);
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("Another set of tests", "[misc]") {
    REQUIRE(true);
    REQUIRE(42 == 42);
    REQUIRE_FALSE(42 == 42);
}