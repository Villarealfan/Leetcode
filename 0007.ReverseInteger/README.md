# [题目](https://leetcode.com/problems/reverse-integer/)

* Reverse Integer

> Given a 32-bit signed integer, reverse digits of an integer.

* Example 1:

> Input: 123

> Output: 321

* Example 2:

>Input: -123

> Output: -321

* Example 3:

> Input: 120

> Output: 21

* **Note**:
    
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: $[−2^{31},  2^{31} − 1]$. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.


# 代码

```cpp
class Solution{
public:
    int reverse(int x) {
        long long res = 0;
        while (x != 0){
            res = res*10 + x%10;
            x /= 10;
        }
        if (res >= INT_MIN && res <= INT_MAX){
            return (int)res;
        }
        else{
            return 0;
        }
    }
};
```

# 复杂度
* 时间复杂度: $O(1)$
* 空间复杂度: $O(1)$

# 思路
* 用 long 避免越界，比如 1 开头 9 结尾的很长的数，翻过来可能超过 **INT_MAX**

* 不断加上输入 x 除 10 的余数，按 10 进位即可，x 保留了除 10 的整数部分。
