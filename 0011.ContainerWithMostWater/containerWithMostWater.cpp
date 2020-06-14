#include "../include/tools.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0;
        while (l < r){
            int hl = height[l], hr = height[r];
            int area = min(hl, hr)*(r - l);
            if (area > maxArea){
                maxArea = area;
            }
            if (hl < hr){
                l++;
            }
            else{
                r--;
            }
        }
        return maxArea;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> height = tool.stringToVector(line);
    int output = so.maxArea(height);
    cout << "输出:\n" << output  << endl;
    return 0;
}
