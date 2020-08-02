#include "../include/tools.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        int n = heights.size(), l, res;
        heights.push_back(0);
        stack<int> s;
        for (int i = 0; i <= n; i++){
            while (!s.empty() && heights[i] < heights[s.top()]){
                int h = heights[s.top()];
                s.pop();
                if (!s.empty()){
                    l = s.top();
                }
                else{
                    l = -1;
                }
                int temp = (i - l - 1)*h;
                res = max(res, temp);
            }
            s.push(i);
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
    vector<int> nums = tool.stringToVector(line);
    int output = so.largestRectangleArea(nums);
    cout << "输出:\n" << output << endl;
    return 0;
}
