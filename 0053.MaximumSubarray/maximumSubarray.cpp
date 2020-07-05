#include "../include/tools.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum = 0; // 子串求和项
        int maxSum = INT_MIN; // 取 INT_MIN 防止全负数 nums 
        for (int& num: nums){
            sum += num;
            // 更新最大值
            if (sum > maxSum){
                maxSum = sum;
            }
            // 前面子串和为负，重新记录子串
            if (sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);
    int output = so.maxSubArray(nums);
    cout << "输出:" << output << endl;
    return 0;
}
