# [题目](https://leetcode.com/problems/string-to-integer-atoi/)

* String to Integer (atoi)

> Implement **atoi** which converts a string to an integer.

> The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

> The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

> If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

> If no valid conversion could be performed, a zero value is returned.

> Note:
    
    Only the space character **' '** is considered as
    whitespace character.
    Assume we are dealing with an environment which
    could only store integers within the 32-bit signed
    integer range: $[−2^31,  2^31 − 1]$. If the
    numerical value is out of the range of
    representable values, **INT_MAX** ($2^31 − 1$) 
    or **INT_MIN** ($−2^31$) is returned.


* Example 1:

> Input: "42"

> Output: 42

* Example 2:

> Input: "   -42"

> Output: -42

> Explanation: The first non-whitespace character is **'-'**, which is the minus sign. Then take as many numerical digits as possible, which gets 42.

* Example 3:

> Input: "4193 with words"

> Output: 4193

> Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

* Example 4:

> Input: "words and 987"

> Output: 0

> Explanation: The first non-whitespace character is 'w', which is **not** a numerical digit or a +/- sign. Therefore no valid conversion could be performed.

* Example 5:

> Input: "-91283472332"

> Output: -2147483648

> Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer. Thefore **INT_MIN** ($−2^31$) is returned.

# 代码

```cpp
class Solution{
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        long long res = 0;
        str.erase(0, str.find_first_not_of(" ")); // 去掉开头的空格
        bool isNegative = false;

        // 处理第一位，正负性
        int start = 0;
        if (str[0] == '+'){
            start++;
        }
        if (str[0] == '-'){
            start++;
            isNegative = true;
        }

        // 逐位计算
        int n = str.length();
        for (int i = start; i < n; i++){
            if (str[i] < '0' || str[i] > '9') break;
            res = res*10 + (int)(str[i] - '0');
        }

        // 处理负数
        if (isNegative){
            res = - res;
        }

        // 处理越界
        if (res > INT_MAX){
            return INT_MAX;
        }
        else if (res < INT_MIN){
            return INT_MIN;
        }
        else{
            return res;
        }
    }
};
```

# 复杂度
* 时间复杂度: $O(n)$ , $n$ 为字符串长度
* 空间复杂度: $O(n)$

# 思路
* 边界考虑挺复杂
    * 开头多余空格
    * 正负性
    * 越界 
* C++ string 的 **earse** 函数用法
    * string& erase ( size_t pos = 0, size_t n = npos ) 
      
      删除从 pos 开始的 n 个字符，比如 erase(0,2) 就是删除前两个字符
    * iterator erase ( iterator position );
       
       删除 position 处的一个字符 ( position 是个 string 类型的迭代器)
   * iterator erase ( iterator first, iterator last )
   
       删除从 first 到 last 之间的字符（ first 和 last 都是迭代器）
* C++ string 的 **find\_not\_of** 函数
   
   查找当前 string 与指定的字符串中任意一个字符都不相符的字符，并返回该字符在字符串中第一次出现的位置。
   
* 补充

LeetCode 中有写的两个函数分别是去掉字符串左边的空格，和右边空格

```cpp
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}
```
**trimLeftTrailingSpaces** 函数中的
>  **find_if(input.begin(), input.end(), \[](int ch) {return !isspace(ch); })**
   
从头找到位，找不是空格的，返回的是 **iterator**
      
  > **isspace(ch)** 
      
 判定是否为空格
 
 > **\[] (int ch) {return !isspace(ch);}**  
      
 C++ 中 **lambda** 函数的写法，和 python 中匿名函数类似
      
**trimRightTrailingSpaces** 函数中的

> **find_if(input.rbegin(), input.rend(), \[](int ch) { return !isspace(ch); }).base()**

这里从右边开始找到左边，找不是空格的，返回的是 **reverse_iterator**

> **reverse_iterator.base()**

对 **reverse_iterator** 返回相应的 **iterator**

**reverse_iterator** 和 **iterator** 的对应关系可参考这篇 [博客](https://blog.csdn.net/qq_22194315/article/details/57144854)
