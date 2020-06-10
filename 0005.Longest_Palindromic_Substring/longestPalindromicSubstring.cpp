#include "../include/tools.h"

class Solution{
public:
    string longestPalindrome_dp(string s){
        if (s.empty() || s.length() == 1) return s;
        int n = s.length();
        int l = 0, subn = 0; // 子串长度 
        vector<vector<bool>> p(n, vector<bool>(n, false)); // p[i][j] 判断字符串从 j 到 i 是否为回文子串
        for (int i = 0; i < n; i++){
            for (int j = i; j >= 0; j--){
                if (s[i] == s[j] && (i - j <= 1 || p[i - 1][j + 1])){
                    // "aa" 或 "axxxa", p[i - 1][j + 1] 即是判断 xxx 是否为回文
                    p[i][j] = true;
                }
                if (p[i][j] && i - j + 1 > subn){ // 找到更长的回文子串
                    l = j; // 左端更新
                    subn = i - j + 1; // 长度更新
                }
            }
        }
        return s.substr(l, subn);
    }

    string longestPalindrome_manacher(string s){
        if (s.empty() || s.length() == 1) return s;
        int m = s.length();
        
        // 扩展字符串为奇数长度，"abba" ==> "#a#b#a#b#"
        string t = "#";
        for (char c: s){
            t += c;
            t += "#";
        }

        int n = 2*m + 1;
        int r = 0;  // 最远右边界
        int center = 0; // 最远右边界对应的中心;
        vector<int> radius(n, 0); // 每个字符的回文半径
        int maxcenter = 0, maxradius = 0; // 最长回文的中心和半径
        for (int i = 0; i < n; i++){
            // 利用对称性找初始半径
            if (i < r){
                int j = 2*center - i; // i,j 关于 center 对称
                radius[i] = min(radius[j], r - i); // 考虑回文长度 i + radius[j] 是否超过 r
            }
            else{
                radius[i] = 1; // 单字符
            }

            // 扩充半径
            while (i - radius[i] >= 0 && i + radius[i] < n && t[i - radius[i]] == t[i + radius[i]]){
                radius[i]++;
            }

            // 更新右边界和对应的中心
            if (i > r){
                r = i + radius[i];
                center = i;
            }

            // 更新最大中心和最大半径
            if (radius[i] > maxradius){
                maxcenter = i;
                maxradius = radius[i];
            }
        }
        int start = (maxcenter - maxradius + 1)/2; // 对应到 s 中的位置;
        int slen = maxradius - 1; // "#"比 s 中字符个数多 1  
        return s.substr(start, slen);
    } 
};

int main(){
    Solution so;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);

    string output1 = so.longestPalindrome_dp(line);
    cout << "动态规划的输出:\n" << output1  << endl;
    string output2 = so.longestPalindrome_manacher(line);
    cout << "马拉车算法输出:\n" << output2  << endl;
    return 0;
}
