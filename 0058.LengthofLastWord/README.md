# [题目](https://leetcode.com/problems/length-of-last-word/)

*  Length of Last Word

> Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

> If the last word does not exist, return 0.

* Note: 

> A word is defined as a maximal substring consisting of non-space characters only.

* Example:

> Input: "Hello World"

> Output: 5

# 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, tail = s.length() - 1;
        // "hello  word    " , tail 到 d 字符处
        while (tail >= 0 && s[tail] == ' '){
            tail--;
        }
        // 计算 word 的长度
        while (tail >= 0 && s[tail] != ' '){
            len++;
            tail--;
        }
        return len;
    }
};
```

# 思路

* 细节实现