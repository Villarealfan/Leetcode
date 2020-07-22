# [题目](https://leetcode.com/problems/search-a-2d-matrix/)

* Search a 2D Matrix

> Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

> Integers in each row are sorted from left to right.

> The first integer of each row is greater than the last integer of the previous row.

* Example 1:

> Input:
```
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
```

> Output: true

* Example 2:

> Input:
```
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
```

> Output: false

# 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowIndex = getRowIndex(matrix, target);
        return find(matrix[rowIndex], target);
    }

    int getRowIndex(vector<vector<int>>& matrix, int target){
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        int l = 0, r = m;
        while (l < r){
            int mid = l + (r - l)/2;
            if (matrix[mid][n] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return l;
    }

    bool find(vector<int>& row, int target){
        int l = 0, r = row.size() - 1;
        while (l <= r){
            int mid = l + (r - l)/2;
            if (row[mid] == target){
                return true;
            }
            else if (row[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return false;
    }
};
```

# 思路

* 二分搜索，注意题目中每行第一个元素大于上行最后一个元素
* 先二分搜索找对应行号，再在对应行二分搜索该元素
