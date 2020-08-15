# include "../include/tools.h"

class Solution {
public:
    /*
    f(n) = f(0)*f(n - 1) + f(1)*f(n - 2) + ... + f(n - 1)*f(0)
    */
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++){
            for (int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

int main(){
    Solution so;
    int n;
    cout << "输入:" << endl;
    cin >> n;
    int output = so.numTrees(n);
    cout << "输出:\n" << output << endl;
    return 0;
}
