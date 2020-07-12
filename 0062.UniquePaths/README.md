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

```

# 思路

* 动态规划

>- 状态转移方程：

$dp[i][j] = dp[i-1][j] + dp[i][j - 1]$ 

其中 $dp[i - 1][j]$ 是从左边来的，$dp[i][j - 1]$ 是从上面来的

>- 边界情况

	>- $dp[i][0] = 1$，一路向下

	>- $dp[0][j] = 1$，一路向右

* 组合数
> 往下需要 m - 1 步，往右需要 n - 1 步，总共 m+n-2步，因此总共可能情况：
$C_{m+n-2}^{m-1} = C_{m+n-2}^{n - 1}$

