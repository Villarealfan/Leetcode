# [题目](https://leetcode.com/problems/plus-one/)

* Plus One

> Given a **non-empty** array of digits representing a non-negative integer, increment one to the integer.

> The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

> You may assume the integer does not contain any leading zero, except the number 0 itself.

**Example 1:**

```
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
```

**Example 2:**

```
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
```

# 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return digits;
        int n = digits.size() - 1;
        for (int i = n; i >= 0; i--){
            if (digits[i] < 9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0;
            }
        }
        // 进位问题
        if (digits[0] == 0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
```

# 思路

* 细节实现，注意进位问题