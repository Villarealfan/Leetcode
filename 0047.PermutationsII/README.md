# [题目](https://leetcode.com/problems/permutations-ii/)

* Permutations II
> Given a collection of numbers that might contain duplicates, return all possible unique permutations.
>
> **Example:**
>
> ```
> Input: [1,1,2]
> Output:
> [
>   [1,1,2],
>   [1,2,1],
>   [2,1,1]
> ]
> ```

# 代码

```cpp
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> item;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(res, item, nums, used);
        return res;
    }

private:
    void dfs(vector<vector<int> >& res, vector<int> item, const vector<int>& nums, vector<bool> used){
        int m = item.size(), n = nums.size();
        if (m == n){
            res.push_back(item);
            return;
        }
        for (int i = 0; i < n; i++){
            // 去重，要么当前值用过，要么相同的前一个值用过
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && used[i - 1])) continue;
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
* 避免重复，需要排序去重，类似操作还有 [Combination Sum II](https://github.com/Villarealfan/Leetcode/tree/master/0040.CombinationSumII)