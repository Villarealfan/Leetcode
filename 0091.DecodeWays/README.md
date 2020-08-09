# [题目](https://leetcode.com/problems/decode-ways/)

* Decode Ways

> A message containing letters from A-Z is being encoded to numbers using the following mapping:
```
'A' -> 1
'B' -> 2
...
'Z' -> 26
```

> Given a non-empty string containing only digits, determine the total number of ways to decode it.

* Example 1:

> Input: "12"

> Output: 2

> Explanation: It could be decoded as "AB" (1 2) or "L" (12).

* Example 2:

> Input: "226"

> Output: 3

> Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

# 代码
```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int one = 1, two = 1, n = s.length();
        for (int i = 1; i < n; i++){
            if (s[i] == '0'){
                one  = 0;
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')){
                one = one + two;
                two = one - two;
            }
            else{
                two = one;
            }
        }
        return one;
    }
};
```

# 思路

* 动态规划

>- 当 s[i] == '0' 时, dp[i] = '0'

>- 当 s[i - 1: i] = '10' ~ '26' 时，dp[i] = dp[i - 1] + dp[i - 2]

>- 其他，dp[i] = dp[i - 1]

* 用 one 和 two 来替代 O(N) 的 dp 数组
