# [题目](https://leetcode.com/problems/container-with-most-water/)

* Container With Most Water

> Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

* Note: You may not slant the container and n is at least 2.

<img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg" width="100%">


The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

* Example:

> Input: [1,8,6,2,5,4,8,3,7]

> Output: 49


# 代码

```cpp
class Solution{
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0;
        while (l < r){
            int hl = height[l], hr = height[r];
            int area = min(hl, hr)*(r - l);
            if (area > maxArea){
                maxArea = area;
            }
            if (hl < hr){
                l++;
            }
            else{
                r--;
            }
        }
        return maxArea;
    }
};
```

# 复杂度
* 时间复杂度: $O(n)$
* 空间复杂度: $O(1)$

# 思路
* 双指针

