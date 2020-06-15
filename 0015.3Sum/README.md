# [题目](https://leetcode.com/problems/3sum/)

* 3Sum

> Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

* Note:

> The solution set must not contain duplicate triplets.

* Example:

        Given array nums = [-1, 0, 1, 2, -1, -4],

        A solution set is:
        [
         [-1, 0, 1],
         [-1, -1, 2]
        ]


# 代码

```cpp
class Solution{
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重 nums[i]
            int l = i + 1, r = n - 1;
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]){
                        // 去重 nums[l]
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]){
                        // 去重 nums[r]
                        r--;
                    }
                    l++;
                    r--;
                }
                else if (sum < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return res;
    }
};
```

# 复杂度
* 时间复杂度: $O(n^2)$
* 空间复杂度: $O(n)$

# 思路
* 排序
	
* 双指针
	* 用固定的 nums[i] 找有序数组的 Two Sum 
* 去重
	* 去重 nums[i]
	* 去重 nums[l]
	* 去重 nums[r] 

