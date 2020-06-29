#include "../include/tools.h"


class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        if (board.empty()) return;
        solve(board);
    }

private:
    bool solve(vector<vector<char> >& board){
        // dfs
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == '.'){
                    for (char c = '1'; c <= '9'; c++){
                        if (isValid(board, i, j, c)){
                            board[i][j] = c;
                            if (solve(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool isValid(vector<vector<char> >& board, int row, int col, char cc){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                // 行是否有 cc 
                if (board[row][i*3 + j] == cc){
                    return false;
                }

                // 列是否有 cc
                if (board[i*3 + j][col]){
                    return false;
                }

                // 框里是否有 cc
                if (board[3*(row/3) + i][3*(col/3) + j]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    vector<vector<char> > board;
    for (int i = 0; i < 9; i++){
        vector<char> row;
        getline(cin, line);
        for (int j = 0; j < 9; j++){
            row.push_back(line[i]);
        }
        board.push_back(row);
    }

    so.solveSudoku(board);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}
