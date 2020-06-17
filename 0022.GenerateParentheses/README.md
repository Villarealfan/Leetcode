# [题目](https://leetcode.com/problems/generate-parentheses/)

* Generate Parentheses

> Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

> For example, given n = 3, a solution set is:

    [
     "((()))",
     "(()())",
     "(())()",
     "()(())",
     "()()()"
    ]


# 代码

```cpp
class Solution{
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string item;
        dfs(res, item, n, n);
        return res;
    }

    void dfs(vector<string>& res, string item, int l, int r){
        if (l > r) return;
        if (l == 0 && r == 0){
            res.push_back(item);
            return;
        }
        if (l > 0) dfs(res, item + "(", l - 1, r);
        if (r > 0) dfs(res, item + ")", l, r - 1);
    }
};
```

# 复杂度
* 时间复杂度: 
* 空间复杂度: 

# 思路
* DFS
* $l$ 表示左括号剩余次数，$r$ 表示右括号剩余次数 


