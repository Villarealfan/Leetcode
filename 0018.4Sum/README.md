# [题目](https://leetcode.com/problems/4sum/)

* 4Sum

> Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

* Note:

> The solution set must not contain duplicate quadruplets.

* Example:

        Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

        A solution set is:
        [
         [-1,  0, 0, 1],
         [-2, -1, 1, 2],
         [-2,  0, 0, 2]
        ]


# 代码

```cpp
class Solution{
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重 nums[i]
            for (int j = i + 1; j < n - 2; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // 去重 nums[j]
                int l = j + 1, r = n - 1;
                while (l < r){
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target){
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++; // 去重 nums[l]
                        while (l < r && nums[r] == nums[r - 1]) r--; // 去重 nums[r]
                        l++;
                        r--;
                    }
                    else if (sum < target) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};
```

# 复杂度
* 时间复杂度: $O(n^3)$
* 空间复杂度: $O(n)$

# 思路
* 排序
	
* 双指针
	* 用固定的 nums[i], nums[j] 找有序数组的 Two Sum ，类似于 [3Sum](https://github.com/Villarealfan/Leetcode/tree/master/0015.3Sum) 
* 去重
	* 去重 nums[i]
	* 去重 nums[j]
	* 去重 nums[l]
	* 去重 nums[r] 

