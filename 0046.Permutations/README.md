# [题目](https://leetcode.com/problems/permutations/)

* Permutations
> Given a collection of **distinct** integers, return all possible permutations.

* Example:

> Input: [1,2,3]

> Output:

    [
     [1,2,3],
     [1,3,2],
     [2,1,3],
     [2,3,1],
     [3,1,2],
     [3,2,1]
    ]

# 代码


```cpp
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> item;
        vector<bool> used(nums.size(), false);
        dfs(res, item, nums, used);
        return res;
    }

private:
    void dfs(vector<vector<int> >& res, vector<int> item, const vector<int>& nums, vector<bool>& used){
        int m = item.size(), n = nums.size();
        if (m == n){
            res.push_back(item);
            return;
        }
        for (int i = 0; i < n; i++){
            if (used[i]) continue;
            item.push_back(nums[i]);
            used[i] = true;
            dfs(res, item, nums, used);
            item.pop_back();
            used[i] = false;
        }
    }
};
```

# 思路

* dfs
* used 记录 nums 中第 i 个元素是否使用过