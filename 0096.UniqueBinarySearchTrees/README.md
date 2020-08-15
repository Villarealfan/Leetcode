# [题目](https://leetcode.com/problems/unique-binary-search-trees/)

* Unique Binary Search Trees

> Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

* Example:

> Input: 3

> Output: 5

> Explanation:
```
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

* Constraints:

> 1 <= n <= 19

# 代码
```cpp
class Solution {
public:
    /*
    f(n) = f(0)*f(n - 1) + f(1)*f(n - 2) + ... + f(n - 1)*f(0)
    */
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++){
            for (int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
```

# 思路

> 如果采用中序遍历的话，根结点第 k 个被访问到，则根结点的左子树有 k-1 个点、根结点的右指数有 n-k 个点。k的取值范围为 1 到 n

> 卡特兰数
