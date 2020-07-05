# [题目](https://leetcode.com/problems/maximum-subarray/)

* Maximum Subarray

> Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

* Example:

> Input: [-2,1,-3,4,-1,2,1,-5,4],

> Output: 6

> Explanation: [4,-1,2,1] has the largest sum = 6.

* Follow up:

> If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

# 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum = 0; // 子串求和项
        int maxSum = INT_MIN; // 取 INT_MIN 防止全负数 nums
        for (int& num: nums){
            sum += num;
            // 更新最大值
            if (sum > maxSum){
                maxSum = sum;
            }
            // 前面子串和为负，重新记录子串
            if (sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
};
```

# 思路

* 细节实现，也可以用一维动态规划，用 dp[i] 表示 nums 数组中从 0 到 i 的最大子串和，则
  $dp[i] = max(dp[i - 1], 0) + nums[i]$ ，最后求 dp 中最大元素即可。但一维动态规划需要申请 $O(n)$ 的数组 dp 。
  
* 观察可知，最大和的前面肯定不含和为负数的子串，因此一旦发现前面为负的重新记录子串。