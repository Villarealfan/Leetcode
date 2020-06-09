# [题目](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

* Longest Substring Without Repeating Characters 

> Given a string, find the length of the longest substring without repeating characters.

* Example 1:

> Input: "abcabcbb"

> Output: 3 

> Explanation: The answer is "abc", with the length of 3. 

* Example 2:

> Input: "bbbbb"

> Output: 1

> Explanation: The answer is "b", with the length of 1.

* Example 3:

> Input: "pwwkew"

> Output: 3

> Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a **substring**, "pwke" is a **subsequence** and not a substring.

# 代码
```cpp
class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int index[256];
        memset(index, -1, sizeof(int)*256);
        int res = 0, l = 0, n = s.length();
        for (int r = 0; r < n; r++){
            l = max(l, index[s[r]] + 1);
            res = max(res, r - l + 1);
            index[s[r]] = r;
        }
        return res;
    }
};
```

# 复杂度
* 时间复杂度: O(n)
* 空间复杂度: O(n)

# 思路
* 静态数组 index 存所有的字符位置，也可以用 unordered_map 存，静态数组更快一些
* **memset()** 函数是将 index 初始化为全部为 -1 的数组，表示所有字符均未出现
* l, r 分别为符合要求的子串左右两端，右端 r 不断向右，左端 l 取 max 的原因是：

        如果 l 一直为 index[s[r]] + 1，当  index[s[r]] + 1 < r 时，

		例：
		-----------------------------------------------------------------
				0 1 2 3
				a b b a
		            r
				l
		-----------------------------------------------------------------
		在 r = 2 时，s[r] = 'b', index['b'] = 1
		l = index[s[r]] + 1 = index['b'] + 1 = 1 + 1 = 2
		-----------------------------------------------------------------
				0 1 2 3
				a b b a
				      r
				    l
		-----------------------------------------------------------------
		r = 3 时，s[r] = 'a', index['a'] = 0
		l = index[s[r]] + 1 = index['a'] + 1 = 0 + 1 = 1
		得到子串为 'bba'， 其中 'b' 重复出现了。
* res 记录结果，r - l + 1 是每次子串的长度，不断更新即可
     

