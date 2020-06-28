# [题目](https://leetcode.com/problems/valid-sudoku/)

* Valid Sudoku

> Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

>- Each row must contain the digits 1-9 without repetition.
>- Each column must contain the digits 1-9 without repetition.
>- Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

![A partially filled sudoku which is valid.](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

> The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

* Example 1:

> Input:

    [
      ["5","3",".",".","7",".",".",".","."]
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
   ]
   
> Output: true

* Example 2:

> Input:
    [
     ["8","3",".",".","7",".",".",".","."],
     ["6",".",".","1","9","5",".",".","."],
     [".","9","8",".",".",".",".","6","."],
     ["8",".",".",".","6",".",".",".","3"],
     ["4",".",".","8",".","3",".",".","1"],
     ["7",".",".",".","2",".",".",".","6"],
     [".","6",".",".",".",".","2","8","."],
     [".",".",".","4","1","9",".",".","5"],
     [".",".",".",".","8",".",".","7","9"]
    ]

> Output: false

* Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

* Note:

>- A Sudoku board (partially filled) could be valid but is not necessarily solvable.

>- Only the filled cells need to be validated according to the mentioned rules.

>- The given board contain only digits 1-9 and the character '.'.

>- The given board size is always 9x9.


# 代码

```cpp
class Solution{
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        bool row[9][9] = {false}; // row[x][y]: x 行是否使用数字 y + 1
        bool col[9][9] = {false}; // col[x][y]: x 列是否使用数字 y + 1
        bool box[9][9] = {false}; // box[x][y]: 第 x 个方格里是否使用 y + 1
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                int val = (int)(board[i][j] - '1');
                int boxindex = (i/3)*3 + j/3; // 一行一行的数，0-1-2;3-4-5;6-7-8
                if (row[i][val] || col[j][val] || box[boxindex][val]){
                    return false;
                }
                row[i][val] = col[j][val] = box[boxindex][val] = true;
            }
        }
        return true;
    }
};
```

# 复杂度

* 时间复杂度: $O(n^2)$
* 空间复杂度: $O(n^2)$

# 思路

