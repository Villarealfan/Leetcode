#include "../include/tools.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return 0;
        int step = 0; // 进过区域数
        int l = 0; // 下一步能到达区域左边界
        int r = 0; // 下一步能到达区域右边界
        int n = nums.size();
        for (int i = 0; i < n - 1; i++){
            if (i + nums[i] >= n - 1) return step + 1; // 如果能直接到，直接完成这一跳
            r = max(r, i + nums[i]);
            // 进入下个区域
            if (i == l){
                step++; 
                l = r; // 为了跳得尽可能远
            }
        }
        return step;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);

    int output = so.jump(nums);
    cout << "输出:\n" << output << endl;
    return 0;
}
