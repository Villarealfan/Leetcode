#include "../include/tools.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int m = s.length(), n = p.length();
        int star = -1; // * 出现在 p 中的最新位置
        int match = 0; // 最远匹配的 s 中的位置
        while (i < m){
            if (j < n && (p[j] == s[i] || p[j] == '?')){
                // 常规匹配上了
                i++;
                j++;
            }
            else if (j < n && p[j] == '*'){
                // 遇到 *
                star = j;
                j++;
                match = i;
            }
            else if (star != -1){
                // p = "*c" 尽可能多的匹配
                j = star + 1;
                match++;
                i = match;
            }
            else{
                // 无论如何都没匹配上
                return false;
            }
        }

        // p = "*c*"，* 可以匹配空
        while (j < n && p[j] == '*'){
            j++;
        }

        return j == n; 
    }
};

int main(){
    Solution so;
    Tools tool;

    string s, p;
    cout << "输入 s:" << endl;
    getline(cin, s);
    cout << "输入 p:" << endl;
    getline(cin, p);

    bool res = so.isMatch(s, p);
    string output = tool.boolToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
