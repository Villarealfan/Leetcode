# [题目](https://leetcode.com/problems/combination-sum/)

* Combination Sum

> Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

> The same repeated number may be chosen from candidates unlimited number of times.

* Note:

> All numbers (including target) will be positive integers.
> The solution set must not contain duplicate combinations.

* Example 1:

> Input: candidates = [2,3,6,7], target = 7,

> A solution set is:
    [
     [7],
     [2,2,3]
    ]

* Example 2:

> Input: candidates = [2,3,5], target = 8,

> A solution set is:
    [
     [2,2,2,2],
     [2,3,3],
     [3,5]
    ]


# 代码

```cpp
class Solution{
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> item;
        dfs(res, item, candidates, target, 0);
        return res;
    }

private:
    void dfs(vector<vector<int> >& res, vector<int> item, vector<int>& candidates, int target, int start){
        if (target < 0) return;
        if (target == 0){
            res.push_back(item);
            return;
        }
        int n = candidates.size();
        for (int i = start; i < n; i++){
            item.push_back(candidates[i]);
            dfs(res, item, candidates, target - candidates[i], i);
            item.pop_back();
        }
    }
};
```

# 复杂度

* 时间复杂度: 指数级
* 空间复杂度: $O(n!)$

# 思路

* DFS
* 注意 candidates 中元素可以重复利用，因此
```cpp
dfs(res, item, candidates, target - candidates[i], i);
```
这里还是要考虑第 $i$ 个元素。