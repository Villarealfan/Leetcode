# include "../include/tools.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) return false;
        if (m < n) return isInterleave(s2, s1, s3);
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int j = 1; j <= n; j++){
            dp[j] = (dp[j - 1] && s2[j - 1] == s3[j - 1]);
        }
        for (int i = 1; i <= m; i++){
            dp[0] = (dp[0] && s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= n; j++){
                dp[j] = ((dp[j - 1] && s2[j -1] == s3[i + j - 1])||(dp[j] && s1[i - 1] == s3[i + j - 1]));
            }
        }
        return dp[n];
    }
};

int main(){
    Solution so;
    Tools tool;
    string s1, s2, s3;
    cout << "输入 s1:" << endl;
    getline(cin, s1);
    cout << "输入 s2:" << endl;
    getline(cin, s2);
    cout << "输入 s3:" << endl;
    getline(cin, s3);
    bool res = so.isInterleave(s1, s2, s3);
    string output = tool.boolToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
