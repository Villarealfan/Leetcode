# [题目](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

* Remove Duplicates from Sorted Array
> GGiven a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

> Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

* Example 1:

> Given nums = [1,1,2],

> Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

> It doesn't matter what you leave beyond the returned length.

* Example 2:

> Given nums = [0,0,1,1,1,2,2,3,3,4],

> Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

> It doesn't matter what values are set beyond the returned length.

* Clarification:

> Confused why the returned value is an integer but your answer is an array?

> Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

> Internally you can think of this:

    // nums is passed in by reference. (i.e., without making a copy)
    int len = removeDuplicates(nums);
    
    // any modification to nums in your function would be known by the caller.
    // using the length returned by your function, it prints the first len elements.
    for (int i = 0; i < len; i++) {
        print(nums[i]);
    }


# 代码

```cpp
class Solution{
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = 1, n = nums.size();
        for (int i = 1; i < n; i++){
            if (nums[i] != nums[i - 1]){
                nums[len] = nums[i];
                len++;
            }
        }
        return len;
    }
};
```

# 复杂度
* 时间复杂度: $O(n)$
* 空间复杂度: $O(1)$

# 思路
* 由于 len 一直不超过 i, 因此 nums[len] 可以将后面的元素 nums[i] 复制过来