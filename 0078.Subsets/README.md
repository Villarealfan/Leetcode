# [题目](https://leetcode.com/problems/subsets/)

* Subsets

> Given a set of distinct integers, nums, return all possible subsets (the power set).

* Note: 
> The solution set must not contain duplicate subsets.

* Example:

> Input: nums = [1,2,3]

> Output:
```
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```

# 代码

```cpp
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> item;
        dfs(res, item, nums, 0);
        return res;
    }

private:
    void dfs(vector<vector<int> >& res, vector<int> item, vector<int>& nums, int k){
        if (k > nums.size()) return;
        res.push_back(item);
        for (int i = k; i < nums.size(); i++){
            item.push_back(nums[i]);
            dfs(res, item, nums, i + 1);
            item.pop_back();
        }
    }
};
```

# 思路

* DFS
