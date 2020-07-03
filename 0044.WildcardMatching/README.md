# [题目](https://leetcode.com/problems/wildcard-matching/)

* Wildcard Matching

> Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

>- '?' Matches any single character.

>- '*' Matches any sequence of characters (including the empty sequence).

> The matching should cover the entire input string (not partial).

* Note:

>- s could be empty and contains only lowercase letters a-z.

>- p could be empty and contains only lowercase letters a-z, and characters like ? or *.

* Example 1:

> Input: s = "aa", p = "a"

> Output: false

> Explanation: "a" does not match the entire string "aa".

* Example 2:

> Input: s = "aa", p = "*"

> Output: true

> Explanation: '*' matches any sequence.

* Example 3:

> Input: s = "cb", p = "?a"

> Output: false

> Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

* Example 4:

> Input: s = "adceb", p = "*a*b"

> Output: true

> Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

* Example 5:

> Input: s = "acdcb", p = "a*c?b"

> Output: false


# 代码

```cpp
class Solution{
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int m = s.length(), n = p.length();
        int star = -1; // * 出现在 p 中的最新位置
        int match = 0; // 最远匹配的 s 中的位置
        while (i < m){
            if (j < n && (p[j] == s[i] || p[j] == '?')){
                // 常规匹配上了
                i++;
                j++;
            }
            else if (j < n && p[j] == '*'){
                // 遇到 *
                star = j;
                j++;
                match = i;
            }
            else if (star != -1){
                // p = "*c" 尽可能多的匹配
                j = star + 1;
                match++;
                i = match;
            }
            else{
                // 无论如何都没匹配上
                return false;
            }
        }

        // p = "*c*"，* 可以匹配空
        while (j < n && p[j] == '*'){
            j++;
        }

        return j == n;
    }
};
```

# 复杂度

* 时间复杂度: $O(m + n)$
* 空间复杂度: $O(1)$

# 思路

* 双指针
* j = start + 1 是 p = "*c" 尽可能多的匹配 s, j 一直在 c 的位置