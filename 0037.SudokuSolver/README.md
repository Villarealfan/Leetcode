# [题目](https://leetcode.com/problems/sudoku-solver/)

* Sudoku Solver

> Write a program to solve a Sudoku puzzle by filling the empty cells.

> A sudoku solution must satisfy all of the following rules:

>- Each of the digits 1-9 must occur exactly once in each row.

>- Each of the digits 1-9 must occur exactly once in each column.

>- Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

> Empty cells are indicated by the character '.'.

![A partially filled sudoku which is valid.](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

> A sudoku puzzle...

![A partially filled sudoku which is valid.](https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)

> ...and its solution numbers marked in red.

* Note:

>- The given board contain only digits 1-9 and the character '.'.

>- You may assume that the given Sudoku puzzle will have a single unique solution.

>- The given board size is always 9x9.


# 代码

```cpp
class Solution{
public:
    void solveSudoku(vector<vector<char> >& board) {
        if (board.empty()) return;
        solve(board);
    }

private:
    bool solve(vector<vector<char> >& board){
        // dfs
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == '.'){
                    for (char c = '1'; c <= '9'; c++){
                        if (isValid(board, i, j, c)){
                            board[i][j] = c;
                            if (solve(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool isValid(vector<vector<char> >& board, int row, int col, char cc){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                // 行是否有 cc
                if (board[row][i*3 + j] == cc){
                    return false;
                }

                // 列是否有 cc
                if (board[i*3 + j][col]){
                    return false;
                }

                // 框里是否有 cc
                if (board[3*(row/3) + i][3*(col/3) + j]){
                    return false;
                }
            }
        }
        return true;
    }
};
```

# 复杂度

* 时间复杂度: 指数级的
* 空间复杂度: $O(n^2)$

# 思路

* dfs