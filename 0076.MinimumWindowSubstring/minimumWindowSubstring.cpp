#include "../include/tools.h"

class Solution {
public:
    string minWindow(string s, string t) {
       int m = s.length(), n = t.length();
       if (m < n) return "";
       int cnt[128]; // 每个字符出现的次数
       memset(cnt, 0, sizeof(int)*128); // 初始都出现 0 次

       for (char c:t) cnt[c]++; // 统计 t 中字符出现次数
       int minStart = 0, minLen = INT_MAX; // 最小窗口
       int match = 0; // 字符使用次数
       for (int i = 0, j = 0; i < m; i++){
           cnt[s[i]]--;
           if (cnt[s[i]] >= 0){
               // 字符还没用完
               match++;
           }
           while (match == n){
               // 最小窗口更新
               if (i - j + 1 < minLen){
                   minLen = i - j + 1;
                   minStart = j;
               }
               if (cnt[s[j]] >= 0){
                   match--;
               }
               cnt[s[j]]++;
               j++;
           }
       }

       if (minLen == INT_MAX){
           return "";
       }
       else{
           return s.substr(minStart, minLen);
       }
    }
};

int main(){
    Solution so;
    
    string s, t;
    cout << "输入 s:" << s << endl;
    getline(cin, s);
    cout << "输入 t:" << t << endl;
    getline(cin, t);
    string output = so.minWindow(s, t);
    cout << "输出:" << output << endl;
    return 0;
}
