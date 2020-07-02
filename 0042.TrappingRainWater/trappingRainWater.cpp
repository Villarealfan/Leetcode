#include "../include/tools.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int hlmax = 0, hrmax = 0; // 左右高度最小值
        int res = 0;
        while (l < r){
            if (height[l] < height[r]){
                hlmax = max(hlmax, height[l]);
                res += hlmax - height[l];
                l++;
            }
            else{
                hrmax = max(hrmax, height[r]);
                res += hrmax - height[r];
                r--;
            }
        }
        return res;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> height = tool.stringToVector(line);

    int output = so.trap(height);
    cout << "输出:\n" << output << endl;
    return 0;
}
