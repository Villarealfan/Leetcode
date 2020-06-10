# [题目](https://leetcode.com/problems/longest-palindromic-substring/)

* Longest Palindromic Substring

> Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

* Example 1:

> **Input**: "babad"

> **Output**: "bab"

> **Note**: "aba" is also a valid answer.

* Example 2:

> **Input**: "cbbd"

> **Output**: "bb"


# 动态规划
## 代码

```cpp
class Solution{
public:
    string longestPalindrome_dp(string s){
        if (s.empty() || s.length() == 1) return s;
        int n = s.length();
        int l = 0, subn = 0; // 子串长度 
        vector<vector<bool>> p(n, vector<bool>(n, false)); // p[i][j] 判断字符串从 j 到 i 是否为回文子串
        for (int i = 0; i < n; i++){
            for (int j = i; j >= 0; j--){
                if (s[i] == s[j] && (i - j <= 1 || p[i - 1][j + 1])){
                    // "aa" 或 "axxxa", p[i - 1][j + 1] 即是判断 xxx 是否为回文
                    p[i][j] = true;
                }
                if (p[i][j] && i - j + 1 > subn){ // 找到更长的回文子串
                    l = j; // 左端更新
                    subn = i - j + 1; // 长度更新
                }
            }
        }
        return s.substr(l, subn);
    }
};
```

## 复杂度
* 时间复杂度: $O(n^2)$

* 空间复杂度: $O(n^2)$

## 思路

**状态转移方程**

$$
dp[i][j] = 1 
\begin{cases}
i=j, \ 单字符\ a\\
i-j=1\ \&\&\ dp[i]=dp[j],\ 双字符\ aa\\
p[i - 1][j + 1]\ \&\&\ dp[i]=dp[j], 即中间是回文子串且两头相同,axxxa
\end{cases}
$$
   
# Manacher 算法

## 代码

```cpp
class Solution{
public:
        if (s.empty() || s.length() == 1) return s;
        int m = s.length();

        // 扩展字符串为奇数长度，"abba" ==> "#a#b#a#b#"
        string t = "#";
        for (char c: s){
            t += c;
            t += "#";
        }

        int n = 2*m + 1;
        int r = 0;  // 最远右边界
        int center = 0; // 最远右边界对应的中心;
        vector<int> radius(n, 0); // 每个字符的回文半径
        int maxcenter = 0, maxradius = 0; // 最长回文的中心和半径
        for (int i = 0; i < n; i++){
            // 利用对称性找初始半径
            if (i < r){
                int j = 2*center - i; // i,j 关于 center 对称
                radius[i] = min(radius[j], r - i); // 考虑回文长度 i + radius[j] 是否超过 r
            }
            else{
                radius[i] = 1; // 单字符
            }

            // 扩充半径
            while (i - radius[i] >= 0 && i + radius[i] < n && t[i - radius[i]] == t[i + radius[i]]){
                radius[i]++;
            }

            // 更新右边界和对应的中心
            if (i > r){
                r = i + radius[i];
                center = i;
            }

            // 更新最大中心和最大半径
            if (radius[i] > maxradius){
                maxcenter = i;
                maxradius = radius[i];
            }
        }
        int start = (maxcenter - maxradius + 1)/2; // 对应到 s 中的位置;
        int slen = maxradius - 1; // "#"比 s 中字符个数多 1
        return s.substr(start, slen);
    }
};
```

## 复杂度
* 时间复杂度: $O(n^2)$
* 空间复杂度: $O(n^2)$

## 思路
* **处理奇偶性**

为了处理奇偶长度的字符串，将字符空档处全部插入#, 如 s = "abc" ==> t = "#a#b#c#" , 无论s长度是奇是偶，t长度为奇（#比原字符始终多一个，n + n +1 = 2n+1，为奇）



* **找 t 中字符在 s 中对应位置**

用数组 radius 记录每个字符的回文半径(包括自身这个字符)，如 
		  
          	       i 0 1 2 3 4 5 6 7 8 9 10
		           t # a # b # a # b # a #
	       radius[i] 1 2 1 4 1 6 1 4 1 2 1
		                   ↑
				 radius[5] = 6, center = 5 
如上所示，由 radius[5] = 6 和 center = 5, 字符串 t = "#a#b#a#b#a#"  的起点位置 startpoint  = center - radius + 1 = 0
		
但这个位置是 t 中的位置，需要找到s中对应的位置，由于 # 和原字符各占一位，因此 startpoint/2（向下取整）为 s 中起点位置。
	
同时，字符串 t 中含的 # 比原字符多一个，而半径有含本身元素，则 radius - 1 为 原字符串的回文长度。
	
因此若找到最大的 radius 和  center ，即可输出 s.substr((center - radius + 1)/2, radius - 1) 。
	


* **利用对称性更新半径**

那么怎么找到 radius[i] 和 center 呢? 这里利用了回文的**对称性**。
	
记录 r 为历史回文能达到的最远右边界，center 为能达到最远右边界的回文的中心。（这里能达到最右不一定是最长的，有可能是新开的一段小回文，如 "abccbadmd" 中 "dmd" 的中心为 m, 最右边界到最后一位，但 "dmd" 不是最长的回文）

则对于不超过这些右边界的点i的计算，可以利用 i 关于 center 对称点 j = 2*center - i 的信息计算。

>- 若 i + radius[j] < r, 说明 j 处回文不够长（对称的i处回文也是等长的），radius[i] = radius[j];

>- 若 i + radius[j] > r, 说明 j 处回文太长超出 r， 超出 r 部分不能保证对称性，因此 radius[i] = r - i;

>- 对于 i > r, 说明 i 根本就没有可以利用信息，则由于其本身是回文 radius[i] = 1;


除了这些以外，**由于右端信息的未知性**， i 处的回文可能更长，

因此 radius[i] 以外的左端元素 t[i - radius[i]] 和右端元素 t[i + radius[i]] 仍需要判断，这里的判断又没有历史信息可以参考，只能逐一判断。



* **更新右边界和中心**



* **更新最大半径和中心**
