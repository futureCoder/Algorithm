//<p>给定一个非负整数数组 <code>nums</code> 和一个整数&nbsp;<code>k</code> ，你需要将这个数组分成&nbsp;<code>k</code><em>&nbsp;</em>个非空的连续子数组。</p>
//
//<p>设计一个算法使得这&nbsp;<code>k</code><em>&nbsp;</em>个子数组各自和的最大值最小。</p>
//
//<p>&nbsp;</p>
//
//<p><strong>示例 1：</strong></p>
//
//<pre>
//<strong>输入：</strong>nums = [7,2,5,10,8], k = 2
//<strong>输出：</strong>18
//<strong>解释：</strong>
//一共有四种方法将 nums 分割为 2 个子数组。 
//其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
//因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。</pre>
//
//<p><strong>示例 2：</strong></p>
//
//<pre>
//<strong>输入：</strong>nums = [1,2,3,4,5], k = 2
//<strong>输出：</strong>9
//</pre>
//
//<p><strong>示例 3：</strong></p>
//
//<pre>
//<strong>输入：</strong>nums = [1,4,4], k = 3
//<strong>输出：</strong>4
//</pre>
//
//<p>&nbsp;</p>
//
//<p><strong>提示：</strong></p>
//
//<ul> 
// <li><code>1 &lt;= nums.length &lt;= 1000</code></li> 
// <li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li> 
// <li><code>1 &lt;= k &lt;= min(50, nums.length)</code></li> 
//</ul>
//
//<div><div>Related Topics</div><div><li>贪心</li><li>数组</li><li>二分查找</li><li>动态规划</li><li>前缀和</li></div></div><br><div><li>👍 973</li><li>👎 0</li></div>
#include "cpp_header_template.h"
// 2024-07-28 13:09:32
//leetcode submit region begin(Prohibit modification and deletion)
// 思路:
// dp[i][j], 表示[i,j]的
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)
