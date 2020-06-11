# [题目](https://leetcode.com/problems/zigzag-conversion/)

* ZigZag Conversion

> The string "**PAYPALISHIRING**" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

>     P   A   H   N 
    A P L S I I G
    Y   I   R
> And then read line by line: "**PAHNAPLSIIGYIR**"

> Write the code that will take a string and make this conversion given a number of rows:

>     string convert(string s, int numRows);

* Example 1:

> **Input**: s = "PAYPALISHIRING", numRows = 3

> **Output**: "PAHNAPLSIIGYIR"


* Example 2:

> **Input**: s = "PAYPALISHIRING", numRows = 4

> **Output**: "PINALSIGYAHRPI"

> **Explanation**:

>      P     I    N
>    A   L S  I G
>    Y A   H R
>    P     I



# 代码

```cpp
class Solution{
public:
    string convert(string s, int numRows){
        int n = s.length();
        if (numRows <= 1 || numRows >= n) return s;
        string res;
        int diff = 2*(numRows - 1);
        for (int i = 0; i < numRows; i++){
            for (int j = i; j < n; j += diff){
                res +=  s[j];
                if (i > 0 && i < numRows - 1){
                    int k = j + diff - 2*i;
                    if (k < n){
                        res += s[k];
                    }
                }
            }
        }
        return res;
    }
};
```

# 复杂度
* 时间复杂度: $O(n)$
* 空间复杂度: $O(n)$

# 思路

* 找规律

将各个脚标排列如下

		0       8           16
		1     7 9        15 17
		2   6   10    14    18
		3 5     11 13
		4       12 
找规律:

- 第一行：
    - 0 (+8) 8 (+8) 16 ==> +8, 8 = 2*(numRows - 1)
- 中间的：
   - **1** (+6) 7 | 9 (+6)  15 | 17 ==> +6, 6 = 8 - 2***1** 
   - **2** (+4) 6 | 10 (+4) 14 | 18 ==> +4, 4 = 8 - 2***2**
   - **3** (+2) 5 | 11 (+2) 13 ==> +4, 2 = 8 - 2***3**
 
- 最第一行：
    - 4 (+8) 12 ==> +8, 8 = 2*(numRows - 1)
    
即，第一行第二行相差 $2*(numRows - 1)$ , 其他 $i$ 行需要**每次多加一个**，相差为 $2*(numRows - 1) - 2i$，如第 **1** 行 1 后面的 7 相差为 6， $6  = 6 = 8 - 2*1$
