# [题目](https://leetcode.com/problems/minimum-path-sum/)

* Minimum Path Sum

> Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

> Note: You can only move either down or right at any point in time.

* Example:

> Input:
```
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
```

> Output: 7

> Explanation: Because the path 1→3→1→1→1 minimizes the sum.

# 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, grid[0][0]);
        // 第一行
        for (int j = 1; j < n; j++){
            dp[j] = dp[j - 1] + grid[0][j];
        }
        // 其他行
        for (int i = 1; i < m; i++){
            dp[0] += grid[i][0]; // 第一列只能从上面来
            for (int j = 1; j < n; j++){
                // 取左边和上面来的最小的
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};
```

# 思路

* 动态规划

$dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j]$

* 一维数组降低空间复杂度
