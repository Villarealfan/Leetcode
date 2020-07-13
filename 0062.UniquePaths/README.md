# [题目](https://leetcode.com/problems/unique-paths/)

* Unique Paths

> A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

> The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

> How many possible unique paths are there?

![](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

> Above is a 7 x 3 grid. How many possible unique paths are there?

* Example 1:

> Input: m = 3, n = 2

> Output: 3

* Explanation:

> From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
```
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
```

* Example 2:

> Input: m = 7, n = 3

> Output: 28

* Constraints:

>- 1 <= m, n <= 100

>- It's guaranteed that the answer will be less than or equal to $2*10^9$.

# 代码

```cpp
class Solution {
public:
    int uniquePaths_dp1(int m, int n) {
        int dp[100][100];
        for (int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++){
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths_dp2(int m, int n){
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }

    int uniquePaths_math(int m, int n){
        int x = m + n - 2;
        int k = min(m,n) - 1;
        long a = 1, b = 1;
        while (k >= 1){
            a *= x;
            b *= k;
            x--;
            k--;
        }
        return (int)(a/b);
    }
};
```

# 思路

* 动态规划

>- 状态转移方程：

$dp[i][j] = dp[i-1][j] + dp[i][j - 1]$ 

其中 $dp[i - 1][j]$ 是从左边来的，$dp[i][j - 1]$ 是从上面来的

>- 边界情况

$dp[i][0] = 1$，一路向下

$dp[0][j] = 1$，一路向右

* 二维数组改为一维数组存储

> 只需要记录各行或者各列情况

* 组合数
> 往下需要 m - 1 步，往右需要 n - 1 步，总共 m+n-2步，因此总共可能情况：

$C_{m+n-2}^{m-1} = C_{m+n-2}^{n - 1}$

