# [题目](https://leetcode.com/problems/trapping-rain-water/)

* Trapping Rain Water

> Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

![](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

> The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

* Example:

> Input: [0,1,0,2,1,0,1,3,2,1,2,1]

> Output: 6


# 代码

```cpp
class Solution{
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int hlmax = 0, hrmax = 0; // 左右高度最小值
        int res = 0;
        while (l < r){
            if (height[l] < height[r]){
                hlmax = max(hlmax, height[l]);
                res += hlmax - height[l];
                l++;
            }
            else{
                hrmax = max(hrmax, height[r]);
                res += hrmax - height[r];
                r--;
            }
        }
        return res;
    }
};
```

# 复杂度

* 时间复杂度: $O(n)$
* 空间复杂度: $O(1)$

# 思路

* 双指针