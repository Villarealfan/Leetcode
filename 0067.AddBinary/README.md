# [题目](https://leetcode.com/problems/add-binary/)

* Add Binary

> Given two binary strings, return their sum (also a binary string).

> The input strings are both non-empty and contains only characters 1 or 0.

* Example 1:

> Input: a = "11", b = "1"

> Output: "100"

* Example 2:

> Input: a = "1010", b = "1011"

>Output: "10101"

* Constraints:

>- Each string consists only of '0' or '1' characters.
>- 1 <= a.length, b.length <= $10^4$
>- Each string is either "0" or doesn't contain any leading zero.


# 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0, sum = 0;
        // 从后往前加
        while (i >= 0 || j >= 0){
            sum = carry;
            // a,b 不到头就加
            if (i >= 0){
                sum += (a[i] - '0');
                i--;
            }
            if (j >= 0){
                sum += (b[j] - '0');
                j--;
            }
            // 注意是二进制
            res.push_back(sum%2 + '0');
            carry = sum/2;
        }

        // 最后进位
        if (carry != 0){
            res.push_back(carry + '0');
        }
        // 翻转
        reverse(res.begin(), res.end());
        return res;
    }
};
```

# 思路

* 细节实现