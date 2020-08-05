# include "../include/tools.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.empty() || s2.empty()) return false;
        if (s1 == s2) return true;
        int letter[26] = {0};
        memset(letter, 0, sizeof(int)*26);
        int n = s1.length();
        // 查看各个字母使用频次
        for (int i = 0; i < n; i++){
            letter[s1[i] - 'a']++;
            letter[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++){
            if (letter[i] != 0){
                return false;
            }
        }
        for (int i = 0; i < n; i++){
            // 左边字符对左边字符，右边字符对右边字符，保证 s1 和 s2
            // 的左边-左边，右边-右边子串长度一样
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))){
                return true;
            }
            // 左边字符对右边字符，右边字符对左边字符，保证 s1 和 s2
            // 的左边-右边，右边-左边子串长度一样
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution so;
    Tools tool;
    string s1, s2;
    cout << "输入 s1:" << endl;
    getline(cin, s1); 
    cout << "输入 s2:" << endl;
    getline(cin, s2);
    bool res = so.isScramble(s1, s2);
    string output = tool.boolToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
