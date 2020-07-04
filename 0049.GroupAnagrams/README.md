# [题目](https://leetcode.com/problems/group-anagrams/)

* Group Anagrams

> Given an array of strings, group anagrams together.

* Example:

> Input: ["eat", "tea", "tan", "ate", "nat", "bat"],

> Output:

    [
     ["ate","eat","tea"],
     ["nat","tan"],
     ["bat"]
    ]

* Note:

>- All inputs will be in lowercase.

>- The order of your output does not matter.

# 代码

```cpp
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > maps;
        for (string& str: strs){
            string key = str;
            sort(key.begin(), key.end());
            maps[key].push_back(str);
        }
        for (auto& item: maps){
            res.push_back(item.second);
        }
        return res;
    }
};
```

# 思路

* Hash Table
* 相同组的字符串按字典序排后，当做 key