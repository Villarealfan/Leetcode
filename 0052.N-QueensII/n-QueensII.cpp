#include "../include/tools.h"

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> col(n, false); // 列上是否有皇后
        vector<bool> diag45(2*n - 1, false); // 45 度对角线 "/" 上是否有皇后
        vector<bool> diag135(2*n - 1, false); // 135 度对角线 "\" 上是否有皇后 
        dfs(res, col, diag45, diag135, n, 0);
        return res;
    }

private:
    void dfs(int& res, vector<bool>& col, vector<bool>& diag45, vector<bool>& diag135, const int n, int i){
        if (i == n){
            // n 行遍历完，说明找到一个可行方案
            res++;
            return;
        }
        for (int j = 0; j < n; j++){
            if (col[j] || diag45[i + j] || diag135[n - 1 - j + i]){
                /*
                 * col[j] = true 表示对应列有皇后
                 * diag45[i + j] = true 表示对应 45 度对角线有皇后
                 * diag135[n - 1 - j + i] = true 表示对应 135 度对角线有皇后
                 *
                 * 45 度对角线编号规则:
                 * (0,0) 第 0 号,(1,0)/(0,1) 第 1 号,...,(n-1,n-1) 2n - 1 号
                 *
                 * 135 度对角线编号规则:
                 * (n-1,0) 第 0 号,(0,0)/(1,1)/.../(n-1,n-1) 第 n - 1 号,...,
                 * (0, n - 1) 第 2n - 1 号
                 */
                continue;
            }
            col[j] = diag45[i + j] = diag135[n - 1 - j + i] = true;
            dfs(res, col, diag45, diag135, n, i + 1); // 遍历下一行 
            col[j] = diag45[i + j] = diag135[n - 1 - j + i] = false;
        }
    }
};

int main(){
    Solution so;

    int n;
    cout << "输入:" << endl;
    cin >> n;

    int output = so.totalNQueens(n);
    cout << "输出:\n" << output << endl;
    return 0;
}
