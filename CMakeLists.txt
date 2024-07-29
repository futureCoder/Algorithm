cmake_minimum_required(VERSION 3.28)
project(Algorithm)

set(CMAKE_CXX_STANDARD 23)

#include_directories(lib/Catch2/build/generated-includes)
include_directories(./src/)
include_directories(./src/leetcode/include)
include_directories(./src/leetcode/editor/cn/)

include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.10  # 选择具体的版本号
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests examples/ut_with_catch2.cpp)
target_link_libraries(tests Catch2::Catch2)
# 在测试目标中链接Catch2

add_subdirectory(lib/simple-logger)

add_executable(quick_sort src/sorting/quick_sort_test.cpp
        src/sorting/heap_sort.h
        src/sorting/heap_sort_test.cpp
        )
target_link_libraries(quick_sort Catch2::Catch2)
# 在测试目标中链接Catch2

add_executable(leetcode
#        src/leetcode/editor/cn/0215.kth-largest-element-in-an-array.cpp
        src/leetcode/editor/cn/0215.kth-largest-element-in-an-array_test.cpp
)
target_link_libraries(leetcode Catch2::Catch2)

add_executable(custom
        src/leetcode/editor/cn/0416.partition-equal-subset-sum_test.cpp
)
target_link_libraries(custom Catch2::Catch2)