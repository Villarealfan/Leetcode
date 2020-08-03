# include "../include/tools.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> left(n, 0); // 从左到右，出现连续 1 的第一个坐标
        vector<int> right(n, n); // 从右到左，出现连续 1 的最后一个坐标
        vector<int> high(n, 0); // 从上到下的高度
        int res = 0;
        for (int i = 0; i < m; i++){
            int l = 0, r = n;
            // 更新 left[j] 和 high[j]
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == '1'){
                    high[j]++;
                    left[j] = max(left[j], l);
                }
                else{
                    high[j] = 0;
                    left[j] = 0;
                    l = j + 1;
                }
            }
            // 更新 right[j]
            for (int j = n - 1; j >= 0; j--){
                if (matrix[i][j] == '1'){
                    right[j] = min(right[j], r);
                }
                else{
                    right[j] = n;
                    r = j;
                }
            }

            // 计算 res
            for (int j = 0; j < n; j++){
                res = max(res, (right[j] - left[j])*high[j]);
            }
        }
        return res;
    }
};

int main(){
    Solution so;
    int m, n;
    cout << "输入矩阵维度:" << endl;
    cin >> m >> n;
    char c;
    vector<vector<char> > matrix(m, vector<char>(n, '0'));
    cout << "输入矩阵:" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> c;
            matrix[i][j] = c;
        }
    }
    int output = so.maximalRectangle(matrix);
    cout << "输出:\n" << output << endl;
    return 0;
}
