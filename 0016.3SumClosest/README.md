# [题目](https://leetcode.com/problems/3sum-closest/)

* 3Sum Closest

> Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

* Example 1:

> Input: nums = [-1,2,1,-4], target = 1

> Output: 2

> Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 
* Constraints:

>- $3 <= nums.length <= 10^3$
>- $-10^3 <= nums[i] <= 10^3$
>- $-10^4 <= target <= 10^4$


# 代码

```cpp
class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int close_sum = nums[0] + nums[1] + nums[2];
        int min_diff = abs(close_sum - target);
        int n = nums.size();
        for (int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                int diff = abs(sum - target);
                if (diff < min_diff){
                    min_diff = diff;
                    close_sum = sum;
                }
                if (sum < target){
                    l++;
                }
                else if (sum > target){
                    r--;
                }
                else{
                    return sum;
                }
            }
        }
        return close_sum;
    }
};
```

# 复杂度
* 时间复杂度: $O(n^2)$
* 空间复杂度: $O(1)$

# 思路
* 排序
	
* 双指针
	* 用固定的 nums[i] 找有序数组的 Two Sum 
	
* 比较，记录最小的和

