# [题目](https://leetcode.com/problems/n-queens/)

* N-Queens

> The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

![](https://assets.leetcode.com/uploads/2018/10/12/8-queens.png)

> Given an integer n, return all distinct solutions to the n-queens puzzle.

> Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

* Example:

> Input: 4

> Output: 

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

> Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.


# 代码

```cpp
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> queens(n, 0);
        dfs(res, queens, 0, n);
        return res;
    }

private:
    void dfs(vector<vector<string> >& res, vector<int>& queens, int row, const int n){
        if (row == n){
            addQueens(res, queens, n);
            return;
        }
        for (int col = 0; col < n; col++){
            queens[row] = col; // 第 row 行的皇后放在第 col 列
            if (isValid(queens, row)){
                // 一行行的放，放成功了就下一行
                dfs(res, queens, row + 1, n);
            }
        }
    }

private:
    void addQueens(vector<vector<string> >& res, vector<int>& queens, const int n){
        vector<string> solution;
        for (int i = 0; i < n; i++){
            string rowStr;
            // 第 i 行第 j 列是皇后，用 'Q' 代替，否则用 '.' 代替
            for (int j = 0; j < n; j++){
                if (queens[i] == j){
                    rowStr.push_back('Q');
                }
                else{
                    rowStr.push_back('.');
                }
            }
            solution.push_back(rowStr);
        }
        res.push_back(solution);
    }

private:
    bool isValid(vector<int>& queens, int row){
        // 由于是一行行的放，因此考虑合法性时，只需考虑与之前行的皇后，放置的列是否相同，以及是否在一条对角线上
        for (int i = 0; i < row; i++){
            if (queens[i] == queens[row] || abs(queens[i] - queens[row]) == abs(i - row)){
                return false;
            }
        }
        return true;
    }
};
```

# 思路

* dfs 
* $queens[row] = col$, 表示第 row 行第 col 列放置皇后
* 一行行的放，判断合法性时，只需与前几行比较
	* 是否同列: $queens[i] == queens[row]$
	* 是否在一条对角线上: $abs(queens[i] - queens[row]) == abs(i - row)$
