# [题目](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

* Letter Combinations of a Phone Number

> Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

> A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png" width="80%">

* Example:

> Input: "23"

> Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

* Note:

> Although the above answer is in lexicographical order, your answer could be in any order you want.

# 代码

```cpp
class Solution{
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        string item;
        string maps[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = digits.length();
        dfs(res, item, digits, maps, 0, n);
        return res;
    }

    void dfs(vector<string>& res, string item, string& digits, string maps[], int i, int& n){
        if (i == n){
            res.push_back(item);
            return;
        }

        int index = (int)(digits[i] - '0');
        string s = maps[index];
        for (char c: s){
            item.push_back(c);
            dfs(res, item, digits, maps, i + 1, n);
            item.pop_back();
        }
   }
};
```

# 复杂度
* 时间复杂度: $O(4^n)$, $n$ 为字符串长度
* 空间复杂度: $O(n)$

# 思路
* DFS  
  
* maps 记录各个数字与字符串的对应情况，0 和 1 都对应 ""。

