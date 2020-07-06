#include "../include/tools.h"

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int rowbegin = 0, rowend = n - 1; // 行上边界和下边界
        int colbegin = 0, colend = n - 1; // 列左边界和右边界
        int count = 1;
        while (rowbegin <= rowend && colbegin <= colend){
            // 从左往右走
            for (int j = colbegin; j <= colend; j++){
                matrix[rowbegin][j] = count++;
            }
            // 向下走一格
            rowbegin++;

            // 从上往下走
            for (int i = rowbegin; i <= rowend; i++){
                matrix[i][colend] = count++; 
            }
            // 向左走一格
            colend--;

            //  避免上下越界
            if (rowbegin <= rowend){
                // 从右往左走
                for (int j = colend; j >= colbegin; j--){
                    matrix[rowend][j] = count++;
                }
                // 向上走一格
                rowend--;
            }

            // 避免左右越界
            if (colbegin <= colend){
                // 从下往上走
                for (int i = rowend; i >= rowbegin; i--){
                    matrix[i][colbegin] = count++;
                }
                // 向右走一格
                colbegin++;
            }
        }
        return matrix;
    }
};

int main(){
    Solution so;
    Tools tool;

    int n;
    string line;
    cout << "输入:" << endl;
    cin >> n;
    vector<vector<int> > matrix = so.generateMatrix(n);
    for (vector<int>& rowV: matrix){
        line = tool.vectorToString(rowV);
        cout << line << endl;
    }
    return 0;
}
