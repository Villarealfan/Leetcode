# [题目](https://leetcode.com/problems/restore-ip-addresses/)

* Restore IP Addresses

> Given a string containing only digits, restore it by returning all possible valid IP address combinations.

> A valid IP address consists of exactly four integers (each integer is between 0 and 255) separated by single points.

* Example:

> Input: "25525511135"

> Output: ["255.255.11.135", "255.255.111.35"]

# 代码

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string item = "";
        dfs(res, item, s, 0, 0);
        return res;
    }

private:
    void dfs(vector<string>& res, string item, string s, int start, int count){
        if (count > 4) return;
        if (count == 4 && start == s.length()){
            res.push_back(item);
            return;
        }
        for (int i = 0; i < 3; i++){
            if (start + i >= s.length()) return;
            if (s[start] == '0' && i > 0) return;
            int temp = 0;
            for (int k = start; k <= start + i; k++){
                temp = 10*temp + (s[k] - '0');
            }
            if (temp >= 256) return;

            string ss = s.substr(start, i + 1);
            if (count < 3){
                ss = ss + ".";
            }
            dfs(res, item + ss, s, start + i + 1, count + 1);
        }
    }
};
```

# 思路

* DFS
