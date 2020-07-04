# [题目](https://leetcode.com/problems/jump-game-ii)

* Jump Game II

> Given an array of non-negative integers, you are initially positioned at the first index of the array.

> Each element in the array represents your maximum jump length at that position.

> Your goal is to reach the last index in the minimum number of jumps.

* Example:

> Input: [2,3,1,1,4]

> Output: 2

> Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

* Note:

> You can assume that you can always reach the last index.

# 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return 0;
        int step = 0; // 进过区域数
        int l = 0; // 下一步能到达区域左边界
        int r = 0; // 下一步能到达区域右边界
        for (int i = 0; i < nums.size() - 1; i++){
            if (i + nums[i] >= n - 1) return step + 1; // 如果能直接到，直接完成这一跳
            r = max(r, i + nums[i]);
            // 进入下个区域
            if (i == l){
                step++;
                l = r; // 为了跳得尽可能远
            }
        }
        return step;
    }
};
```

# 思路

* 贪心
* 对于 nums = [2,3,1,1,4] 来说，初始第 0 跳 **可能** 跳的区域为  [0,0] 
	* i = 0 时，nums[0] = 2, 能跳的右边界 r = 0 + 2 = 2 , 此时 i = 0 已经进入第 0 跳 **可能**跳的区域  [0,0] 中，则 **完成第 1 跳**，更新 step = 1,  左边界 l = r = 2，此时第 2 跳 **可能** 跳的区域为 [2,2]，其实 i = 0 时位于出发点，无论如何总是要跳的;
	* i = 1 时，nums[1] = 3, 能跳的右边界 r = 1 + 3 = 4, 左边界 l = 2, step = 1, 第 2 跳 **可能** 跳的区域为 [2,4], 其实已经到达终点了，直接完成第 2 跳;