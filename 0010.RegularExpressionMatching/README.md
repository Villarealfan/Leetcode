# [题目](https://leetcode.com/problems/regular-expression-matching/)

* Regular Expression Matching

> Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
     
        '.' Matches any single character.
     
        '*' Matches zero or more of the preceding element.
        
> The matching should cover the entire input string (not partial).

* Note:

> s could be **empty** and contains only lowercase letters a-z.

> p could be **empty** and contains only lowercase letters a-z, and characters like . or *.

* Example 1:

> Input: s = "aa", p = "a"

> Output: false

> Explanation: "a" does not match the entire string "aa".


* Example 2:

> Input: s = "aa", p = "a*"

> Output: true

> Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

* Example 3:

> Input: s = "ab", p = ".*"

> Output: true

> Explanation: ".\*" means "zero or more (*) of any character (.)".

* Example 4:

> Input: s = "aab", p = "c\*a\*b"

> Output: true
> Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

* Example 5:

> Input: s = "mississippi", p = "mis\*is\*p\*."

> Output: false

# 代码

```cpp
class Solution{
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; j++){
            if (p[j - 1] == '*'){
                if (j == 1){
                    dp[0][1] = true;
                }
                else{
                    dp[0][j] = dp[0][j - 2];
                }
            }
        }

        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*'){
                    if (j == 1){
                        dp[i][1] = true;
                    }
                    else{
                        if (p[j - 2] != '.' && p[j - 2] != s[i - 1]){
                            dp[i][j] = dp[i][j - 2];
                        }
                        else{
                            dp[i][j] = (dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2]);
                        }
                    }
                }
            }
        }
        return dp[m][n];
    }
};
```

# 复杂度
* 时间复杂度: $O(mn)$
* 空间复杂度: $O(mn)$

# 思路
* 动态规划
* dp[i][j] 记录 s[0-i] 和 p[0-j] 是否匹配
	* 若 p[j - 1] 直接匹配上 s[i - 1] ，即 p[j - 1] == '.' 或 p[j - 1] == s[i - 1] , 例如:
		* s = "xxxayyy", p = "zzzawww" (s 中的 a 与 p 中的 a 匹配上了)
		* s = "xxxayyy", p = "zzz.www" (s 中的 a 与 p 中的 . 匹配上了)
	
	这两种情况下，都是需要看前面的 s = "xxx" 与 p = "zzz" 的匹配情况，即:
	
	$dp[i][j] = dp[i - 1][j -1]$
	
	* 若 p[j - 1] 是通过 * 匹配上 s[i - 1] ，即 p[j - 1] == '*' 时
		* 若 p[j - 2] 能匹配上 s[i - 1]，即 p[j - 2] == '.' 或 p[j - 2] == s[i - 1]，例如：
			* p[j - 2] == '.' 时		
			
			> s = "xxxayyy", p = "zz.\*www" (s 中的 a 与 p 中的 .* 匹配上了)，此时需要看前面的 s = "xxxa" 与 p = "zz" 的匹配情况
	
	$dp[i][j] = dp[i][j - 2]$
			
		    * p[j - 2] == s[i - 1] 但 s[i - 1] != s[i - 2] 时
		    
		    > s = "xxxayyy", p = "zza\*www" (s 中的 a 与 p 中的 a* 匹配上了)，此时需要看前面的 s = "xxxa" 与 p = "zza" 的匹配情况 
	
	$dp[i][j] = dp[i][j  - 1]$
			
		 * p[j - 2] == s[i - 1] 且 s[i - 1] == s[i - 2] 时
		    
		    > s = "xxaayyy", p = "zza\*www" (s 中的 aa 与 p 中的 a* 匹配上了)， 此时需要看前面的 s = "xxa" 与 p = "zza\*" 的匹配情况 (即 p 中 a* 前可能还有 s 前面的能匹配上， 对应 a* 可以匹配多个)
	
	$dp[i][j] = dp[i - 1][j]$
	
		* 若 p[j - 2] 不能匹配上 s[i - 1]， 即 p[j - 2] != '.' 或 p[j - 2] != s[i - 1] ，例如
			* s = "xxxayyy", p = "zzb\*www" (p 中的 b* 对应 s 中的 a)， 此时需要看前面的 s = "xxxa" 与 p = "zz" 的匹配情况，即:
	
	$dp[i][j] = dp[i][j - 2]$
	
* 边界情况
      * s = "", p = "", $dp[0][0] = true$
      * s = "", p = "*" , $dp[0][1] = true$
      * s = "", p = "abcd*" ，需要看 s = "" 与 p = "abc" 的匹配情况，即 $dp[0][j] = dp[0][j - 2]$
