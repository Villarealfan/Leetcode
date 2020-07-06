# [题目] (https://leetcode.com/problems/spiral-matrix/)

* Spiral Matrix

> Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

* Example 1:

> Input:

```
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
```

> Output: 
```
[1,2,3,6,9,8,7,4,5]
```

* Example 2:

> Input:

```
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
```

> Output:
```
[1,2,3,4,8,12,11,10,9,5,6,7]
```

# 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int rowbegin = 0, rowend = m - 1;
        int colbegin = 0, colend = n - 1;
        while (rowbegin <= rowend && colbegin <= colend){
            //  从左 colbegin 向右走到 colend
            // （0,0）--> (0,1) --> ... --> (0,n - 1)
            for (int j = colbegin; j <= colend; j++){
                res.push_back(matrix[rowbegin][j]);
            }

            // 向下走一格, 更新上边界 rowbegin
            // (0,n - 1) --> (1,n - 1)
            rowbegin++;

            //  从上 rowbegin 向下走到 rowend
            // （1,n - 1）--> (2,n - 1) --> ... --> (n - 1,n - 1)
            for (int i = rowbegin; i <= rowend; i++){
                res.push_back(matrix[i][colend]);
            }

            //  向左走一格，更新右边界 colend
            //  (n - 1, n - 1) --> (n - 1, n - 2)
            colend--;

            // 避免上下越界
            if (rowbegin <= rowend){
                // 从右 colend 向左走到 colbegin
                // (n - 1, n - 2) --> (n - 1,n - 3) --> ... --> (n - 1, 0)
                for (int j = colend; j >= colbegin; j--){
                    res.push_back(matrix[rowend][j]);
                }
                // 向上走一格，更新下边界 rowend
                // (n - 1, 0) --> (n - 2, 0)
                rowend--;
            }

            // 避免左右越界
            if (colbegin <= colend){
                // 从下 rowend 向上走到 rowbegin
                // (n - 2, 0) --> (n - 3,0) --> ... --> (1, 0)
                for (int i = rowend; i >= rowbegin; i--){
                    res.push_back(matrix[i][colbegin]);
                }
                // 向右走一格，更新左边界 colbegin
                // (1,0) --> (1,1)
                colbegin++;
            }
        }
        return res;
    }
};
```

# 思路

* 细节实现
* 绕外围顺时针转，同 [Spiral Matrix II](https://github.com/Villarealfan/Leetcode/tree/master/0059.SpiralMatrixII)