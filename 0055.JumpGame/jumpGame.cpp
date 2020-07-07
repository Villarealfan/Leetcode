#include "../include/tools.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int r = nums[0];
        for (int i = 1; i < n; i++){
            if (r >= i && r <= i + nums[i]){
                // 进入下一个区域[i, i+ nums[i]]
                if (i + nums[i] >= n - 1){
                    // 下个区域直接能到
                    return true;
                }
                r = i + nums[i];
            }
        }
        return r >= n - 1; // 能否到最后一格

    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);
    bool res = so.canJump(nums);
    string output = tool.boolToString(res);
    cout << "输出:\n" << output << endl;
    return 0;
}
