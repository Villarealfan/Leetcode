# [题目] (https://leetcode.com/problems/climbing-stairs/)

* Climbing Stairs

> You are climbing a stair case. It takes n steps to reach to the top.

> Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

* Example 1:

> Input: 2

> Output: 2

> Explanation: 
```
There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

* Example 2:

> Input: 3

> Output: 3

* Explanation: 
```
There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

* Constraints:

>- 1 <= n <= 45

# 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        long first = 1, second = 1;
        while (n > 1){
            long temp = first + second;
            first = second;
            second = temp;
            n--;
        }
        return (int)second;
    }
};
```

# 思路

* 斐波那契数列
* 注意 int 越界问题