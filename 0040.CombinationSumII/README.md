# [题目](https://leetcode.com/problems/combination-sum-ii/)

* Combination Sum II

> Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

> Each number in candidates may only be used once in the combination.

* Note:

> All numbers (including target) will be positive integers.

> The solution set must not contain duplicate combinations.

* Example 1:

> Input: candidates = [10,1,2,7,6,1,5], target = 8,

> A solution set is:
    
    [
     [1, 7],
     [1, 2, 5],
     [2, 6],
     [1, 1, 6]
    ]

* Example 2:

> Input: candidates = [2,5,2,1,2], target = 5,

> A solution set is:

    [
     [1,2,2],
     [5]
    ]


# 代码

```cpp
class Solution{
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            item.push_back(candidates[i]);
            dfs(res, item, candidates, target - candidates[i], i + 1);
            item.pop_back();
        }
    }
};
```

# 复杂度

* 时间复杂度: 指数级
* 空间复杂度: $O(n!)$

# 思路
* 类似 [CombinationSum](https://github.com/Villarealfan/Leetcode/tree/master/0039.CombinationSum)
* DFS
* 先排序
* 注意去重
```cpp
if (i > start && candidates[i] == candidates[i - 1]) continue;
```
