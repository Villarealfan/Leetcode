# [题目](https://leetcode.com/problems/implement-strstr/)

* Implement strStr()

> Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

* Example 1:

> Input: haystack = "hello", needle = "ll"
> Output: 2

* Example 2:

> Input: haystack = "aaaaa", needle = "bba"
> Output: -1

* Clarification:

> What should we return when needle is an empty string? This is a great question to ask during an interview.

> For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().


# 代码

```cpp
class Solution{
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.length(), m = needle.length();
        for (int i = 0; i <= n - m; i++){
            if (haystack.substr(i, m) == needle){
                return i;
            }
        }
        return -1;
    }
};
```

# 复杂度

* 时间复杂度: $O(m(n - m))$
* 空间复杂度: $O(1)$

# 思路

* 用 needle 与 haystack 等长的子串逐一对比