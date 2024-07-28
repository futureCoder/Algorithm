//<p>给定整数数组 <code>nums</code> 和整数 <code>k</code>，请返回数组中第 <code><strong>k</strong></code> 个最大的元素。</p>
//
//<p>请注意，你需要找的是数组排序后的第 <code>k</code> 个最大的元素，而不是第 <code>k</code> 个不同的元素。</p>
//
//<p>你必须设计并实现时间复杂度为 <code>O(n)</code> 的算法解决此问题。</p>
//
//<p>&nbsp;</p>
//
//<p><strong>示例 1:</strong></p>
//
//<pre>
//<strong>输入:</strong> <span><code>[3,2,1,5,6,4],</code></span> k = 2
//<strong>输出:</strong> 5
//</pre>
//
//<p><strong>示例&nbsp;2:</strong></p>
//
//<pre>
//<strong>输入:</strong> <span><code>[3,2,3,1,2,4,5,5,6], </code></span>k = 4
//<strong>输出:</strong> 4</pre>
//
//<p>&nbsp;</p>
//
//<p><strong>提示： </strong></p>
//
//<ul> 
// <li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li> 
// <li><code>-10<sup>4</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>4</sup></code></li> 
//</ul>
//
//<div><div>Related Topics</div><div><li>数组</li><li>分治</li><li>快速选择</li><li>排序</li><li>堆（优先队列）</li></div></div><br><div><li>👍 2506</li><li>👎 0</li></div>
#include "cpp_header_template.h"
// 2024-07-28 11:44:58
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size()) {
            return -1;
        }
        return _part_quick_sort(nums, k);
    }
private:
    int _part_quick_sort(std::vector<int>& nums, int k) {
        int target_pivot = nums.size() - k;
        std::stack<std::pair<int, int>> st;
        st.emplace(0, nums.size());
        while (!st.empty()) {
            auto [left, right] = st.top();
            st.pop();
            int pivot = _partition(nums, left, right);
            if (pivot == target_pivot) {
                return nums[pivot];
            }
            if (pivot < target_pivot) {
                st.emplace(pivot + 1, right);
            } else {
                st.emplace(left, pivot);
            }
        }
        return -1;
    }

    int _partition(std::vector<int>& nums, int begin, int end) {
        int pivot = _pivot(begin, end);
        int target = nums[pivot];
        std::swap(nums[pivot], nums[end - 1]);
        int left = begin;
        for (int right = begin; right < end - 1; ++right) {
            if (nums[right] < target) {
                std::swap(nums[left++], nums[right]);
            }
        }
        std::swap(nums[left], nums[end - 1]);
        return left;
    }
    int _pivot(int begin, int end) {
        return std::rand() % (end - begin) + begin;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
