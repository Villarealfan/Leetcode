#include "../include/tools.h"

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (dfs(board, i, j, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char> >& board, int i, int j, string word, int index){
        if (index >= word.length()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (board[i][j] == word[index]){
            index++;
            char c = board[i][j];
            board[i][j] = '#';
            bool res = dfs(board, i + 1, j, word, index) || dfs(board, i - 1, j, word, index) || dfs(board, i, j + 1, word, index) || dfs(board, i, j - 1, word, index);
            board[i][j] = c;
            return res;
        }
        return false;
    }
};

int main(){
    Solution so;
    Tools tool;

    string boardStr,word;
    vector<vector<char> > board;
    cout << "输入 board: " << endl;
    getline(cin, boardStr);
    for (string lineStr: tool.split(boardStr, ";")){
        vector<char> line;
        for (char c: lineStr){
            line.push_back(c);
        }
        board.push_back(line);
    }
    cout << "输入 word:" << endl;
    getline(cin, word);
    bool res = so.exist(board, word);
    string output = tool.boolToString(res);
    cout << "输出:" << output << endl;
    return 0;
}
