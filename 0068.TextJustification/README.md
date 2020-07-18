# [题目] (https://leetcode.com/problems/text-justification/)

* Text Justification

> Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

> You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

> Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

> For the last line of text, it should be left justified and no extra space is inserted between words.

* Note:

>- A word is defined as a character sequence consisting of non-space characters only.

>- Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.

>- The input array words contains at least one word.

* Example 1:

> Input:
```
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
```

> Output:
```
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```

* Example 2:

> Input:
```
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
```

> Output:
```
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
```

> Explanation: 
```
Note that the last line is "shall be    " instead of "shall     be",because the last line must be left-justified instead of fully-justified.

Note that the second line is also left-justified becase it contains only one word.
```

* Example 3:

> Input:
```
words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
```

* Output:
```
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
```

# 代码

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int start = 0, n = words.size();
        while (start < n){
            int total = words[start].length(); //  添加字符的总长度
            int end = start + 1; // 该行使用最后一个单词的位置

            // 不断添加空格和新单词
            while (end < n){
                int temp = words[end].length() + 1; // + 1 是有一个空格
                if (total + temp > maxWidth){
                    break;
                }
                total += temp;
                end++;
            }

            string cur = ""; // 这行的字符串
            cur += words[start]; // 先把 start 这个放进去
            int diff = end - start - 1; // 能放置单词个数 - 1，可以认为单词间空挡个数

            if (end == n || diff == 0){
                // 最后一行或者只能放这一个单词时

                // 先把这些单词全拼接到 cur 后面，注意加空格
                for (int i = start + 1; i < end; i++){
                    cur += " ";
                    cur += words[i];
                }

                // 长度不够后面加空格
                for (int i = cur.length(); i < maxWidth; i++){
                    cur += " ";
                }
            }
            else{
                // maxWidth - total 是总空格个数, diff 是有多少个空挡
                int mimimum = (maxWidth - total)/diff + 1; //  单词间空挡最少需要的空格个数
                int residual = (maxWidth - total)%diff; // 每个空挡分 mimimum 个空格后，剩余的空格数

                for (int i = start + 1; i < end; i++){
                    //  多余的 residual 个空格在前面逐一分配
                    for (int k = 0; k < mimimum; k++){
                        // 先把最少的空格拼接上去
                        cur += " ";
                    }

                    // 多余的空格逐一使用
                    if (residual > 0){
                        cur += " ";
                        residual--;
                    }
                    cur += words[i]; // 拼接单词
                }
            }
            res.push_back(cur);
            start = end;
        }
        return res;
    }
};
```

# 思路

* 细节实现
