#include "../include/tools.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowIndex = getRowIndex(matrix, target);
        return find(matrix[rowIndex], target);
    }

    int getRowIndex(vector<vector<int>>& matrix, int target){
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        int l = 0, r = m;
        while (l < r){
            int mid = l + (r - l)/2;
            if (matrix[mid][n] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return l;
    }

    bool find(vector<int>& row, int target){
        int l = 0, r = row.size() - 1;
        while (l <= r){
            int mid = l + (r - l)/2;
            if (row[mid] == target){
                return true;
            }
            else if (row[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return false;
    }
};

int main(){
    Solution so;
    Tools tool;

    int m, n, element, target;
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

    cout << "输入 target:" << endl;
    cin >> target;
    bool res = so.searchMatrix(matrix, target);
    string output = tool.boolToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
