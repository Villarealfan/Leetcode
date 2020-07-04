# [题目](https://leetcode.com/problems/powx-n/)

* Pow(x, n)
> Implement pow(x, n), which calculates x raised to the power n (xn).

* Example 1:

> Input: 2.00000, 10

> Output: 1024.00000

* Example 2:

> Input: 2.10000, 3

> Output: 9.26100

* Example 3:

> Input: 2.00000, -2

> Output: 0.25000

* Explanation:
> $2^{-2} = 1/2^2 = 1/4 = 0.25$

* Note:

>- -100.0 < x < 100.0
>- n is a 32-bit signed integer, within the range $[−2^{31}, 2^{31} − 1]$.

# 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n >= 0){
            return power(x, n);
        }
        else{
            return 1.0/power(x,n);
        }
    }

private:
    double power(double x, int n){
        if (n == 0) return 1.0;
        double y = power(x, n/2);
        if (n %2 == 0){
            return y*y;
        }
        else{
            return y*y*x;
        }
    }
};
```

# 思路

* 二分搜索
	* 奇数，$x^n = x^{2m + 1} = x^{m}\times x^{m}\times x = y\times y \times x$
	* 偶数，$x^n = x^{2m} = x^{m}\times x^{m} = y\times y$

* 递归

