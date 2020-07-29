# [题目] (https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

* Search in Rotated Sorted Array II

> Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

> (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

> You are given a target value to search. If found in the array return true, otherwise return false.

* Example 1:

> Input: nums = [2,5,6,0,0,1,2], target = 0

> Output: true

* Example 2:

> Input: nums = [2,5,6,0,0,1,2], target = 3

> Output: false

* Follow up:

> This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?

# 代码
```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            if (nums[l] == target) return true;
            if (nums[r] == target) return true;
            int mid = l + (r - l)/2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[r]){
                r--;
                continue;
            }
            else if (nums[mid] < nums[r]){
                if (target > nums[mid] && target < nums[r]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if (target > nums[l] && target < nums[mid]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};
```

# 思路

* 二分搜索

* 需要注意有重复的数，nums[mid] == nums[r] 时，需要跳过处理
