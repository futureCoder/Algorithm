//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 100 
// 
//
// Related Topics 数组 动态规划 👍 2116 👎 0

#include <unordered_set>

#include "cpp_header_template.h"
// 2024-07-29 13:17:15
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (total_sum % 2 != 0) {
            return false;
        }
        int target = total_sum >> 1;
        std::vector<int> dp(target + 1, 0);

        for (auto num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = std::max(dp[j], dp[j - num] + num); // dp[j]: max_sum <= j 时， 当前元素最多能加到多少
                if (dp[j] == target) {
                    return true;
                }
            }
        }
        for (int j = 0; j < dp.size(); ++j) {
            std::cout << "j: " << j << ", val: " << dp[j] << std::endl;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
