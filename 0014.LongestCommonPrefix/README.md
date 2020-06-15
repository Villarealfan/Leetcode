# [题目](https://leetcode.com/problems/longest-common-prefix/)

* Longest Common Prefix

> Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

* Example 1:

> Input: ["flower","flow","flight"]

> Output: "fl"

* Example 2:

> Input: ["dog","racecar","car"]

> Output: ""

> Explanation: There is no common prefix among the input strings.

* Note:

> All given inputs are in lowercase letters a-z.


# 代码

```cpp
class Solution{
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int n = strs.size(), m = strs[0].length();
        string res;
        for (int j = 0; j < m; j++){
            char c = strs[0][j];
            for (int i = 1; i < n; i++){
                if (j >= strs[i].length() || strs[i][j] != c){
                    return res;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};
```

# 复杂度
* 时间复杂度: $O(mn)$
* 空间复杂度: $O(m)$

# 思路
* 暴力求解，逐个和第一个字符串比较，超过其长度或者字符对不上直接返回

