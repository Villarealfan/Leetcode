#include "../include/tools.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; j++){
            if (p[j - 1] == '*'){
                if (j == 1){
                    dp[0][1] = true;
                }
                else{
                    dp[0][j] = dp[0][j - 2];
                }
            }
        }

        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*'){
                    if (j == 1){
                        dp[i][1] = true;
                    }
                    else{
                        if (p[j - 2] != '.' && p[j - 2] != s[i - 1]){
                            dp[i][j] = dp[i][j - 2];
                        }
                        else{
                            dp[i][j] = (dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2]);
                        }
                    }
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution so;
    Tools tool;

    string s, p;
    cout << "输入字符串 s:" << endl;
    getline(cin, s);
    cout << "输入字符串 p:" << endl;
    getline(cin, p);
    bool res = so.isMatch(s, p);

    string output = tool.boolToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
