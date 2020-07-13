# [题目](https://leetcode.com/problems/unique-paths-ii/)

* Unique Paths II

> A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

> The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

> Now consider if some obstacles are added to the grids. How many unique paths would there be?

![](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

> An obstacle and empty space is marked as 1 and 0 respectively in the grid.

* Note: 

> m and n will be at most 100.

* Example 1:

> Input:
```
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
```

> Output: 2

> Explanation:

```
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

# 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int dp[100];
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // 处理第一行
        dp[0] = 1 - obstacleGrid[0][0];
        for (int j = 1; j < n; j++){
            dp[j] = dp[j - 1]*(1 - obstacleGrid[0][j]);
        }
        // 处理其他行
        for (int i = 1; i < m; i++){
            dp[0] *= (1 - obstacleGrid[i][0]); // 第一列只和上面的有关
            for (int j = 1; j < n; j++){
                // 后面的列需要考虑左面和上面元素
                dp[j] = (dp[j] + dp[j - 1])*(1 - obstacleGrid[i][j]);
            }
        }
        return dp[n - 1];
    }
};
```

# 思路

* 动态规划
* 一维数组代替二维数组，只需要记录一行的情况。