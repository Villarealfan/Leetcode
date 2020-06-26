# [题目](https://leetcode.com/problems/longest-valid-parentheses/)

* Longest Valid Parentheses

> Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

* Example 1:

> Input: "(()"

> Output: 2

> Explanation: The longest valid parentheses substring is "()"

* Example 2:

> Input: ")()())"

> Output: 4

> Explanation: The longest valid parentheses substring is "()()"


# 代码

```cpp
class Solution{
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '('){
                st.push(i);
            }
            else { // s[i] == ')'
                st.pop();
                
                if (!st.empty()){ // 第 i 位前面的 '(' 不比 ')' 少
                    res = max(res, i - st.top());
                }
                else{
                    // 第 i 位前面的')'比'('多
                    st.push(i);
                }
            }
        }
        return res;
    }
};
```

# 复杂度

* 时间复杂度: $O(n)$
* 空间复杂度: $O(n)$，栈 st 空间为 $O(n)$

# 思路

* 括号问题很适合用栈结构来解决，栈先进后出的特点可以帮助判断最内层的 "()" 的合法性
* 精妙之处在于栈初始化的 -1 ，当 st = "()" 时，$i = 1$ 更新 res 时，1 - （-1） = 2
* 其实每次更新 res 时，均是
       s = "x x ... x (    ) x   ... x"
            0 1 ... j j+1  i i+1 ... n-1
  每次计算时，$j + 1$ 位 (或者是 $i - 1$ 位) 的 ')' 被弹出，此时 st.top() 是 $j = i - 2$ ，即 $res = i - j = i - (i - 2) = 2$