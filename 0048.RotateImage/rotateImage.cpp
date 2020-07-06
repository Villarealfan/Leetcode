#include "../include/tools.h"

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; i++){
            for (int j = i; j < n - 1 - i; j++){
                /*
                 * 规律:
                 * matrix[a][b] <-- matrix[c][d]
                 * a = d, b + c = n - 1
                 */
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
        return;
    }
};

int main(){
    Solution so;
    Tools tool;

    int n;
    cout << "输入方阵大小:" << endl;
    cin >> n;
    
    // 生成 n*n 的方阵
    vector<vector<int> > matrix = tool.getRandomMatrix(n);

    cout << "输入矩阵为:" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    so.rotate(matrix);
    cout << "输出矩阵为:" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
