#include "../include/tools.h"

class Solution {
public:
    int minDistance_dp2dim(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

        // word1 = "xxx", word2 = "", d = word1.length()
        for (int i = 1; i <= m; i++){
            dp[i][0] = i;
        }

        // word1 = "", word2 = "yyy", d = word2.length()
        for (int j = 1; j <= n; j++){
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (word1[i - 1] == word2[j - 1]){
                    // word1 = "xxxxa", word2 = "yyya"
                    // d(word1, word2) = d("xxxx", "yyy") 
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    /*
                     * 增: dp[i - 1][j]
                     * 删: dp[i][j - 1]
                     * 改: dp[i - 1][j - 1]
                     * 增删改均需要一步操作
                     * */
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }
        return dp[m][n];
    }

    int minDistance_dp1dim(string word1, string word2){
        int m = word1.size(), n = word2.size();
        if (m < n){
            // 让空间复杂度为 O(min(m,n))
            return minDistance_dp1dim(word2, word1);
        }
        vector<int> dp(n + 1, 0);
        // 第一行处理
        for (int j = 1; j <= n; j++){
            dp[j] = j;
        }
        for (int i = 1; i <= m; i++){
            int pre = dp[0]; // pre 相当于 dp[i - 1][j - 1]，左上角的
            dp[0] = i;
            for (int j = 1; j <= n; j++){
                int temp = dp[j]; // temp 相当于 dp[i - 1][j]，上面的
                if (word1[i - 1] == word2[j - 1]){
                    dp[j] = pre;
                }
                else{
                    dp[j] = min({pre, dp[j - 1], temp}) + 1;
                }
                pre = temp;
            }
        }
        return dp[n];
    }
};

int main(){
    Solution so;
    string word1, word2;

    cout << "输入 word1:" << endl;
    getline(cin, word1);

    cout << "输入 word2:" << endl;
    getline(cin, word2);

    int output_2dim = so.minDistance_dp2dim(word1, word2);
    cout << " 二维动态规划的输出:\n" << output_2dim << endl;
    int output_1dim = so.minDistance_dp1dim(word1, word2);
    cout << " 一维动态规划的输出:\n" << output_1dim << endl;
    return 0;
}
