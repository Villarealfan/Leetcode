# [题目](https://leetcode.com/problems/rotate-image/)

* Rotate Image

> You are given an n x n 2D matrix representing an image.

> Rotate the image by 90 degrees (clockwise).

* Note:

> You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

* Example 1:

> Given input matrix = 

    [
     [1,2,3],
     [4,5,6],
     [7,8,9]
    ],

> rotate the input matrix in-place such that it becomes:

     [
      [7,4,1],
      [8,5,2],
      [9,6,3]
     ]

* Example 2:

> Given input matrix =

    [
      [ 5, 1, 9,11],
      [ 2, 4, 8,10],
      [13, 3, 6, 7],
      [15,14,12,16]
    ], 

> rotate the input matrix in-place such that it becomes:

    [
     [15,13, 2, 5],
     [14, 3, 4, 1],
     [12, 6, 8, 9],
     [16, 7,10,11]
    ]

# 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; i++){
            for (int j = i; j < n - 1 - i; j++){
                /*
                 * 规律:
                 * matrix[a][b] <-- matrix[c][d]
                 * a = d, b + c = n - 1
                 */
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
        return;
    }
};
```

# 思路

* 找规律，如矩阵
```
    [                      [
      [ 5, 1, 9,11],         [15,13, 2, 5],
      [ 2, 4, 8,10],         [14, 3, 4, 1],
      [13, 3, 6, 7],  -->    [12, 6, 8, 9],
      [15,14,12,16]          [16, 7,10,11],
    ]                      ]
```

* 值:     1   --> 10  --> 12 --> 13
	坐标: 0,1 --> 1,3 --> 3,2 --> 2,0

*	值：     9   --> 7  --> 14 --> 2
	坐标： 0,2 --> 2,3 --> 3,1 --> 1,0

	  i,j --> j, n - 1 - i  --> n - 1 - i, n - 1 - j  -->  n - 1 - j 
	
>- $matrix[a][b] <-- matrix[c][d]$
>-  $a = d, b + c = n - 1$

* 一次旋转是 4 个元素互相交换，注意 i,j 的范围, 如下图所示，从 n = 3 到 n = 6, 红 -> 蓝 -> 黄 -> 绿的旋转顺序

![](https://github.com/Villarealfan/Leetcode/blob/master/0048.RotateImage/rotate.png)
