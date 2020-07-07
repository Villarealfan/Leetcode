# [题目] (https://leetcode.com/problems/jump-game/)

* Jump Game

> Given an array of non-negative integers, you are initially positioned at the first index of the array.

> Each element in the array represents your maximum jump length at that position.

> Determine if you are able to reach the last index.

* Example 1:

> Input: nums = [2,3,1,1,4]

> Output: true

> Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

* Example 2:

> Input: nums = [3,2,1,0,4]

> Output: false

> Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

* Constraints:

>- $1 <= nums.length <= 3 * 10^4$

>- $0 <= nums[i][j] <= 10^5$

# 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int r = nums[0];
        for (int i = 1; i < n; i++){
            if (r >= i && r <= i + nums[i]){
                // 进入下一个区域[i, i+ nums[i]]
                if (i + nums[i] >= n - 1){
                    // 下个区域直接能到
                    return true;
                }
                r = i + nums[i];
            }
        }
        return r >= n - 1; // 能否到最后一格

    }
};
```
# 思路

* 贪心
* 类似于 [Jump Game II](https://github.com/Villarealfan/Leetcode/tree/master/0045.JumpGameII) , 都是 $[i , i + nums[i]]$ 作为下个跳跃区域