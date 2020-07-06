# [题目](https://leetcode.com/problems/spiral-matrix-ii/)

* Spiral Matrix II

> Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

* Example:

> Input: 3

> Output:

```
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```

# 代码

```cpp
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int rowbegin = 0, rowend = n - 1; // 行上边界和下边界
        int colbegin = 0, colend = n - 1; // 列左边界和右边界
        int count = 1;
        while (rowbegin <= rowend && colbegin <= colend){
            // 从左往右走
            for (int j = colbegin; j <= colend; j++){
                matrix[rowbegin][j] = count++;
            }
            // 向下走一格
            rowbegin++;

            // 从上往下走
            for (int i = rowbegin; i <= rowend; i++){
                matrix[i][colend] = count++;
            }
            // 向左走一格
            colend--;

            //  避免上下越界
            if (rowbegin <= rowend){
                // 从右往左走
                for (int j = colend; j >= colbegin; j--){
                    matrix[rowend][j] = count++;
                }
                // 向上走一格
                rowend--;
            }

            // 避免左右越界
            if (colbegin <= colend){
                // 从下往上走
                for (int i = rowend; i >= rowbegin; i--){
                    matrix[i][colbegin] = count++;
                }
                // 向右走一格
                colbegin++;
            }
        }
        return matrix;
    }
};
```

# 思路

* 细节实现
* 绕着外围顺时针转圈，先从左到右，然后从上到下，然后从右到左，最后从下到上
* 注意避免上下和左右越界问题