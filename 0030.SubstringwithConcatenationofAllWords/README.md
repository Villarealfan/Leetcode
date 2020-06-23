# [题目](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)

* Substring with Concatenation of All Words

> You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

* Example 1:
> Input: 
    s = "barfoothefoobarman", 
    words = ["foo","bar"]
> Output: [0,9]
> Explanation: 
    Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
    The output order does not matter, returning [9,0] is fine too.

* Example 2:

> Input: 
     s = "wordgoodgoodgoodbestword", 
     words = ["word","good","best","word"]
> Output: []


# 代码

```cpp
class Solution{
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return {};
        unordered_map<string, int> maps, temp;
        int n = words.size(), m = words[0].size();
        int endIndex = s.length() - m*n; // 遍历的最右端

        // 统计每个单词出现次数
        for (string& word: words) maps[word]++;

        // 滑动窗口逐一匹配
        for (int i = 0; i <= endIndex; i++){
            int k = 0; // 匹配的单词个数
            while (k < n){
                string subs = s.substr(i + k*m, m); // 截取第 k 个子串
                if (maps.find(subs) != maps.end()){
                    // 子串是 maps 中的单词
                    temp[subs]++;
                    if (temp[subs] > maps[subs]){
                        // 使用次数比 maps 中还多
                        break;
                    }
                }
                else{
                    // 不在 maps 中
                    break;
                }
                k++;
            }
            //  n 个单词全部匹配上
            if (k == n){
                res.push_back(i);
            }
            temp.clear(); // 每次匹配完清空
        }
        return res;
};
```

# 复杂度

* 时间复杂度: $O(ln)$, $l$ 最外层循环，$n$ 为 匹配的单词数，16-31 行的循环内，unordered_map 判断是否存在是 $O(1)$ 的。
* 空间复杂度: $O(m+n)$， $m$ 是 $subs$ 的空间， $n$ 是 maps 和 temp 的空间

# 思路

* 题目中最关键的就是所有单词长度相同，但是可能出现重复的单词，因此需要抓住这两个特点
* 滑动窗口，窗口大小为 $m$ ，不断用窗口内的子串判断
* Hashmap ,判断滑动窗口产生的子串是否在 maps 中出现的时间复杂度为 $O(1)$
* 两种情况：
  * 当窗口中的子串不是 maps 中的，说明该子串没用；
  * 当窗口中的子串出现次数多于 maps 中的，说明该子串用超了;