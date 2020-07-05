# [题目](https://leetcode.com/problems/n-queens-ii/)

* N-Queens II

> The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

![](https://assets.leetcode.com/uploads/2018/10/12/8-queens.png)

> Given an integer n, return the number of distinct solutions to the n-queens puzzle.

* Example:

> Input: 4

> Output: 2

> Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.

```
    [
     [".Q..",  // Solution 1
      "...Q",
      "Q...",
      "..Q."],

     ["..Q.",  // Solution 2
      "Q...",
      "...Q",
      ".Q.."]
    ]
```

# 代码

```cpp
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> col(n, false); // 列上是否有皇后
        vector<bool> diag45(2*n - 1, false); // 45 度对角线 "/" 上是否有皇后
        vector<bool> diag135(2*n - 1, false); // 135 度对角线 "\" 上是否有皇后
        dfs(res, col, diag45, diag135, n, 0);
        return res;
    }

private:
    void dfs(int& res, vector<bool>& col, vector<bool>& diag45, vector<bool>& diag135, const int n, int i){
        if (i == n){
            // n 行遍历完，说明找到一个可行方案
            res++;
            return;
        }
        for (int j = 0; j < n; j++){
            if (col[j] || diag45[i + j] || diag135[n - 1 - j + i]){
                /*
                 * col[j] = true 表示对应列有皇后
                 * diag45[i + j] = true 表示对应 45 度对角线有皇后
                 * diag135[n - 1 - j + i] = true 表示对应 135 度对角线有皇后
                 *
                 * 45 度对角线编号规则:
                 * (0,0) 第 0 号,(1,0)/(0,1) 第 1 号,...,(n-1,n-1) 2n - 1 号
                 *
                 * 135 度对角线编号规则:
                 * (n-1,0) 第 0 号,(0,0)/(1,1)/.../(n-1,n-1) 第 n - 1 号,...,
                 * (0, n - 1) 第 2n - 1 号
                 */
                continue;
            }
            col[j] = diag45[i + j] = diag135[n - 1 - j + i] = true;
            dfs(res, col, diag45, diag135, n, i + 1); // 遍历下一行
            col[j] = diag45[i + j] = diag135[n - 1 - j + i] = false;
        }
    }
};
```


# 思路

* dfs
* col 表示对应列是否有皇后
* diag45 表示对应 45 度对角线是否有皇后，编号如下所示

![](https://raw.githubusercontent.com/Villarealfan/Leetcode/master/0052.N-QueensII/45.jpg)

* diag135 表示对应 135 度对角线是否有皇后，编号如下所示

![](https://raw.githubusercontent.com/Villarealfan/Leetcode/master/0052.N-QueensII/135.jpg)


