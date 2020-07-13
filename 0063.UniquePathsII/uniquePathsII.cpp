#include "../include/tools.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int dp[100];
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // 处理第一行
        dp[0] = 1 - obstacleGrid[0][0];
        for (int j = 1; j < n; j++){
            dp[j] = dp[j - 1]*(1 - obstacleGrid[0][j]);
        }
        // 处理其他行
        for (int i = 1; i < m; i++){
            dp[0] *= (1 - obstacleGrid[i][0]); // 第一列只和上面的有关
            for (int j = 1; j < n; j++){
                // 后面的列需要考虑左面和上面元素
                dp[j] = (dp[j] + dp[j - 1])*(1 - obstacleGrid[i][j]);
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
    vector<vector<int> > obstacleGrid;
    for (string& row: rows){
        vector<int> item = tool.stringToVector(row);
        obstacleGrid.push_back(item);
    }

    int output = so.uniquePathsWithObstacles(obstacleGrid);
    cout << "输出:\n" << output << endl;
    return 0;
}
