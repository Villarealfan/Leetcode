#include "../include/tools.h"

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> queens(n, 0);
        dfs(res, queens, 0, n);
        return res;
    }

private:
    void dfs(vector<vector<string> >& res, vector<int>& queens, int row, const int n){
        if (row == n){
            addQueens(res, queens, n);
            return;
        }
        for (int col = 0; col < n; col++){
            queens[row] = col; // 第 row 行的皇后放在第 col 列
            if (isValid(queens, row)){
                // 一行行的放，放成功了就下一行
                dfs(res, queens, row + 1, n);
            }
        }
    }

private:
    void addQueens(vector<vector<string> >& res, vector<int>& queens, const int n){
        vector<string> solution;
        for (int i = 0; i < n; i++){
            string rowStr;
            // 第 i 行第 j 列是皇后，用 'Q' 代替，否则用 '.' 代替
            for (int j = 0; j < n; j++){
                if (queens[i] == j){
                    rowStr.push_back('Q');
                }
                else{
                    rowStr.push_back('.');
                }
            }
            solution.push_back(rowStr);
        }
        res.push_back(solution);
    }

private:
    bool isValid(vector<int>& queens, int row){
        // 由于是一行行的放，因此考虑合法性时，只需考虑与之前行的皇后，放置的列是否相同，以及是否在一条对角线上
        for (int i = 0; i < row; i++){
            if (queens[i] == queens[row] || abs(queens[i] - queens[row]) == abs(i - row)){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution so;

    int n;
    cout << "输入:" << endl;
    cin >> n;
    vector<vector<string> > sols = so.solveNQueens(n);
    cout << "输出:" << endl;
    for (auto& sol: sols){
        for (string& row: sol){
            cout << row << "," << endl;
        }
        cout << endl;
    }
    return 0;
}
