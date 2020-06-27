# [题目](https://leetcode.com/problems/search-in-rotated-sorted-array/)

* Search in Rotated Sorted Array

> Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

> You are given a target value to search. If found in the array return its index, otherwise return -1.

> You may assume no duplicate exists in the array.

> Your algorithm's runtime complexity must be in the order of O(log n).

* Example 1:

> Input: nums = [4,5,6,7,0,1,2], target = 0

> Output: 4

* Example 2:

> Input: nums = [4,5,6,7,0,1,2], target = 3

> Output: -1


# 代码

```cpp
class Solution{
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            int mid = l + (r - l)/2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < nums[r]){
                if (target > nums[mid] && target < nums[r]){
                    // target 在右半边
                    l = mid + 1;
                }
                else{
                    // target 在左半边
                    r = mid - 1;
                }
            }
            else{
                if (target > nums[l] && target < nums[mid]){
                    // target 在左半边
                    r = mid - 1;
                }
                else{
                    // target 在右半边
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};
```

# 复杂度

* 时间复杂度: $O(\log n)$
* 空间复杂度: $O(1)$

# 思路

* 二分搜索

