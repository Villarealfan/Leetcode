# [题目](https://leetcode.com/problems/scramble-string/)

* Scramble String

> Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

> Below is one possible representation of s1 = "great":

```
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
```

> To scramble the string, we may choose any non-leaf node and swap its two children.

> For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

```
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
```

> We say that "rgeat" is a scrambled string of "great".

> Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

```
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
```

> We say that "rgtae" is a scrambled string of "great".

> Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

* Example 1:

> Input: s1 = "great", s2 = "rgeat"

> Output: true

* Example 2:

> Input: s1 = "abcde", s2 = "caebd"

> Output: false

# 代码

```cpp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.empty() || s2.empty()) return false;
        if (s1 == s2) return true;
        int letter[26] = {0};
        memset(letter, 0, sizeof(int)*26);
        int n = s1.length();
        // 查看各个字母使用频次
        for (int i = 0; i < n; i++){
            letter[s1[i] - 'a']++;
            letter[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++){
            if (letter[i] != 0){
                return false;
            }
        }
        for (int i = 0; i < n; i++){
            // 左边字符对左边字符，右边字符对右边字符，保证 s1 和 s2
            // 的左边-左边，右边-右边子串长度一样
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))){
                return true;
            }
            // 左边字符对右边字符，右边字符对左边字符，保证 s1 和 s2
            // 的左边-右边，右边-左边子串长度一样
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))){
                return true;
            }
        }
        return false;
    }
};
```

# 思路

* 细节实现

* 先判断各个字母使用频次是否相同，再用子串对比，左-左和右-右，左-右和右-左，在子串长度一致下对比
