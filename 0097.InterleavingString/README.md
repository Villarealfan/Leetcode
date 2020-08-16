# [题目](https://leetcode.com/problems/interleaving-string/)

* Interleaving String

> Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

* Example 1:

> Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
> Output: true

* Example 2:

> Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
> Output: false

# 代码
```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) return false;
        if (m < n) return isInterleave(s2, s1, s3);
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int j = 1; j <= n; j++){
            dp[j] = (dp[j - 1] && s2[j - 1] == s3[j - 1]);
        }
        for (int i = 1; i <= m; i++){
            dp[0] = (dp[0] && s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= n; j++){
                dp[j] = ((dp[j - 1] && s2[j -1] == s3[i + j - 1])||(dp[j] && s1[i - 1] == s3[i + j - 1]));
            }
        }
        return dp[n];
    }
};
```

# 思路

* 动态规划
