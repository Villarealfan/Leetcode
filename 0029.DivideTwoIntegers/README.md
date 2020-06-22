# [题目](https://leetcode.com/problems/divide-two-integers/)

* Divide Two Integers

> Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

> Return the quotient after dividing dividend by divisor.

> The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

* Example 1:

> Input: dividend = 10, divisor = 3

> Output: 3

> Explanation: 10/3 = truncate(3.33333..) = 3.

* Example 2:

> Input: dividend = 7, divisor = -3

> Output: -2

> Explanation: 7/-3 = truncate(-2.33333..) = -2.

* Note:

>- Both dividend and divisor will be 32-bit signed integers.

>- The divisor will never be 0.

>- Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: $[−2^{31},  2^{31} − 1]$. For the purpose of this problem, assume that your function returns $2^{31} − 1$ when the division result overflows.


# 代码

```cpp
class Solution{
public:
    int divide(int dividend, int divisor) {
        // 分母为 1，结果为其本身
        if (divisor == 1) return dividend;

        // 同号+, 异号-
        int sign;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)){
            sign = 1;
        }
        else{
            sign = -1;
        }

        long long a = abs((long long)dividend), b = abs((long long) divisor), res = 0;

        /*
         * a = b*2^m1 + b*2^m2 + ... + b*2^mn + c
         * res = 2^m1 + 2^m2 + ... + 2^mn
         */
        while (a >= b){
            long long temp = b, m = 1;
            // 求满足 a >= b * 2^m 的最大 m
            while (a >= (temp<<1)){
                temp<<=1; // b*2
                m<<=1; // m*2
            }
            a -= temp;
            res += m;
        }

        // 结果处理，考虑正负，避免越界
        if (sign == 1){
            if (res >= INT_MAX){
                return INT_MAX;
            }
            else{
                return (int)res;
            }
        }
        else{
            if (-res >= INT_MIN){
                return (int)(-res);
            }
            else{
                return INT_MIN;
            }
        }
    }
};
```

# 复杂度

* 时间复杂度: $O(\log n)$
* 空间复杂度: $O(1)$

# 思路

* 最直接的想法是逐次减去被除数，优化一下，考虑被除数翻倍的情况，由于不让用乘除法，可以通过位运算得到被除数的两倍，因此，考虑 

  $a = b\times 2^{m_1} + b\times 2^{m_2} + ... + b\times 2^{m_n} + c$

  需要找到对应的 $m_{1}, m_{2}, \cdots, m_{n}$ , 则商 $res = 2^{m_1} + 2^{m_2}+ \cdots + 2^{m_n}$。

  举例说明， $a = 31,\ b = 3, \ a/b = 31/3 = 10...1$ , 

  $31 = 3\times 2^3 + 3\times 2^1 + 1 = 3\times 8 + 3\times 2 + 1 = 24 + 6 + 1$

  其中 $m_{1} = 3, m_{2} = 1$。

  于是

  $res = 2^3 + 2^1 = 8+2 = 10$

  

* 那么问题就是如何找这些 $m_{1}, m_{2}, \cdots, m_{n}$，首先找 $m_{1}$，可以不断比较 $b = 2\times b $ 与 $a$ 的大小，找到最大满足的 $m_1$ 

  还是上面的例子

  >- $31 > 3\times 2^1 = 6$
  >- $31 > 3\times 2^2 = 12$
  >- $31 > 3\times 2^3 = 24$
  >- $31 < 3\times 2^4 = 48$
  
  因此 $m_{1} = 3$
  
* 找 $m_{2}$ 时，就是不断比较 $b = 2\times b $  与  $a - b\times 2^{m_1}$ 的大小，找到最大满足的 $m_{2}$

  接着上面的例子， $a - b\times 2^{m_1} = 31 - 3\times 2^3 = 31 - 24 = 7$
  >- $7 > 3\times 2 = 6$
  >- $7 < 3\times 2^2 = 12$

  因此 $m_{2} = 1$

* 则 $a - b\times 2^{m_1} - b\times 2^{m_2} = 31 - 3\times 2^3 - 3\times 2^1 = 31 - 24 - 6 = 1 = c$，
  而 $1 < 3$ ，算法终止。

最终， $res = 2^{m_1} + 2^{m_2} = 2^3 + 2^1 = 8 + 2 = 10$ 。
