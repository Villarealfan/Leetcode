# [题目](https://leetcode.com/problems/valid-number/)

* Valid Number

> Validate if a given string can be interpreted as a decimal number.

> Some examples:
```
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
```

* Note:

> It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

>- Numbers 0-9

>- Exponent - "e"

>- Positive/negative sign - "+"/"-"

>- Decimal point - "."

> Of course, the context of these characters also matters in the input.

* Update (2015-02-10):
> The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

# 代码
```cpp
class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        // 去掉头尾空格
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);

        int n = s.length();
        bool point = false; // 是否出现小数点
        bool e = false; // 是否出现 e
        bool number = false; // 是否为数字
        bool number_after_e = true; // e 后面是否为数字
        for (int i = 0; i < n; i++){
            if (s[i] >= '0' && s[i] <= '9'){
                number = true;
                number_after_e = true;
            }
            else if (s[i] == '.'){
                // 小数点不能在 e 后，也不能出现两次
                if (e || point){
                    return false;
                }
                point = true;
            }
            else if (s[i] == 'e'){
                // e 不能出现两次，e 前必须有数字
                if (e || !number){
                    return false;
                }
                e = true;
                number_after_e = false;
            }
            else if (s[i] == '+' || s[i] == '-'){
                // ± 号只能出现在第一位或者 e 后一位
                if (i != 0 && s[i - 1] != 'e'){
                    return false;
                }
            }
            else{
                // 出现其他符号
                return false;
            }
        }
        return number && number_after_e;
    }
};
```

# 思路

* 细节实现，需要注意 e 前和 e 后都得是数字