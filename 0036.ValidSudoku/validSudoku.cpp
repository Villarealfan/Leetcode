#include "../include/tools.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        bool row[9][9] = {false}; // row[x][y]: x 行是否使用数字 y + 1
        bool col[9][9] = {false}; // col[x][y]: x 列是否使用数字 y + 1
        bool box[9][9] = {false}; // box[x][y]: 第 x 个方格里是否使用 y + 1
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                int val = (int)(board[i][j] - '1');
                int boxindex = (i/3)*3 + j/3; // 一行一行的数，0-1-2;3-4-5;6-7-8
                if (row[i][val] || col[j][val] || box[boxindex][val]){
                    return false;
                }
                row[i][val] = col[j][val] = box[boxindex][val] = true;
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

    bool res = so.isValidSudoku(board);
    string output = tool.boolToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
