# [题目](https://leetcode.com/problems/two-sum/)
* Two Sum

>Given an array of integers, return indices of the two numbers such that they add up to a specific target.

>You may assume that each input would have exactly one solution, and you may not use the same element twice.

* Example:

>Given nums = [2, 7, 11, 15], target = 9,

>Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

# 代码
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> index;
       int n = nums.size();
       for (int i = 0; i < n; i++){
           int other = target - nums[i];
           if (index.find(other) != index.end()){
               return {index[other], i};
           }
           index[nums[i]] = i;
       }
       return {-1, -1};
    }
};
```

# 复杂度
* 时间复杂度: O(n) 
* 空间复杂度: O(n)

# 思路
* index 存储 <数字的值，数字在 nums 中的位置> 
* hashmap 查询时间复杂度为 O (1) 