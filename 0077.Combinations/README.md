# [题目](https://leetcode.com/problems/combinations/)

* Combinations

> Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

* Example:

> Input: n = 4, k = 2

> Output:
```
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

# 代码

```cpp
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> item;
        dfs(res, item, n, k, 1);
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, vector<int> item, int n, int k, int index){
        if (k == 0){
            res.push_back(item);
            return;
        }

        for (int i = index; i <= n; i++){
            item.push_back(i);
            dfs(res, item, n, k - 1, i + 1);
            item.pop_back();
        }
    }
};
```

# 思路

* DFS
