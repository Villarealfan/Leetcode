# [题目](https://leetcode.com/problems/set-matrix-zeroes/)

* Set Matrix Zeroes

> Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

* Example 1:

> Input: 
```
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
```

> Output: 
```
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
```

* Example 2:

> Input: 
```
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
```

> Output: 
```
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
```

* Follow up:

>- A straight forward solution using O(mn) space is probably a bad idea.
>- A simple improvement uses O(m + n) space, but still not the best solution.
>- Could you devise a constant space solution?

# 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool flag = false; // 标记第一列是否有 0
        // 若 matrix[i][j] = 0, 将这行和这列的首元素标记为 0
        for (int i = 0; i < m; i++){
            if (matrix[i][0] == 0) flag = true;
            for (int j = 1; j < n; j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // 处理标记，若行列首元素为 0，则该行该列全变为 0
        for (int i = m - 1; i >= 0; i--){
            for (int j = n - 1; j > 0; j--){
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if (flag) matrix[i][0] = 0; // 第一列为 0 时，这列全为 0
        }
        return;
    }
};
```

# 思路

* 细节实现
* 先标记后处理，将非第一列的元素对应行列首元素先变为 0
* 第一列单独标记处理
