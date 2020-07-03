# [题目](https://leetcode.com/problems/multiply-strings/)

* Multiply Strings

> Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

* Example 1:

> Input: num1 = "2", num2 = "3"

> Output: "6"

* Example 2:

> Input: num1 = "123", num2 = "456"

> Output: "56088"

* Note:

>- The length of both num1 and num2 is < 110.

>- Both num1 and num2 contain only digits 0-9.

>- Both num1 and num2 do not contain any leading zero, except the number 0 itself.

>- You must not use any built-in BigInteger library or convert the inputs to integer directly.


# 代码

```cpp
class Solution{
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty() || num1 == "0" || num2 == "0") return "0";
        int m = num1.length(), n = num2.length();
        string res(m + n, '0');
        for (int i = m - 1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--){
                int sum = (num1[i] - '0')*(num2[j] - '0') + (res[i + j + 1] - '0');
                res[i + j + 1] = sum%10 + '0';
                res[i + j] += sum/10;
            }
        }
        res.erase(0, res.find_first_not_of('0'));
        return res;
    }
};
```

# 复杂度

* 时间复杂度: $O(mn)$
* 空间复杂度: $O(m + n)$

# 思路

* num1 * num2 最多为 $m + n$ 位， $m$ 位的 $num1$ 最多为 $\underbrace{99...99}\_\text{m}$ ， $n$ 位的 $num2$ 最多为 $\underbrace{99...99}\_\text{n}$ 

$$
\underbrace{99...99}_\text{m} \times \underbrace{99...99}_\text{n} = \underbrace{99...99}_\text{m} \times (\underbrace{10...00}_\text{n} - 1) \leq \underbrace{99...99}_\text{m} \times \underbrace{10...00}_\text{n} = \underbrace{\underbrace{99...99}_\text{m}\underbrace{0...00}_\text{n}}_\text{m + n}
$$

* 注意做乘法时候，倒着乘， i + j + 1位是较低位，i + j 是高位
```
	     num1   1 2 3
	   * num2   4 5 6
	    ---------------------- *6
	              1 8
	            1 2
                  0 6
	    ---------------------- *5
	            1 5
                  1 0
		0 5
	    ----------------------- *4
	          1 2
		0 8                          
	   +  0 4                       
	---------------------------
	  res 0 5 6 0 8 8
```
* 如果最终 res 最高位为 0，需要去掉 
	        
