#include "../include/tools.h"


class Solution {
public:
    int uniquePaths_dp1(int m, int n) {
        int dp[100][100];
        for (int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++){
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths_dp2(int m, int n){
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }

    int uniquePaths_math(int m, int n){
        int x = m + n - 2;
        int k = min(m,n) - 1;
        long a = 1, b = 1;
        while (k >= 1){
            a *= x;
            b *= k;
            x--;
            k--;
        }
        return (int)(a/b);
    }
};

int main(){
    Solution so;
    int m, n;
    cout << "输入 m, n:" << endl;
    cin >> m >> n;

    int output_dp1 = so.uniquePaths_dp1(m, n);
    cout << "输出:\n" << "一维动态规划:" << output_dp1 << endl;
    
    int output_dp2 = so.uniquePaths_dp2(m, n);
    cout << "输出:\n" << "二维动态规划:" << output_dp2 << endl;
    
    int output_math = so.uniquePaths_math(m,n);
    cout << "组合数: " << output_math << endl;

    return 0;
}
