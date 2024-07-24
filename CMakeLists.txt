cmake_minimum_required(VERSION 3.28)
project(Algorithm)

set(CMAKE_CXX_STANDARD 23)

include_directories(lib/Catch2/build/generated-includes)

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

add_executable(quick_sort src/sorting/test_quick_sort.cpp)
target_link_libraries(quick_sort Catch2::Catch2)
# 在测试目标中链接Catch2