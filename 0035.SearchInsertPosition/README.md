# [题目](https://leetcode.com/problems/search-insert-position/)

* Search Insert Position

> Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

> You may assume no duplicates in the array.

* Example 1:

> Input: [1,3,5,6], 5

> Output: 2

* Example 2:

> Input: [1,3,5,6], 2

> Output: 1

* Example 3:

> Input: [1,3,5,6], 7

> Output: 4

* Example 4:

> Input: [1,3,5,6], 0

> Output: 0


# 代码

```cpp
class Solution{
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            int mid = l + (r - l)/2;
            if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return l;
    }
};
```

# 复杂度

* 时间复杂度: $O(\log n)$
* 空间复杂度: $O(1)$

# 思路

* 二分搜索

