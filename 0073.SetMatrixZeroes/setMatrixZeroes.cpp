#include "../include/tools.h"

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool flag = false; // 标记第一列是否有 0 
        // 若 matrix[i][j] = 0, 将这行和这列的首元素标记为 0
        for (int i = 0; i < m; i++){
            if (matrix[i][0] == 0) flag = true;
            for (int j = 1; j < n; j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // 处理标记，若行列首元素为 0，则该行该列全变为 0
        for (int i = m - 1; i >= 0; i--){
            for (int j = n - 1; j > 0; j--){
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if (flag) matrix[i][0] = 0; // 第一列为 0 时，这列全为 0
        }
        return;
    }
};

int main(){
    Solution so;

    int m, n, element;
    cout << "输入矩阵规模:" << endl;
    cin >> m >> n;
    vector<vector<int> > matrix(m, vector<int>(n, 0));
    cout << "输入矩阵元素:" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> element;
            matrix[i][j] = element;
        }
    }

    so.setZeroes(matrix);
    cout << "输出矩阵为:" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
