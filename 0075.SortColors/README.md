# [题目](https://leetcode.com/problems/sort-colors/)

* Sort Colors

> Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

>- Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

* Note: 

> You are not suppose to use the library's sort function for this problem.

* Example:

> Input: [2,0,2,1,1,0]

> Output: [0,0,1,1,2,2]

* Follow up:

>- A rather straight forward solution is a two-pass algorithm using counting sort.
>- First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
>- Could you come up with a one-pass algorithm using only constant space?

# 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1, two = nums.size(), index = 0;
        while (index < two){
            if (nums[index] == 0){
                swap(nums[index++], nums[++zero]);
            }
            else if (nums[index] == 1){
                index++;
            }
            else{
                swap(nums[index++], nums[--two]);
            }
        }
        return;
    }
};
```

# 思路

* 三路快排
* 0 往左边放，2 往右边放
