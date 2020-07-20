# [题目](https://leetcode.com/problems/edit-distance/)

* Edit Distance

> Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

> You have the following 3 operations permitted on a word:

>- Insert a character
>- Delete a character
>- Replace a character

* Example 1:

> Input: word1 = "horse", word2 = "ros"

> Output: 3

* Explanation: 
```
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

* Example 2:

> Input: word1 = "intention", word2 = "execution"

> Output: 5

> Explanation: 
```
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```

# 代码

```cpp
class Solution {
public:
    int minDistance_dp2dim(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

        // word1 = "xxx", word2 = "", d = word1.length()
        for (int i = 1; i <= m; i++){
            dp[i][0] = i;
        }

        // word1 = "", word2 = "yyy", d = word2.length()
        for (int j = 1; j <= n; j++){
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (word1[i - 1] == word2[j - 1]){
                    // word1 = "xxxxa", word2 = "yyya"
                    // d(word1, word2) = d("xxxx", "yyy")
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    /*
                     * 增: dp[i - 1][j]
                     * 删: dp[i][j - 1]
                     * 改: dp[i - 1][j - 1]
                     * 增删改均需要一步操作
                     * */
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }
        return dp[m][n];
    }

    int minDistance_dp1dim(string word1, string word2){
        int m = word1.size(), n = word2.size();
        if (m < n){
            // 让空间复杂度为 O(min(m,n))
            return minDistance_dp1dim(word2, word1);
        }
        vector<int> dp(n + 1, 0);
        // 第一行处理
        for (int j = 1; j <= n; j++){
            dp[j] = j;
        }
        for (int i = 1; i <= m; i++){
            int pre = dp[0]; // pre 相当于 dp[i - 1][j - 1]，左上角的
            dp[0] = i;
            for (int j = 1; j <= n; j++){
                int temp = dp[j]; // temp 相当于 dp[i - 1][j]，上面的
                if (word1[i - 1] == word2[j - 1]){
                    dp[j] = pre;
                }
                else{
                    dp[j] = min({pre, dp[j - 1], temp}) + 1;
                }
                pre = temp;
            }
        }
        return dp[n];
    }
};
```

# 思路

* 动态规划
    * $dp[i][j]$ 表示 word1[:i] 和 word2[:j] 之间的编辑距离
    * $word1[i - 1] = word2[j - 1]$ 时，$dp[i][j] = dp[i - 1][j - 1]$ 
    * 其他时，$dp[i][j] =  min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) +
      1$, 对应增删改三种情况

* 一维动态规划
    * pre 代替 $dp[i - 1][j - 1]$
    * temp 代替 $dp[i - 1][j]$
