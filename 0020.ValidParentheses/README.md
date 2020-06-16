# [题目](https://leetcode.com/problems/valid-parentheses/)

* Valid Parentheses

> Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

> An input string is valid if:

>- Open brackets must be closed by the same type of brackets.
>- Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

* Example 1:

> Input: "()"

> Output: true

* Example 2:

> Input: "()[]{}"

> Output: true

* Example 3:

> Input: "(]"
> Output: false

* Example 4:

> Input: "([)]"
> Output: false

* Example 5:

> Input: "{[]}"

> Output: true


# 代码

```cpp
class Solution{
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if (st.empty()) return false;
                if (s[i] == ')' && st.top() != '(') return false;
                if (s[i] == ']' && st.top() != '[') return false;
                if (s[i] == '}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
```

# 复杂度
* 时间复杂度: $O(n)$
* 空间复杂度: $O(n)$

# 思路
* 栈：先进后出，后进先出
* 不合法 false 情况
	*  只有左边括号，没有右边括号
	*  刚进去的 '(' 和遍历的 ')' 对不上
	*  刚进去的 '[' 和遍历的 ']' 对不上
	*  刚进去的 '{' 和遍历的 '}' 对不上
	*  最后一个是左括号，即 '(' 或 '[' 或 '{'

