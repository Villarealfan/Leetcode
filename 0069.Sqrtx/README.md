# [题目](https://leetcode.com/problems/sqrtx/)

* Sqrt(x)

> Implement int sqrt(int x).

> Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

> Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

* Example 1:

> Input: 4

> Output: 2

* Example 2:

> Input: 8

> Output: 2

* Explanation: 
The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

# 代码

```cpp
class Solution {
public:
    int mySqrt_binarySearch(int x) {
        if (x == 0 || x == 1) return x;
        int l = 1, r = x;
        while (l <= r){
            long mid = l + (r - l)/2;
            long squre = mid*mid; // 防止越界
            if (squre == x){
                return mid;
            }
            else if (squre < x){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return r; // 最终 l = r + 1
    }

    int mySqrt_newton(int x){
        if (x == 0 || x == 1) return x;
        long res = x;
        while (res*res > x){
            // 牛顿法迭代公式
            res = (res + x/res)/2;
        }
        return res;
    }
};
```

# 思路

## 二分搜索

* 注意越界问题
* 注意最终输出，由于向下取整，因此最终的是从 $squre < x$ 这个判断条件过来的，因此 $l++$ ，循环出来时 $ l = r + 1$，r 为向下取整的结果，l 为向上取整的结果。

## 牛顿法

* 相当于求 $y = x^2 - a = 0 $ 的根， 迭代公式

$$
x := x - \frac{f(x)}{f^{'}(x)} = x - \frac{x^2 - a}{2x} = \frac{1}{2}(x + \frac{a}{x})
$$
