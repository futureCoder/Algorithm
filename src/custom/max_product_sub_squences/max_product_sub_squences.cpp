//
// Created by 董子雄 on 2024/7/28.
//
// 给定一个整数数组，将这个整数数组拆分为两个子序列，要求返回和的乘积最大的两个子序列
//
// 例1
// 给定 [1, 3, 5, 7, 10]，返回 [1,5,7],[3,10]

#include "leetcode/include/cpp_header_template.h"

class Solution {
public:
    vector<vector<int>> findMaxProductSubsequences(vector<int>& nums) {
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        int target = total_sum / 2;
        std::vector<std::vector<bool>> dp(nums.size() + 1, std::vector<bool>(target + 1, false));
        std::vector<std::vector<int>> path(nums.size() + 1, std::vector<int>(target + 1, 0));

        for (int i = 0; i <= nums.size(); ++i) {
            dp[i][0] = true;
        }

        int max_j = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j - nums[i - 1] >= 0) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                    if (dp[i][j]) {
                        path[i][j] = (dp[i - 1][j - nums[i - 1]]) ? nums[i - 1] : 0;
                        max_j = std::max(max_j, j);
                    }
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        std::cout<<max_j<<std::endl;

        std::vector<int> seq1, seq2;
        int j = max_j;
        for (int i = nums.size(); i > 0 && j > 0; --i) {
            if (path[i][j] > 0) {
                seq1.push_back(path[i][j]);
                j -= path[i][j];
            }
        }

        for (auto num : nums) {
            if (std::find(seq1.begin(), seq1.end(), num) == seq1.end()) {
                seq2.push_back(num);
            }
        }
        return {seq1, seq2};
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6, 9, 1000};
    Solution s;
    auto result = s.findMaxProductSubsequences(nums);
    cout << "Sequence 1: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << "\nSequence 2: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}