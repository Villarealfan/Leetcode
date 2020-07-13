#include "../include/tools.h"

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, grid[0][0]);
        // 第一行
        for (int j = 1; j < n; j++){
            dp[j] = dp[j - 1] + grid[0][j];
        }
        // 其他行
        for (int i = 1; i < m; i++){
            dp[0] += grid[i][0]; // 第一列只能从上面来
            for (int j = 1; j < n; j++){
                // 取左边和上面来的最小的
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<string> rows = tool.split(line, ";");
    vector<vector<int> > grid;
    for (string& row: rows){
        vector<int> item = tool.stringToVector(row);
        grid.push_back(item);
    }

    int output = so.minPathSum(grid);
    cout << "输出:\n" << output << endl;
    return 0;
}
