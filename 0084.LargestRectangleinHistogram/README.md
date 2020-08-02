# [题目](https://leetcode.com/problems/largest-rectangle-in-histogram/)

* Largest Rectangle in Histogram

> Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
![](https://assets.leetcode.com/uploads/2018/10/12/histogram.png)
 
> Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
![](https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png)

> The largest rectangle is shown in the shaded area, which has area = 10 unit.

* Example:

> Input: [2,1,5,6,2,3]

> Output: 10

# 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        int n = heights.size(), l, res;
        heights.push_back(0);
        stack<int> s;
        for (int i = 0; i <= n; i++){
            while (!s.empty() && heights[i] < heights[s.top()]){
                int h = heights[s.top()];
                s.pop();
                if (!s.empty()){
                    l = s.top();
                }
                else{
                    l = -1;
                }
                int temp = (i - l - 1)*h;
                res = max(res, temp);
            }
            s.push(i);
        }
        return res;
    }
};
```

# 思路

* 栈
