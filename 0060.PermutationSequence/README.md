#[题目](https://leetcode.com/problems/permutation-sequence/)

* Permutation Sequence

> The set [1,2,3,...,n] contains a total of n! unique permutations.

> By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

```
"123"
"132"
"213"
"231"
"312"
"321"
```

> Given n and k, return the kth permutation sequence.

* Note:

> Given n will be between 1 and 9 inclusive.

> Given k will be between 1 and n! inclusive.

* Example 1:

> Input: n = 3, k = 3

> Output: "213"

* Example 2:

> Input: n = 4, k = 9

> Output: "2314"

# 代码

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "1"; // "123...n"

        int fac[9]; // fac[i]: (i+1)!
        fac[0] = 1;

        for (int i = 1; i < n; i++){
            fac[i] = fac[i - 1]*(i + 1);
            res.push_back(i +'1');
        }

        int index = 0;
        int head; //
        k--; // 从 0 计数
        while (n >= 2){ 
            head = k/fac[n - 2]; // 正确排序的首个数字对应位置
            k -= head*fac[n - 2]; // 放好首个数字后的 1 排序

            // 将首个数字放好
            if (head > 0){
                char temp = res[head + index];
                // 其他数字按原顺序后移
                for (int i = head + index - 1; i >= index; i--){
                    res[i + 1] = res[i];
                }
                res[index] = temp;
            }

            index++;
            n--;
        }
        return res;
    }
};
```

# 思路

* 找规律，比如 n = 4, k = 16，最暴力想法就是，直接枚举 $4! = 24$ 种结果，找到对应结果，即 "3241"

```
1234
1243
1324
1342
1423
1432

2134
2143
2314
2341
2413
2431

3124
3142
3214
3241
3412
3421

4123
4132
4213
4231
4312
4321
```

优化一下，一个数字一个数字的确定：

## 先确定第一位数字

由于 3 开头的前面一个有 12 个(1 开头的 $3! = 6$ 个，2 开头的也是 $3! = 6$ 个)，$12 < k = 16 < 18$，这样就确定了首位数字为 "3"，k - 12 = 16 - 12 = 4，下一步需要找以 3 开头里边的第 4 个字符串，即在 "124" 这三个数字的全排列中找到第 4 个。

## 接着确定第二位数字

由于 "31" 开头的有 2 个，"32" 开头的也有2个，因此第二位数字为 "2" ，则下一步需要在 "14" 的全排列中找到第 2 个。

## 确定第三位数字

由于 "1" 开头的有 1 个，"4" 开头的也有 1 个，因此第三位数字为 "4"，同时最后一位必然是 "1"。