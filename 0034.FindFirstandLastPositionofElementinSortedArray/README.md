# [题目](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

* Find First and Last Position of Element in Sorted Array

> Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

> Your algorithm's runtime complexity must be in the order of O(log n).

> If the target is not found in the array, return [-1, -1].

* Example 1:

> Input: nums = [5,7,7,8,8,10], target = 8

> Output: [3,4]

* Example 2:

> Input: nums = [5,7,7,8,8,10], target = 6

> Output: [-1,-1]
 
* Constraints:

>- $0 <= nums.length <= 10^5$
>- $-10^9 <= nums[i] <= 10^9$
>- nums is a non decreasing array.
>- $-10^9 <= target <= 10^9$


# 代码

```cpp
class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int l = 0, r = nums.size() - 1;

        // 二分搜索找最左边的
        while (l <= r){
            int mid = l + (r - l)/2;
            if (nums[mid] == target){
                first = mid;
                r = mid - 1; // 找最左边的
            }
            else if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        if (first == -1){
            l = 0;
        }
        else{
            l = first;
        }
        r = nums.size() - 1;
        // 再次二分搜索找
        while (l <= r){
            int mid = l + (r - l)/2;
            if (nums[mid] == target){
                last = mid;
                l = mid + 1; // 找最右边的
            }
            else if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return {first, last};
    }
};
```

# 复杂度

* 时间复杂度: $O(\log n)$
* 空间复杂度: $O(1)$

# 思路

* 两次二分搜索，先找最左边的，再找最右边的

