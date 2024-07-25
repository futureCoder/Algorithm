#include <vector>



class QuickSort {
public:
    static void sort(std::vector<int>& nums) {
        _sort(nums, 0, nums.size());
    }
private:
    static void _sort(std::vector<int>& nums, int begin, int end) {
        if (begin >= end) {
            return;
        }
        std::stack<std::pair<int, int>> stk;
        stk.emplace(begin, end);
        while (!stk.empty()) {
            auto [b, e] = stk.top();
            stk.pop();
            int pivot = _partition(nums, b, e);
            if (pivot - 1 > b) {
                stk.emplace(b, pivot);
            }
            if (pivot + 1 < e) {
                stk.emplace(pivot + 1, e);
            }
        }
    }
    static int _partition(std::vector<int>& nums, int begin, int end) {
        int pivot = _pivot(begin, end);
        int target = nums[pivot];
        std::swap(nums[pivot], nums[end - 1]);
        int i = begin;
        for (int j = begin; j < end - 1; ++j) {
            if (nums[j] < target) {
                std::swap(nums[i++], nums[j]);
            }
        }
        std::swap(nums[i], nums[end - 1]);
        return i;
    }
    static int _pivot(int begin, int end) {
        // 返回[begin,end)区间内的随机数
        int range = end - begin;
        return std::rand() % range + begin;
    }
};
