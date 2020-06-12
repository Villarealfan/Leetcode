# [题目](https://leetcode.com/problems/palindrome-number/)

* Palindrome Number

> Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

* Example 1:

> Input: 121

> Output: true

* Example 2:

> Input: -121

> Output: false

> Explanation: From left to right, it reads **-121**. From right to left, it becomes **121-**. Therefore it is not a palindrome.

* Example 3:

> Input: 10

> Output: false
> Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

* Follow up:

Coud you solve it without converting the integer to a string?

# 代码

```cpp
class Solution{
public:
    bool isPalindrome(int x) {
        if (x < 0 || x%10 == 0) return false;
        int y = 0;
        while (x > y){
            y = y*10 + x%10;
            x /= 10;
        }
        return (x == y || x == y/10); // 1221, 12321
    }
};
```

# 复杂度
* 时间复杂度: $O(n)$ , $n$ 为 x 的位数
* 空间复杂度: $O(1)$

# 思路
* 边界情况
	* 负数肯定不是回文
	* 10, 200, 2000, 这些以 0 结尾的肯定也不是回文，因为最高位不为 0
	* 需要考虑位数的奇偶性，如 1221 得到 x = 12, y = 21; 12321 得到 x = 12, y = 123, y 比 x 多了一位

